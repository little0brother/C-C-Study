#include <stdio.h>
#include <stdlib.h>
#include "des.h"

#define SIZE 1024*4

void menu()
{
	printf("=============================\n");
	printf("1.�����ļ�\n");
	printf("2.�����ļ�\n");
	printf("3.����\n");
	printf("4.�˳�\n");
	printf("=============================\n");
}

// �����ļ�
void EncFile()
{
	// ��4k��С���ļ���srcBuf
	// rBuf ���� -> dstBuf
	// dstBuf -> д�ļ�

	FILE* rFd = NULL;
	FILE* wFd = NULL;
	char rPath[512] = { 0 };	// Դ�ļ�·��(��Ҫ�����ļ�·��)
	char wPath[512] = { 0 };	// Ŀ��·��(������ܺ���ļ�)
	unsigned char srcBuf[SIZE] = { 0 };	// 4k �����ļ��Ĵ洢
	int rLen = 0;	// �����ļ�����
	unsigned char dstBuf[SIZE] = { 0 };	// 4k ���ܺ�Ҫ���ļ���д�Ĵ洢
	int wLen = 0;	// ���ܺ�Ҫд�ļ��ĳ���
	int ret = 0;	// ���պ�������ֵ

	printf("��������Ҫ���ܵ��ļ���:");
	scanf("%s", rPath);

	printf("��������ܺ���ļ���:");
	scanf("%s", wPath);

	// ����ʽ����Ҫ���ܵ��ļ� rPath
	rFd = fopen(rPath, "rb+");
	if (rFd == NULL)
	{
		perror("EncFile fopen rPath");
		return;
	}

	// д��ʽ�򿪼��ܺ���ļ� wPath
	wFd = fopen(wPath, "wb+");
	if (wFd == NULL)
	{
		perror("EncFile fopen wPath");
		goto End;
		return;
	}

	// ѭ����ȡ�ļ�
	while (1)
	{
		rLen = fread(srcBuf, 1, SIZE, rFd);
		if (rLen < SIZE)	// ���ļ�С��4kʱ����ѭ����ִ���·� < 4k �ļ�����
		{
			break;
		}
		
		// srcBuf ���� -> dstBuf
		ret = DesEnc_raw(srcBuf, rLen, dstBuf, &wLen);
		if (ret != 0)
		{
			printf("DesDec_raw ����=4k����ʧ��\n");
			goto End;
			return;
		}

		// д���ܺ���ļ�
		ret = fwrite(dstBuf, 1, wLen, wFd);
		if (ret != wLen)
		{
			printf("д���ܺ���ļ�=4k����ʧ��\n");
			goto End;
			return;
		}
	}


	// С��4k��С���ļ���srcBuf
	// rBuf ���� -> dstBuf
	// dstBuf -> д�ļ�
	// srcBuf ���� -> dstBuf
	ret = DesEnc(srcBuf, rLen, dstBuf, &wLen);
	if (ret != 0)
	{
		printf("DesDec ���� < 4k����ʧ��\n");
		goto End;
		return;
	}

	// д���ܺ���ļ�
	ret = fwrite(dstBuf, 1, wLen, wFd);
	if (ret != wLen)
	{
		printf("д���ܺ���ļ� < 4k����ʧ��\n");
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

// �����ļ� (������ļ��෴)
void DecFile()
{
	// ��4k��С���ļ���srcBuf
	// rBuf ���� -> dstBuf
	// dstBuf -> д�ļ�

	FILE* rFd = NULL;
	FILE* wFd = NULL;
	char rPath[512] = { 0 };	// Դ�ļ�·��(��Ҫ�����ļ�·��)
	char wPath[512] = { 0 };	// Ŀ��·��(������ܺ���ļ�)
	unsigned char srcBuf[SIZE] = { 0 };	// 4k �����ļ��Ĵ洢
	int rLen = 0;	// �����ļ�����
	unsigned char dstBuf[SIZE] = { 0 };	// 4k ���ܺ�Ҫ���ļ���д�Ĵ洢
	int wLen = 0;	// ���ܺ�Ҫд�ļ��ĳ���
	int ret = 0;	// ���պ�������ֵ

	printf("��������Ҫ���ܵ��ļ���:");
	scanf("%s", rPath);

	printf("��������ܺ���ļ���:");
	scanf("%s", wPath);

	// ����ʽ����Ҫ���ܵ��ļ� rPath
	rFd = fopen(rPath, "rb+");
	if (rFd == NULL)
	{
		perror("EncFile fopen rPath");
		return;
	}

	// д��ʽ�򿪽��ܺ���ļ� wPath
	wFd = fopen(wPath, "wb+");
	if (wFd == NULL)
	{
		perror("EncFile fopen wPath");
		goto End;
		return;
	}

	// ѭ����ȡ�ļ�
	while (1)
	{
		rLen = fread(srcBuf, 1, SIZE, rFd);
		if (rLen < SIZE)	// ���ļ�С��4kʱ����ѭ����ִ���·� < 4k �ļ�����
		{
			break;
		}

		// srcBuf ���� -> dstBuf
		ret = DesDec_raw(srcBuf, rLen, dstBuf, &wLen);
		if (ret != 0)
		{
			printf("DesDec_raw ����=4k����ʧ��\n");
			goto End;
			return;
		}

		// д���ܺ���ļ�
		ret = fwrite(dstBuf, 1, wLen, wFd);
		if (ret != wLen)
		{
			printf("д���ܺ���ļ�=4k����ʧ��\n");
			goto End;
			return;
		}
	}


	// С��4k��С���ļ���srcBuf
	// rBuf ���� -> dstBuf
	// dstBuf -> д�ļ�
	// srcBuf ���� -> dstBuf
	ret = DesDec(srcBuf, rLen, dstBuf, &wLen);
	if (ret != 0)
	{
		printf("DesDec ���� < 4k����ʧ��\n");
		goto End;
		return;
	}

	// д���ܺ���ļ�
	ret = fwrite(dstBuf, 1, wLen, wFd);
	if (ret != wLen)
	{
		printf("д���ܺ���ļ� < 4k����ʧ��\n");
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