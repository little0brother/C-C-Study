/*++

	source.cpp, 2019/1/14
	(c) Qiansi Corporation, All rights reserved.

--*/
#include <iostream>
#include <time.h>
#include "disk.h"
using namespace std;

char diskno = 1;
char _data[512];

char* preprocess(char* ptr)
{
	while(*ptr && *ptr != ' ') 
		ptr++;
	*ptr++ = '\0';

	while(*ptr && *ptr == ' ') 
		ptr++;
	return ptr;
}

int str2hex(char* src, char* dst, int maxlen = 32)
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
	int num = min((int)strlen(src) / 2, maxlen);
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

void fillsector(char* ptr)
{
	__int64 sector = _atoi64(ptr);
	ptr = preprocess(ptr);

	char buf[32];
	str2hex(ptr, buf, 1);
	ptr = preprocess(ptr);

	clock_t ck = clock();
	Disk disk(diskno);

	if(disk.fillsector(sector, (BYTE)buf[0], atoi(ptr)))
	{
		ck = clock() - ck;
		printf("+OK(%d.%d)\n\n", ck / 1000, ck % 1000);
	}
}

void finddata(char* ptr)
{
	unsigned char udata[256];
	__int64 offset, pos;
	Disk disk(diskno);

	offset = _atoi64(ptr);
	ptr = preprocess(ptr);
	*(int*)&udata[0] = str2hex(ptr, (char*)&udata[4]);

	if((pos = disk.finddata(offset, udata)) >= 0)
		printf("pos = %#010llx\n\n", pos);
}

void findsign(char* ptr)
{
	Disk disk(diskno);
	__int64 sector;

	sector = _atoi64(ptr);
	disk.findsign(sector);
	printf("\n");
}

void readsector(char* ptr)
{
	Disk disk(diskno);
	__int64 sector;

	sector = _atoi64(ptr);
	if(disk.readsector(sector, (unsigned char*)_data))
	{
		//for(auto e : _data)
		//	printf("%02x ", (unsigned char)e);
		for (int i = 0; i < 32; i++)
		{
			printf("%03x  ", i * 16);
			for (int j = 0; j < 16; j++)
				printf("%02X %s", (unsigned char)_data[i * 16 + j],
				    j == 7 ? " " : "");
			printf("\n");
		}
		printf("\n\n");
	}
}

void writesector(char* ptr)
{
	Disk disk(diskno);
	__int64 sector;

	sector = _atoi64(ptr);
	if(disk.writesector(sector, (unsigned char*)_data))
		printf("+OK\n\n");
}

void setsign(char* ptr)
{
	Disk disk(diskno);
	__int64 sector;
	char data[32];

	sector = _atoi64(ptr);
	ptr = preprocess(ptr);
	str2hex(ptr, data);

	if(disk.setsign(sector, *(unsigned short*)&data[0]))
		printf("+OK\n\n");
}

void setdiskno(char* ptr)
{
	diskno = (char)atoi(ptr);
	printf("+OK\n\n");
}

void load(char* filename)
{
	FILE* stream = fopen(filename, "rb");
	if(!stream)
	{
		int err = errno;
		__err__;
		return;
	}

	int num = fread(_data, 512, 1, stream);
	for(auto e : _data)
		printf("%02x ", (unsigned char)e);
	printf("\n\n");
	fclose(stream);
}

void save(char* filename)
{
	FILE* stream = fopen(filename, "wb");
	if(!stream)
	{
		int err = errno;
		__err__;
		return;
	}

	int num = fwrite(_data, 512, 1, stream);
	if(!num)
	{
		int err = errno;
		__err__;
	}
	else
		printf("+OK\n\n");
	fclose(stream);
}

void disp(char* ptr)
{
	for(auto e : _data)
		printf("%02x ", (unsigned char)e);
	printf("\n\n");
}

void cleardata(char* ptr)
{
	for(auto& e : _data)
		e = 0;
	printf("+OK\n\n");
}

void replace(char* ptr)
{
	char* addr, udata[512];
	int num, start;

	addr = ptr;
	ptr = preprocess(ptr);
	num = str2hex(ptr, udata, 512);

	sscanf(addr, "%x", &start);
	for(int i = 0; i < num; i++)
	{
		if(start + i < 512)
			_data[start + i] = udata[i];
	}
	printf("+OK\n\n");
}

int main()
{
	printf("Disk Operating System\n"
		   "(c) Qiansi Corporation, 2019.\n\n");

	while(true)
	{
		char cmd[256] = {0}, *ptr;
		int i = 0;

		printf("disk>");
		while((cmd[i] = getchar()) != '\n' && i < 255)
			i++;
		cmd[i] = '\0';
		ptr = preprocess(cmd);

		#define command(x) \
		if(!_strcmpi(cmd, #x))\
		{\
			x(ptr);\
			continue;\
		}

		command(cleardata);
		command(disp);
		command(finddata);
		command(fillsector);
		command(findsign);

		command(load);
		command(readsector);
		command(replace);
		command(setsign);
		command(setdiskno);

		command(save);
		command(writesector);

		// exit
		if(!_strcmpi(cmd, "quit") || !_strcmpi(cmd, "exit"))
			break;

		// help
		printf("Exec commands:\n"
				"  cleardata\n"
				"  disp\n"
				"  finddata\n"
				"  fillsector\n"
				"  findsign\n"
				"  load\n"
				"  readsector\n"
				"  replace\n"
				"  setsign\n"
				"  setdiskno\n"
				"  save\n"
				"  writesector\n"
				"\n");
	}
	return 0;
}