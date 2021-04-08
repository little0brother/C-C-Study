#include <stdio.h>
#include <stdlib.h>
#include "des.h"

#define SIZE 1024*4

void menu()
{
	printf("=============================\n");
	printf("1.加密文件\n");
	printf("2.解密文件\n");
	printf("3.清屏\n");
	printf("4.退出\n");
	printf("=============================\n");
}

// 加密文件
void EncFile()
{
	// 以4k大小读文件，srcBuf
	// rBuf 加密 -> dstBuf
	// dstBuf -> 写文件

	FILE* rFd = NULL;
	FILE* wFd = NULL;
	char rPath[512] = { 0 };	// 源文件路径(需要加密文件路径)
	char wPath[512] = { 0 };	// 目标路径(保存加密后的文件)
	unsigned char srcBuf[SIZE] = { 0 };	// 4k 所读文件的存储
	int rLen = 0;	// 所读文件长度
	unsigned char dstBuf[SIZE] = { 0 };	// 4k 加密后要向文件中写的存储
	int wLen = 0;	// 加密后要写文件的长度
	int ret = 0;	// 接收函数返回值

	printf("请输入需要加密的文件名:");
	scanf("%s", rPath);

	printf("请输入加密后的文件名:");
	scanf("%s", wPath);

	// 读方式打开需要加密的文件 rPath
	rFd = fopen(rPath, "rb+");
	if (rFd == NULL)
	{
		perror("EncFile fopen rPath");
		return;
	}

	// 写方式打开加密后的文件 wPath
	wFd = fopen(wPath, "wb+");
	if (wFd == NULL)
	{
		perror("EncFile fopen wPath");
		goto End;
		return;
	}

	// 循环读取文件
	while (1)
	{
		rLen = fread(srcBuf, 1, SIZE, rFd);
		if (rLen < SIZE)	// 当文件小于4k时跳出循环，执行下方 < 4k 文件加密
		{
			break;
		}
		
		// srcBuf 加密 -> dstBuf
		ret = DesEnc_raw(srcBuf, rLen, dstBuf, &wLen);
		if (ret != 0)
		{
			printf("DesDec_raw 加密=4k数据失败\n");
			goto End;
			return;
		}

		// 写加密后的文件
		ret = fwrite(dstBuf, 1, wLen, wFd);
		if (ret != wLen)
		{
			printf("写加密后的文件=4k数据失败\n");
			goto End;
			return;
		}
	}


	// 小于4k大小读文件，srcBuf
	// rBuf 加密 -> dstBuf
	// dstBuf -> 写文件
	// srcBuf 加密 -> dstBuf
	ret = DesEnc(srcBuf, rLen, dstBuf, &wLen);
	if (ret != 0)
	{
		printf("DesDec 加密 < 4k数据失败\n");
		goto End;
		return;
	}

	// 写加密后的文件
	ret = fwrite(dstBuf, 1, wLen, wFd);
	if (ret != wLen)
	{
		printf("写加密后的文件 < 4k数据失败\n");
		goto End;
		return;
	}

End:
	if (rFd != NULL)
	{
		fclose(rFd);
		rFd = NULL;
	}
	if (wFd != NULL)
	{
		fclose(wFd);
		wFd = NULL;
	}
}

// 解密文件 (与加密文件相反)
void DecFile()
{
	// 以4k大小读文件，srcBuf
	// rBuf 解密 -> dstBuf
	// dstBuf -> 写文件

	FILE* rFd = NULL;
	FILE* wFd = NULL;
	char rPath[512] = { 0 };	// 源文件路径(需要解密文件路径)
	char wPath[512] = { 0 };	// 目标路径(保存解密后的文件)
	unsigned char srcBuf[SIZE] = { 0 };	// 4k 所读文件的存储
	int rLen = 0;	// 所读文件长度
	unsigned char dstBuf[SIZE] = { 0 };	// 4k 解密后要向文件中写的存储
	int wLen = 0;	// 解密后要写文件的长度
	int ret = 0;	// 接收函数返回值

	printf("请输入需要解密的文件名:");
	scanf("%s", rPath);

	printf("请输入解密后的文件名:");
	scanf("%s", wPath);

	// 读方式打开需要解密的文件 rPath
	rFd = fopen(rPath, "rb+");
	if (rFd == NULL)
	{
		perror("EncFile fopen rPath");
		return;
	}

	// 写方式打开解密后的文件 wPath
	wFd = fopen(wPath, "wb+");
	if (wFd == NULL)
	{
		perror("EncFile fopen wPath");
		goto End;
		return;
	}

	// 循环读取文件
	while (1)
	{
		rLen = fread(srcBuf, 1, SIZE, rFd);
		if (rLen < SIZE)	// 当文件小于4k时跳出循环，执行下方 < 4k 文件解密
		{
			break;
		}

		// srcBuf 解密 -> dstBuf
		ret = DesDec_raw(srcBuf, rLen, dstBuf, &wLen);
		if (ret != 0)
		{
			printf("DesDec_raw 解密=4k数据失败\n");
			goto End;
			return;
		}

		// 写解密后的文件
		ret = fwrite(dstBuf, 1, wLen, wFd);
		if (ret != wLen)
		{
			printf("写解密后的文件=4k数据失败\n");
			goto End;
			return;
		}
	}


	// 小于4k大小读文件，srcBuf
	// rBuf 解密 -> dstBuf
	// dstBuf -> 写文件
	// srcBuf 解密 -> dstBuf
	ret = DesDec(srcBuf, rLen, dstBuf, &wLen);
	if (ret != 0)
	{
		printf("DesDec 解密 < 4k数据失败\n");
		goto End;
		return;
	}

	// 写解密后的文件
	ret = fwrite(dstBuf, 1, wLen, wFd);
	if (ret != wLen)
	{
		printf("写解密后的文件 < 4k数据失败\n");
		goto End;
		return;
	}

End:
	if (rFd != NULL)
	{
		fclose(rFd);
		rFd = NULL;
	}
	if (wFd != NULL)
	{
		fclose(wFd);
		wFd = NULL;
	}
}

int main()
{
	int cmd;

	while (1)
	{
		menu();
		printf("cmd:");
		scanf("%d", &cmd);

		switch (cmd)
		{
		case 1: EncFile(); break;
		case 2: DecFile(); break;
		case 3: system("cls"); break;
		default: exit(0); break;
		}
	}

	return 0;
}