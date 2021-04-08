/*++

	disk.cpp, 2019/1/14
	(c) Qiansi Corporation, All rights reserved.

--*/
#include <iostream>
#include <time.h>
#include "disk.h"

using namespace std;

void Disk::errlog(char* file, int row, int err)
{
	FILE* stream = fopen("errno.ini", "ab");
	if(!stream)
		return;

	time_t timep = time(NULL);
	tm* ptm = localtime(&timep);
	
	fprintf(stream, "%s\r\nrow: %d\r\nerr: %d\r\n%s\r\n", file, row, err, strerror(err));
	fprintf(stream, "%d/%02d/%02d,%02d:%02d:%02d\r\n\r\n",
		ptm->tm_year + 1900, ptm->tm_mon + 1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec);
	fclose(stream);
}

BOOL Disk::fillsector(__int64 sector, unsigned char val, int num)
{
#ifndef __C__
#else
	HANDLE hdev = CreateFile(disk, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL, OPEN_EXISTING, 0, NULL);
	if(hdev == INVALID_HANDLE_VALUE)
	{
		int err = GetLastError();
		__err__;
		return FALSE;
	}
	
	LARGE_INTEGER li;
	li.QuadPart = sector << 9;
	DWORD dw = SetFilePointer(hdev, li.LowPart, &li.HighPart, FILE_BEGIN);

	char buf[512];
	BOOL flag;

	memset(buf, val, sizeof buf);
	for(int i = 0; i < num; i++)
	{
		flag = WriteFile(hdev, buf, 512, &li.LowPart, NULL);
		if(!flag)
		{
			int err = GetLastError();
			__err__;
			break;
		}
	}

	CloseHandle(hdev);
	return flag;
#endif
}

__int64 Disk::finddata(__int64 offset, unsigned char* udata)
{
#ifndef __C__
	char disk[] = "\\\\.\\PHYSICALDRIVE1";
	disk[17] = diskno;

	FILE* stream = fopen(disk, "rb");
	if(!stream)
	{
		int err = errno;
		__err__;
		return FALSE;
	}
	_fseeki64(stream, offset, SEEK_SET);

	__int64 pos = 0;
	while(!feof(stream))
	{
		unsigned char buf[1024 * 64];
		int i, j, num;

		num = fread(buf, 1, sizeof(buf), stream);
		pos += num;

		for(i = 0; i <= num - *(int*)&udata[0]; i++)
		{
			for(j = 0; j < *(int*)&udata[0]; j++)
			{
				if(buf[i + j] != udata[4 + j])
					break;
			}
			if(j >= *(int*)&udata[0])
				break;
		}
		if(i <= num - *(int*)&udata[0])
			return pos - num + i;
	}
	return -1;
#else
	HANDLE hdev = CreateFile(disk, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, 
		NULL, OPEN_EXISTING, 0, NULL);
	if(hdev == INVALID_HANDLE_VALUE)
	{
		int err = GetLastError();
		__err__;
		return -1;
	}

	LARGE_INTEGER li;
	li.QuadPart = offset >> 9 << 9;
	SetFilePointerEx(hdev, li, &li, FILE_BEGIN);

	unsigned char buf[512 * 32];
	BOOL flag, status = FALSE;
	__int64 pos = 0;
	int num, i = offset & 0x1ff, j = 0;

	do
	{
		flag = ReadFile(hdev, buf, sizeof buf, (DWORD*)&num, NULL);
		if(!flag)
		{
			int err = GetLastError();
			__err__;
			break;
		}

		for(; i < num; i++)
		{
			for(; j < *(int*)&udata[0]; j++)
			{
				if(i + j >= num)
					goto next;

				if(udata[4 + j] != buf[i + j])
					break;
			}
			if(j == *(int*)&udata[0])
				break;
			j = 0;
		}

		if(i < num)
		{
			status = TRUE;
			pos += i;
			break;
		}

		pos += num;
		i = 0;
		continue;

	next:
		pos += i >> 9 << 9;
		i %= 512;
		li.QuadPart = (offset >> 9 << 9) + pos;
		SetFilePointerEx(hdev, li, NULL, FILE_BEGIN);
	} while(flag);

	CloseHandle(hdev);	
	return status ? pos : -1;
#endif
}

int Disk::findsign(__int64 sector)
{
#ifndef __C__
	char disk[] = "\\\\.\\PHYSICALDRIVE1";
	FILE* stream = fopen(disk, "rb");
	if(!stream)
	{
		int err = errno;
		__err__;
		return false;
	}
	_fseeki64(stream, offset, SEEK_SET);

	int num = 0;
	while(!feof(stream))
	{
		unsigned char udata[512 * 32];
		int m, n;

		n = fread(udata, 1, sizeof(udata), stream);
		for(m = 510; m < n; m += 512)
		{
			if(*(unsigned short*)&udata[m] == 0xaa55)
			{
				printf("sector: %lld, %d\r\n\r\n", offset + m / 512, num + 1);
				num++;
			}
		}
		offset += n / 512;
	}
	fclose(stream);
	return num;
#else
	HANDLE hdev = CreateFile(disk, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, 
		NULL, OPEN_EXISTING, 0, NULL);
	if(hdev == INVALID_HANDLE_VALUE)
	{
		int err = GetLastError();
		__err__;
		return FALSE;
	}

	LARGE_INTEGER li;
	li.QuadPart = sector << 9;
	SetFilePointerEx(hdev, li, &li, FILE_BEGIN);

	unsigned char buf[512 * 32];
	int num, m, n = 0;
	BOOL flag;

	do
	{
		flag = ReadFile(hdev, buf, sizeof buf, (DWORD*)&num, NULL);
		if(!flag)
		{
			int err = GetLastError();
			__err__;
			break;
		}

		for(m = 510; m < num; m += 512)
		{
			if(*(unsigned short*)&buf[m] == 0xaa55)
			{
				n++;
				printf("  %#10llx,(%d)\n", li.QuadPart + m, n);
			}
		}
		li.QuadPart += num;
	} while(flag);

	CloseHandle(hdev);	
	return n;
#endif
}

BOOL Disk::readsector(__int64 sector, unsigned char* udata)
{
#ifndef __C__
	char disk[] = "\\\\.\\PHYSICALDRIVE1";
	disk[17] = diskno;

	FILE* stream = fopen(disk, "rb");
	if(!stream)
	{
		int err = errno;
		__err__;
		return FALSE;
	}
	_fseeki64(stream, sector, SEEK_SET);

	int num = fread(udata, 512, 1, stream);
	if(!num)
	{
		int err = errno;
		__err__;
	}
	fclose(stream);
	return num != 0;
#else
	HANDLE hdev = CreateFile(disk, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, 
		NULL, OPEN_EXISTING, 0, NULL);
	if(hdev == INVALID_HANDLE_VALUE)
	{
		int err = GetLastError();
		__err__;
		return FALSE;
	}

	LARGE_INTEGER li;
	li.QuadPart = sector << 9;
	SetFilePointer(hdev, li.LowPart, &li.HighPart, FILE_BEGIN);

	BOOL flag = ReadFile(hdev, udata, 512, &li.LowPart, NULL);
	if(!flag)
	{
		int err = GetLastError();
		__err__;
	}
	CloseHandle(hdev);
	return flag;
#endif
}

BOOL Disk::writesector(__int64 sector, unsigned char* udata)
{
#ifndef  __C__
#else
	HANDLE hdev = CreateFile(disk, GENERIC_WRITE, FILE_SHARE_WRITE,
		NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if(hdev == INVALID_HANDLE_VALUE)
	{
		int err = GetLastError();
		__err__;
		return FALSE;
	}

	LARGE_INTEGER li;
	li.QuadPart = sector << 9;
	SetFilePointerEx(hdev, li, &li, FILE_BEGIN);

	BOOL flag = WriteFile(hdev, udata, 512, &li.LowPart, NULL);
	if(!flag)
	{
		int err = GetLastError();
		__err__;
	}
	CloseHandle(hdev);
	return flag;
#endif
}

BOOL Disk::setsign(__int64 sector, unsigned short val)
{
#ifndef __C__
	char disk[] = "\\\\.\\PHYSICALDRIVE1";
	disk[17] = diskno;

	FILE* stream = fopen(disk, "rb+");
	if(!stream)
	{
		int err = errno;
		__err__;
		return false;
	}
	int seek = _fseeki64(stream, sector, SEEK_SET);

	char udata[512];
	int num;

	// 读取原扇区内容
	num = fread(udata, 512, 1, stream);
	if(!num)
	{
		int err = errno;
		__err__;
		goto end;
	}

	// 设定签名值
	*(unsigned short*)&udata[510] = val;
	seek = _fseeki64(stream, sector, SEEK_SET);

	// 写入扇区
	num = fwrite(udata, 512, 1, stream);
	if(!num)
	{
		int err = errno;
		__err__;
		goto end;
	}
end:
	fclose(stream);
	return num != 0;
#else
	HANDLE hdev = CreateFile(disk, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL, OPEN_EXISTING, 0, NULL);
	if(hdev == (HANDLE)-1)
	{
		int err = GetLastError();
		__err__;
		return FALSE;
	}
	
	//DWORD dwCount;
	//if(!DeviceIoControl(hdev, FSCTL_LOCK_VOLUME, NULL, 0, NULL, 0, &dwCount, NULL))
	//{
	//	int err = GetLastError();
	//	__err__;
	//}

	LARGE_INTEGER li;
	li.QuadPart = sector << 9;
	DWORD dw = SetFilePointer(hdev, li.LowPart, &li.HighPart, FILE_BEGIN);

	char buf[512];
	BOOL flag;

	flag = ReadFile(hdev, buf, 512, &li.LowPart, NULL);
	if(!flag)
	{
		int err = GetLastError();
		__err__;
		goto end;
	}
	
	*(unsigned short*)&buf[510] = val;
	li.QuadPart = sector << 9;
	dw = SetFilePointer(hdev, li.LowPart, &li.HighPart, FILE_BEGIN);

	flag = WriteFile(hdev, buf, 512, &li.LowPart, NULL);
	if(!flag)
	{
		int err = GetLastError();
		__err__;
	}
end:
	//DeviceIoControl(hdev, FSCTL_UNLOCK_VOLUME, NULL, 0, NULL, 0, &dwCount, NULL);
	CloseHandle(hdev);
	return flag;
#endif
}