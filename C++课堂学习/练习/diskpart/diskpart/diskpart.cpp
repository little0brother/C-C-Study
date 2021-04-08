/*++

	disk.cpp, 2019/3/16
	(c) Qiansi Corporation, All rights reserved.

--*/
//#include <windows.h>
#include <time.h>
#include <iostream>
#include "diskpart.h"
using namespace std;

#if !defined(min) || !defined(max)
#define min(a, b)	((a) < (b) ? (a) : (b))
#define max(a, b)	((a) > (b) ? (a) : (b))
#endif

#ifndef __help
#define __help(x)			\
if(!_strcmpi(ptr, "/?"))	\
{							\
	printf("%s\n\n", x);	\
	return;					\
}
#endif

void Disk::clear(char* ptr)
{
	__help("cleardata");
	for(int n = 0; n < SECTOR_SIZE; n++)
		pdata[n] = 0;
	printf("+OK\n\n");
}

unsigned int Disk::crc32(unsigned char* pv, int len)
{
	static unsigned int crc32table[256];
	static bool flag = true;
	unsigned int ret = 0xffffffff;

	if(flag)
	{
		for(int i = 0; i < 256; i++)
		{
			unsigned int crc = i;
			for(int j = 0; j < 8; j++)
			{
				if(crc & 1)
					crc = (crc >> 1) ^ 0xEDB88320;
				else
					crc = crc >> 1;
			}
			crc32table[i] = crc;
		}
		flag = false;
	}

	for(int i = 0; i < len; i++)
	{
		ret = crc32table[((ret & 0xFF) ^ pv[i])] ^ (ret >> 8);
	}

	ret = ~ret;
	return ret;
}

void Disk::crc32(char* ptr)
{
	// 显示命令格式
	__help("crc32 start size");

	FILE* stream = fopen(driver, "rb+");
	if(!stream)
	{
		__err__;
		return;
	}
	setvbuf(stream, NULL, _IOFBF, SECTOR_SIZE);

	long long start = _atoi64(ptr);
	int size = atoi(nextparam(ptr));

	_fseeki64(stream, start / SECTOR_SIZE * SECTOR_SIZE, SEEK_SET);
	int sectorsnum = (int)((start + size) / SECTOR_SIZE - start / SECTOR_SIZE + 1);

	unsigned char* buf = new unsigned char[SECTOR_SIZE * sectorsnum];
	unsigned int crc;

	int num = fread(buf, SECTOR_SIZE, sectorsnum, stream);
	if(!num)
	{
		int err = errno;
		__err__;
	}
	else
	{
		crc = crc32(&buf[start & 0x1ff], size);

		unsigned char* ch = (unsigned char*)&crc;
		printf("crc32 = %02x %02x %02x %02x\n\n", ch[0], ch[1], ch[2], ch[3]);
	}
	fclose(stream);
}

int Disk::errlog(const char* filename, long line)
{
	char* ptr = strerror(errno);
	printf("%s(%d)\ndescribe: %s(%d)\n\n", filename, line, ptr, errno);
	return 0;
}

void Disk::fill(char* ptr)
{
	// 命令格式
	__help("fill sectorno val(hex) num");

	// 提取填充值
	__int64 sectorno = _atoi64(ptr);
	ptr = nextparam(ptr);
	char val[4];
	str2hex(ptr, val, 1);

	// 填充扇区数目
	ptr = nextparam(ptr);
	__int64 num = _atoi64(ptr);

	// 打开磁盘并定位
	FILE* stream = fopen(driver, "rb+");
	if(!stream)
	{
		__err__;
		return;
	}
	setvbuf(stream, NULL, _IOFBF, SECTOR_SIZE * 1024);
	_fseeki64(stream, sectorno * SECTOR_SIZE, SEEK_SET);

	// 设置填充缓存
	char* temp = new char[SECTOR_SIZE * 1024];
	memset(temp, val[0], SECTOR_SIZE * 1024);

	// 记录已填充扇区数目
	__int64 total = 0;
	clock_t ck = clock();

	// 分“多次”快速填充
	for(int n = 0; n < num / 1024; n++)
	{
		int m = fwrite(temp, SECTOR_SIZE, 1024, stream);
		if(!m)
		{
			__err__;
			goto end;
		}
		total += m;
	}

	// 最后一次填充
	if(num % 1024 > 0)
	{
		setvbuf(stream, NULL, _IOFBF, SECTOR_SIZE);
		int m = fwrite(temp, SECTOR_SIZE, num % 1024, stream);
		if(!m)
		{
			__err__;
			goto end;
		}
		total += m;
	}

end:
	// 完成状况
	ck = clock() - ck;
	printf("%lld sectors has finished(%ds).\n\n", total, ck / 1000);

	// 关闭磁盘流句柄
	fclose(stream);
}

void Disk::find(char* ptr)
{
	// 命令格式
	__help("find sectorno data(hex)");

	// 提取查找数据
	__int64 start = _atoi64(ptr);
	ptr = nextparam(ptr);
	char buf[256];
	*(int*)&buf[0] = str2hex(ptr, &buf[4], 256);

	FILE* stream = fopen(driver, "rb+");
	if(!stream)
	{
		__err__;
		return;
	}
	_fseeki64(stream, start / SECTOR_SIZE * SECTOR_SIZE, SEEK_SET);
	setvbuf(stream, NULL, _IOFBF, SECTOR_SIZE * 1024);

	char* pv = new char[SECTOR_SIZE * 1024];
	int i = start & 0x1ff, j = 0, n = 0;
	__int64 pos = start / SECTOR_SIZE * SECTOR_SIZE;
	bool fast = true;
	clock_t ck = clock();

	// 循环读取1024扇区
	while(true)
	{
		int num = fread(pv, SECTOR_SIZE, 1024, stream);
		if(!num)
		{
			int err = errno;
			if(fast)
			{
				setvbuf(stream, NULL, _IOFBF, SECTOR_SIZE);
				fast = false;
				continue;
			}
			ck = clock() - ck;
			printf("%lld sectors finished(%ds).\n\n", 
				_ftelli64(stream) / SECTOR_SIZE, ck / 1000);
			break;
		}

		num *= SECTOR_SIZE;
		for(; i < num; i++)
		{
			for(; j < *(int*)&buf[0]; j++)
			{
				if(i + j >= num)
					goto next;
				if(buf[4 + j] != pv[i + j])
					break;
			}
			// 成功，输出偏移地址
			if(j == *(int*)&buf[0])
				printf("%-4d%#10llx\n", ++n, pos + i);

			// 查找串“指标”归位
			j = 0;
		}

		// 查找失败，重新读取数据块
		pos += i / SECTOR_SIZE * SECTOR_SIZE;
		i = 0;
		continue;

	next:
		// 部分匹配，读数据后继续比较
		pos += i / SECTOR_SIZE * SECTOR_SIZE;
		i &= 0x1ff;
		_fseeki64(stream, pos, SEEK_SET);
	}

	delete[] pv;
	fclose(stream);
}

void Disk::findsign(char* ptr)
{
	// 命令格式
	__help("findsign sectorno");

	FILE* stream = fopen(driver, "rb+");
	if(!stream)
	{
		__err__;
		return;
	}
	//__int64 num = (__int64)GetDriveGeometry();

	char* buf = new char[SECTOR_SIZE * 1024];
	__int64 sector = _atoi64(ptr);
	int n = 0;
	bool fast = true;
	clock_t ck = clock();

	setvbuf(stream, NULL, _IOFBF, SECTOR_SIZE * 1024);
	_fseeki64(stream, sector * SECTOR_SIZE, SEEK_SET);

	// 每次快速读取1024个扇区
	while(true)
	{
		int num = fread(buf, SECTOR_SIZE, 1024, stream);
		if(!num)
		{
			if(fast)
			{
				setvbuf(stream, NULL, _IOFBF, SECTOR_SIZE);
				fast = false;
				continue;
			}
			break;
		}

		for(int k = 0; k < num; k++)
		{
			if(*(unsigned short*)&buf[(k + 1) * SECTOR_SIZE - 2] == 0xaa55)
				printf("%-4d%#10lld\n", ++n, sector + k);
		}
		sector += num;
	}
	ck = clock() - ck;
	printf("%lld sectors finished(%ds).\n\n", _ftelli64(stream) / SECTOR_SIZE, ck / 1000);

	delete[] buf;
	fclose(stream);
}

//__int64 Disk::GetDriveGeometry()
//{
//	HANDLE hdev = CreateFileA(driver, 0, FILE_SHARE_READ | FILE_SHARE_WRITE,
//		NULL, OPEN_EXISTING, 0, NULL);
//	if(hdev == INVALID_HANDLE_VALUE)
//	{
//		int err = GetLastError();
//		return 0;
//	}
//
//	ULONGLONG disksize = 0;
//	DISK_GEOMETRY dg;
//	DWORD dw;
//
//	if(DeviceIoControl(hdev, IOCTL_DISK_GET_DRIVE_GEOMETRY,
//		NULL, 0, &dg, sizeof dg, &dw, NULL))
//	{
//		disksize = dg.Cylinders.QuadPart * dg.TracksPerCylinder * dg.SectorsPerTrack;
//	}
//
//	CloseHandle(hdev);
//	return disksize;
//}

void Disk::load(char* filename)
{
	char* ptr = filename;
	__help("load filename");

	FILE* stream = fopen(filename, "rb");
	if(!stream)
	{
		__err__;
		return;
	}

	int num = fread(pdata, SECTOR_SIZE, 1, stream);
	num ? printf("+OK\n\n") : (int)__err__;
	fclose(stream);
}

char* Disk::nextparam(char* ptr)
{
	while(*ptr && *ptr != ' ') 
		ptr++;
	*ptr++ = '\0';
	while(*ptr && *ptr == ' ') 
		ptr++;
	return ptr;
}

void Disk::replace(char* ptr)
{
	__help("replace addr(hex) val(hex)");
	char* addr, udata[SECTOR_SIZE];
	int num, start;

	// 确定扇区地址，替换值
	addr = ptr;
	ptr = nextparam(ptr);
	num = str2hex(ptr, udata, SECTOR_SIZE);

	// 替换缓存区的值
	sscanf(addr, "%x", &start);
	for(int i = 0; i < num; i++)
	{
		if(start + i < SECTOR_SIZE)
			pdata[start + i] = udata[i];
	}
	printf("+OK\n\n");
}

void Disk::read(char* ptr)
{
	// 命令格式
	__help("read sectorno");

	FILE* stream = fopen(driver, "rb");
	if(!stream)
	{
		__err__;
		return;
	}

	setvbuf(stream, NULL, _IOFBF, SECTOR_SIZE);
	__int64 sector = _atoi64(ptr);
	_fseeki64(stream, sector * SECTOR_SIZE, SEEK_SET);

	int num = fread(pdata, SECTOR_SIZE, 1, stream);
	num ? shows(pdata) : __err__;
	fclose(stream);
}

void Disk::save(char* filename)
{
	char* ptr = filename;
	__help("save filename");

	FILE* stream = fopen(filename, "wb");
	if(!stream)
	{
		__err__;
		return;
	}

	int num = fwrite(pdata, SECTOR_SIZE, 1, stream);
	num ? printf("+OK\n\n") : __err__;
	fclose(stream);
}

void Disk::setdisk(char* ptr)
{
	__help("setdisk diskno");
	driver[17] = *ptr;
	printf("+OK\n\n");
}

void Disk::setsign(char* ptr)
{
	// 命令格式
	__help("setsign sectorno");

	FILE* stream = fopen(driver, "rb+");
	if(!stream)
	{
		__err__;
		return;
	}

	setvbuf(stream, NULL, _IOFBF, SECTOR_SIZE);
	__int64 sectorno = _atoi64(ptr);
	_fseeki64(stream, sectorno * SECTOR_SIZE, SEEK_SET);

	// 读取扇区、修改签名值
	int num = fread(pdata, SECTOR_SIZE, 1, stream);
	if(!num)
	{
		__err__;
		goto end;
	}
	*(unsigned short*)&pdata[SECTOR_SIZE - 2] = 0xaa55;

	// 写入扇区
	_fseeki64(stream, sectorno * SECTOR_SIZE, SEEK_SET);
	num = fwrite(pdata, SECTOR_SIZE, 1, stream);
	if(!num)
	{
		__err__;
		goto end;
	}
	printf("+OK\n\n");

end:
	fclose(stream);
}

int Disk::shows(char* ptr)
{
	//__help("shows");
	for(int row = 0; row < 32; row++)
	{
		printf("%03x  ", row << 4);
		for(int col = 0; col < 16; col++)
			printf("%02x %s", (unsigned char)pdata[row * 16 + col], col == 7 ? " " : "");
		printf("\n");
	}
	printf("\n");
	return 0;
}

int Disk::str2hex(char* src, char* dst, int maxlen)
{
	char* p, *q, *temp;
	int len = strlen(src);

	temp = new char[len + 1];
	p = src;
	q = temp;

	// 过滤空格字符
	while(*p)
	{
		if(*p != ' ')
			*q++ = *p;
		p++;
	}
	*q = '\0';

	// 转换为16进制
	int num = min((int)strlen(temp) / 2, maxlen);
	for(int i = 0; i < num; i++)
	{
		char a = temp[i + i];
		char b = temp[i + i + 1];

		a -= a >= '0' && a <= '9' ? '0' : (a >= 'a' && a <= 'f' ? 'a' - 10 : a);
		b -= b >= '0' && b <= '9' ? '0' : (b >= 'a' && b <= 'f' ? 'a' - 10 : b);
		dst[i] = a << 4 | b;
	}
	delete[] temp;
	return num;
}

void Disk::write(char* ptr)
{
	// 命令格式
	__help("write sectorno");

	FILE* stream = fopen(driver, "rb+");
	if(!stream)
	{
		__err__;
		return;
	}

	setvbuf(stream, NULL, _IOFBF, SECTOR_SIZE);
	__int64 sector = _atoi64(ptr);
	_fseeki64(stream, sector * SECTOR_SIZE, SEEK_SET);

	int num = fwrite(pdata, SECTOR_SIZE, 1, stream);
	num ? printf("+OK\n\n") : __err__;
	fclose(stream);
}