#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "des.h"

#define SIZE 1024*4

void meun()
{
	printf("**********************************\n");
	printf("1.加密文件\n");
	printf("2.解密文件\n");
	printf("3.清屏\n");
	printf("4.退出\n");
	printf("**********************************\n");
}

void EncryptFile()
{
	FILE* rfp = NULL;
	FILE* wfp = NULL;

	char rpath[128] = { 0 };
	char wpath[128] = { 0 };

	int rlen = 0;
	int wlen = 0;

	unsigned char srcBuf[SIZE] = { 0 };
	unsigned char dstBuf[SIZE] = { 0 };

	int ret = 0;

	printf("请输入需加密的文件名:");
	scanf("%s", rpath);
	printf("请输入加密后的文件名:");
	scanf("%s", wpath);

	rfp = fopen(rpath, "rb+");
	if (rfp == NULL)
	{
		perror("[EncryptFile] rfp fopen");
		return;
	}

	wfp = fopen(wpath, "wb+");
	if (wfp == NULL)
	{
		perror("[EncryptFile] wfp fopen");
		return;
	}

	while (1)
	{
		rlen = fread(srcBuf, 1, SIZE, rfp);
		if (rlen < SIZE)
		{
			break;
		}

		ret = DesEnc_raw(srcBuf, rlen, dstBuf, &wlen);
		if (ret != 0)
		{
			printf("[EncryptFile]:DesEnc_raw err:%d\n", ret);
			goto END;
			return;
		}

		ret = fwrite(dstBuf, 1, wlen, wfp);
		if (ret != wlen)
		{
			printf("[EncryptFile]:fwrite1 err:%d\n", ret);
			goto END;
			return;
		}
	}

	ret = DesEnc(srcBuf, rlen, dstBuf, &wlen);
	if (ret != 0)
	{
		printf("[EncryptFile]:DesEnc_raw err:%d\n", ret);
		goto END;
		return;
	}

	ret = fwrite(dstBuf, 1, wlen, wfp);
	if (ret != wlen)
	{
		printf("[EncryptFile]:fwrite err:%d\n", ret);
		goto END;
		return;
	}

END:
	if (rfp != NULL)
	{
		fclose(rfp);
		rfp = NULL;
	}

	if (wfp != NULL)
	{
		fclose(wfp);
		wfp = NULL;
	}
}

void DecryptFile()
{
	FILE* rfp = NULL;
	FILE* wfp = NULL;

	char rpath[128] = { 0 };
	char wpath[128] = { 0 };

	int rlen = 0;
	int wlen = 0;

	unsigned char srcBuf[SIZE] = { 0 };
	unsigned char dstBuf[SIZE] = { 0 };

	int ret = 0;

	printf("请输入需解密的文件名:");
	scanf("%s", rpath);
	printf("请输入解密后的文件名:");
	scanf("%s", wpath);

	rfp = fopen(rpath, "rb+");
	if (rfp == NULL)
	{
		perror("[EncryptFile] rfp fopen");
		return;
	}

	wfp = fopen(wpath, "wb+");
	if (wfp == NULL)
	{
		perror("[EncryptFile] wfp fopen");
		return;
	}

	while (1)
	{
		rlen = fread(srcBuf, 1, SIZE, rfp);
		if (rlen < SIZE)
		{
			break;
		}

		ret = DesDec_raw(srcBuf, rlen, dstBuf, &wlen);
		if (ret != 0)
		{
			printf("[EncryptFile]:DesEnc_raw err:%d\n", ret);
			goto END;
			return;
		}

		ret = fwrite(dstBuf, 1, wlen, wfp);
		if (ret != wlen)
		{
			printf("[EncryptFile]:fwrite1 err:%d\n", ret);
			goto END;
			return;
		}
	}

	ret = DesDec(srcBuf, rlen, dstBuf, &wlen);
	if (ret != 0)
	{
		printf("[EncryptFile]:DesEnc_raw err:%d\n", ret);
		goto END;
		return;
	}

	ret = fwrite(dstBuf, 1, wlen, wfp);
	if (ret != wlen)
	{
		printf("[EncryptFile]:fwrite err:%d\n", ret);
		goto END;
		return;
	}

END:
	if (rfp != NULL)
	{
		fclose(rfp);
		rfp = NULL;
	}

	if (wfp != NULL)
	{
		fclose(wfp);
		wfp = NULL;
	}
}

int main()
{	
	int cmd = 0;

	while (1)
	{
		meun();
		printf("cmd:");
		scanf("%d", &cmd);

		switch (cmd)
		{
		case 1: EncryptFile(); break;
		case 2: DecryptFile(); break;
		case 3:	system("cls"); break;
		case 4: exit(0);
		}
	}

	return 0;
}