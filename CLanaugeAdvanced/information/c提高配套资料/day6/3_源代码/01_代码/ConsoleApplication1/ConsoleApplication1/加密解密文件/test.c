#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "des.h"

#define  SIZE 1024*4

int main01(void)
{
	unsigned char buf[] = "153u532i4uodsjgldsjlgkjsd";
	int srcLen = strlen(buf);
	unsigned char dst[100] = { 0 }; //����
	int dstLen = 0; //���ĵĳ���
	int ret = 0;

	//����
	ret = DesEnc(buf, srcLen, dst, &dstLen);
	if (ret != 0)
	{
		printf("����ʧ�ܣ� err: %d\n", ret);
		return -1;
	}
	printf("%s���ܺ�%s\n", buf, dst);


	memset(buf, 0, sizeof(buf));
	int len = 0;
	//����
	ret = DesDec(dst,dstLen, buf, &len);
	if (ret != 0)
	{
		printf("����ʧ�ܣ� err: %d\n", ret);
		return -1;
	}

	if (srcLen != len)
	{
		printf("���ܺ�ĳ��Ⱥ�ԭ���Ĳ�һ��\n");
		return -2;
	}

	printf("%s  ���ܺ� : %s\n", dst, buf);


	printf("\n");
	system("pause");
	return 0;
}

void menu()
{
	printf("=====================\n");
	printf("1 �����ļ�\n");
	printf("2 �����ļ�\n");
	printf("3 ����\n");
	printf("4 �˳�\n");
	printf("=====================\n");
}

//�����ļ�
void EncFile()
{
	//��4k��С���ļ�, srcBuf
	//srcBuf ����-> dstBuf
	//dstBuf -> д�ļ�

	FILE *rFd = NULL;
	FILE *wFd = NULL;
	char rPath[512] = { 0 }; //Դ�ļ�·���� ��Ҫ�����ļ�·
	char wPath[512] = { 0 }; //Ŀ��·���� ������ܺ���ļ�
	unsigned char srcBuf[SIZE] = { 0 }; //4k
	int rLen = 0;
	unsigned char dstBuf[SIZE] = { 0 }; //4k
	int wLen = 0;
	int ret = 0;

	printf("��������Ҫ���ܵ��ļ���");
	scanf("%s", rPath);

	printf("��������ܺ���ļ���");
	scanf("%s", wPath);

	//����ʽ����Ҫ���ܵ��ļ�rPath
	rFd = fopen(rPath, "rb+");
	if (rFd == NULL)
	{
		perror("EncFile fopen rPath");
		return;
	}

	//д��ʽ�򿪼��ܺ���ļ�wPath
	wFd = fopen(wPath, "wb+");
	if (wFd == NULL)
	{
		perror("EncFile fopen wPath");
		goto End;
		return;
	}

	//ѭ����ȡ�ļ�
	while (1)
	{
		rLen = fread(srcBuf, 1, SIZE, rFd);
		//printf("rLen = %d\n", rLen);
		if (rLen < SIZE)//С��4k
		{
			break;
		}
		
		//srcBuf ���� -> dstBuf
		ret = DesEnc_raw(srcBuf, rLen, dstBuf, &wLen);
		if (ret != 0)
		{
			printf("DesEnc_raw ����=4k����ʧ��\n");
			goto End;
			return;
		}

		//д���ܺ���ļ�
		ret = fwrite(dstBuf, 1, wLen, wFd);
		if (ret != wLen)
		{
			printf("д���ܺ���ļ�=4k����ʧ��\n");
			goto End;
			return;
		}

	}

	//С��4k��С���ļ�, srcBuf
	//srcBuf ����-> dstBuf
	//srcBuf ���� -> dstBuf
	ret = DesEnc(srcBuf, rLen, dstBuf, &wLen);
	if (ret != 0)
	{
		printf("DesEnc_raw ����<4k����ʧ��\n");
		goto End;
		return;
	}

	//д���ܺ���ļ�
	ret = fwrite(dstBuf, 1, wLen, wFd);
	if (ret != wLen)
	{
		printf("д���ܺ���ļ�<4k����ʧ��\n");
		goto End;
		return;
	}

End:
	if (rFd != NULL)
	{
		fclose(rFd);
	}

	if (wFd != NULL)
	{
		fclose(wFd);
	}


}

//�����ļ�
void DecFile()
{

}

int main(void)
{
	int cmd;
	while (1)
	{
		menu();
		printf("cmd:");
		scanf("%d", &cmd);

		switch (cmd)
		{
		case 1:
			EncFile();
			break;
		case 2:
			DecFile();
			break;
		case 3:
			system("cls");
			break;
		default:
			exit(0);
			break;
		}

	}

	printf("\n");
	system("pause");
	return 0;
}