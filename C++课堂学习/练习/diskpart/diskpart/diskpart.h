/*++

	disk.h, 2019/3/16
	(c) Qiansi Corporation, All rights reserved.

--*/
#pragma once

#define __err__ \
errlog(__FILE__, __LINE__)

#define succeed		  1
#define failed		  0
#define ERR			 -1
#define SECTOR_SIZE	512

class Disk
{
private:
	char driver[20];
	char* pdata;

	int errlog(const char* filename, long line);
	unsigned int crc32(unsigned char* pv, int length);

public:
	Disk(char diskno = 1)
	{
		strcpy(driver, "\\\\.\\PHYSICALDRIVE1");
		driver[17] = '0' + diskno;
		pdata = new char[SECTOR_SIZE];
	}

	~Disk()
	{
		if(pdata)
		{
			delete[] pdata;
			pdata = 0;
		}
	}

	//__int64 GetDriveGeometry();
	int shows(char* ptr);
	char* nextparam(char* ptr);
	int str2hex(char* src, char* dst, int maxlen = 32);

	void clear(char* ptr);
	void replace(char* ptr);
	void read(char* ptr);
	void write(char* ptr);

	void fill(char* ptr);
	void find(char* ptr);
	void findsign(char* ptr);
	void setsign(char* ptr);

	void load(char* filename);
	void save(char* filename);
	void setdisk(char* ptr);

	void crc32(char* ptr);
};