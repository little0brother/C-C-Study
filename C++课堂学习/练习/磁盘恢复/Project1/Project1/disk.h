/*++

	disk.h, 2019/1/14
	(c) Qiansi Corporation, All rights reserved.

--*/
#pragma once
#include <windows.h>

#define __err__ \
Disk::errlog(__FILE__, __LINE__, err);

#define succeed  1
#define failed   0
#define ERR		-1
#define __C__

class Disk
{
	wchar_t disk[20];
	char* pdata;

public:
	Disk(char diskno = 1)
	{
		wcscpy(disk, L"\\\\.\\PHYSICALDRIVE1");
		disk[17] = L'0' + diskno;
		pdata = new char[512];
	}

	~Disk()
	{
		if(pdata)
			delete[] pdata;
	}

	static void errlog(char* file, int row, int err = errno);

	BOOL fillsector(__int64 sector, unsigned char val, int num);
	int findsign(__int64 sector);
	__int64 finddata(__int64 offset, unsigned char* udata);
	BOOL readsector(__int64 sector, unsigned char* udata);
	BOOL writesector(__int64 sector, unsigned char* udata);
	BOOL setsign(__int64 sector, unsigned short val);
};