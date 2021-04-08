#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "des.h"

#define SIZE 1024 * 4 //4K

void MyMenu()
{
	printf("================================\n");
	printf("1 �����ļ�\n");
	printf("2 �����ļ�\n");
	printf("3 ����\n");
	printf("4 �˳�\n");
	printf("================================\n");
}

//�����ļ�
void FileEnc()
{
	char srcFile[512] = { 0 };
	char dstFile[512] = { 0 };
	
	printf("\n��������Ҫ���ܵ��ļ�: ");
	scanf("%s", srcFile);

	printf("\n��������ܺ���ļ�: ");
	scanf("%s", dstFile);

	FILE *rFp = NULL;
	FILE *wFp = NULL;

	unsigned char srcBuf[SIZE] = { 0 }; //����
	int srcLen = 0; //���ĳ���
	unsigned char dstBuf[SIZE] = { 0 }; //����
	int dstLen = 0;	//���ĳ���
	int ret = 0;
	int wLen = 0;

	//���������Ʒ�ʽ����Ҫ���ܵ��ļ�
	rFp = fopen(srcFile, "rb");
	if (rFp == NULL)
	{
		perror("FileEnc fopen srcFile");
		goto End;
	}

	//д�������Ʒ�ʽ�򿪼��ܺ���ļ�
	wFp = fopen(dstFile, "wb");
	if (wFp == NULL)
	{
		perror("FileEnc fopen dstFile");
		goto End;
	}

	//��Դ�ļ��ж�ȡ����
	//4k: DesEnc_raw()
	//<4k: DesEnc()
	while (!feof(rFp)) //�ļ�û�н���
	{
		//���ļ��ж�ȡ����
		//srcBuf: ����ļ����ݵ�buf
		//1��ÿ�ζ�1���ֽ�
		//SIZE: һ�ζ�4k���ڴ棬 ��ȡ���ݵĴ�С�� SIZE * 1
		//����ֵ���ɹ���ȡ���ݵĿ���
		srcLen = fread(srcBuf, 1, SIZE, rFp);
		if (srcLen < SIZE) //�����ȡ����<4k������ѭ��
		{
			break;
		}

		//=4k���ݵļ��ܴ���
		//������srcBuf(����ΪsrcLen)����Ϊ����dstBuf(����ΪdstLen)
		ret = DesEnc_raw(srcBuf, srcLen, dstBuf, &dstLen);
		if (ret != 0)
		{
			printf("FileEnc DesEnc_raw err: %d\n", ret);
			goto End;
		}

		//������dstBuf(����ΪdstLen)д���ļ�wFp��
		wLen = fwrite(dstBuf, 1, dstLen, wFp);
		if (wLen != dstLen)
		{
			printf("������4k��д�ļ�ʧ��\n");
			goto End;
		}
	}

	//С��4k�Ĵ���
	//������srcBuf(����ΪsrcLen)����Ϊ����dstBuf(����ΪdstLen)
	ret = DesEnc(srcBuf, srcLen, dstBuf, &dstLen);
	if (ret != 0)
	{
		printf("FileEnc DesEnc err: %d\n", ret);
		goto End;
	}

	//������dstBuf(����ΪdstLen)д���ļ�wFp��
	wLen = fwrite(dstBuf, 1, dstLen, wFp);
	if (wLen != dstLen)
	{
		printf("��С��4k��д�ļ�ʧ��\n");
		goto End;
	}

End:
	if (rFp != NULL)
	{
		fclose(rFp);
	}

	if (wFp != NULL)
	{
		fclose(wFp);
	}


}

//�����ļ�
void FileDec()
{
	char srcFile[512] = { 0 };
	char dstFile[512] = { 0 };

	printf("\n��������Ҫ���ܵ��ļ�: ");
	scanf("%s", srcFile);

	printf("\n��������ܺ���ļ�: ");
	scanf("%s", dstFile);

	FILE *rFp = NULL;
	FILE *wFp = NULL;

	unsigned char srcBuf[SIZE] = { 0 }; //����
	int srcLen = 0; //���ĳ���
	unsigned char dstBuf[SIZE] = { 0 }; //����
	int dstLen = 0;	//���ĳ���
	int ret = 0;
	int wLen = 0;

	//���������Ʒ�ʽ����Ҫ���ܵ��ļ�
	rFp = fopen(srcFile, "rb");
	if (rFp == NULL)
	{
		perror("FileDec fopen srcFile");
		goto End;
	}

	//д�������Ʒ�ʽ�򿪽��ܺ���ļ�
	wFp = fopen(dstFile, "wb");
	if (wFp == NULL)
	{
		perror("FileDec fopen dstFile");
		goto End;
	}

	//��Դ�ļ��ж�ȡ����
	//4k: DesDec_raw()
	//<4k: DesDec()
	while (!feof(rFp)) //�ļ�û�н���
	{
		//���ļ��ж�ȡ����
		//srcBuf: ����ļ����ݵ�buf
		//1��ÿ�ζ�1���ֽ�
		//SIZE: һ�ζ�4k�ڴ棬 ��ȡ���ݵĴ�С�� SIZE * 1
		//����ֵ���ɹ���ȡ���ݵĿ���
		srcLen = fread(srcBuf, 1, SIZE, rFp);
		if (srcLen < SIZE) //�����ȡ����<4k������ѭ��
		{
			break;
		}

		//=4k���ݵĽ��ܴ���
		//������srcBuf(����ΪsrcLen)����Ϊ����dstBuf(����ΪdstLen)
		ret = DesDec_raw(srcBuf, srcLen, dstBuf, &dstLen);
		if (ret != 0)
		{
			printf("FileDec DesDec_raw err: %d\n", ret);
			goto End;
		}

		//������dstBuf(����ΪdstLen)д���ļ�wFp��
		wLen = fwrite(dstBuf, 1, dstLen, wFp);
		if (wLen != dstLen)
		{
			printf("������4k��д�ļ�ʧ��\n");
			goto End;
		}

	}

	//С��4k�Ĵ���
	//������srcBuf(����ΪsrcLen)����Ϊ����dstBuf(����ΪdstLen)
	ret = DesDec(srcBuf, srcLen, dstBuf, &dstLen);
	if (ret != 0)
	{
		printf("FileDec DesDec err: %d\n", ret);
		goto End;
	}

	//������dstBuf(����ΪdstLen)д���ļ�wFp��
	wLen = fwrite(dstBuf, 1, dstLen, wFp);
	if (wLen != dstLen)
	{
		printf("��С��4k��д�ļ�ʧ��\n");
		goto End;
	}

End:
	if (rFp != NULL)
	{
		fclose(rFp);
	}

	if (wFp != NULL)
	{
		fclose(wFp);
	}

}

int main()
{
	int cmd;

	while (1)
	{
		MyMenu();
		printf("cmd:");
		scanf("%d", &cmd);

		switch (cmd)
		{
		case 1:
			FileEnc();
			break;
		case 2:
			FileDec();
			break;
		case 3:
			system("cls");
			break;
		default:
			exit(0);
		}

	}

	printf("\n");
	system("pause");
	return 0;
}