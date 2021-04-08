#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "des.h"

#define SIZE 1024 * 4 //4K

void MyMenu()
{
	printf("================================\n");
	printf("1 加密文件\n");
	printf("2 解密文件\n");
	printf("3 清屏\n");
	printf("4 退出\n");
	printf("================================\n");
}

//加密文件
void FileEnc()
{
	char srcFile[512] = { 0 };
	char dstFile[512] = { 0 };
	
	printf("\n请输入需要加密的文件: ");
	scanf("%s", srcFile);

	printf("\n请输入加密后的文件: ");
	scanf("%s", dstFile);

	FILE *rFp = NULL;
	FILE *wFp = NULL;

	unsigned char srcBuf[SIZE] = { 0 }; //明文
	int srcLen = 0; //明文长度
	unsigned char dstBuf[SIZE] = { 0 }; //密文
	int dstLen = 0;	//密文长度
	int ret = 0;
	int wLen = 0;

	//读、二进制方式打开需要加密的文件
	rFp = fopen(srcFile, "rb");
	if (rFp == NULL)
	{
		perror("FileEnc fopen srcFile");
		goto End;
	}

	//写、二进制方式打开加密后的文件
	wFp = fopen(dstFile, "wb");
	if (wFp == NULL)
	{
		perror("FileEnc fopen dstFile");
		goto End;
	}

	//从源文件中读取数据
	//4k: DesEnc_raw()
	//<4k: DesEnc()
	while (!feof(rFp)) //文件没有结束
	{
		//从文件中读取内容
		//srcBuf: 存放文件内容的buf
		//1：每次读1个字节
		//SIZE: 一次读4k块内存， 读取内容的大小： SIZE * 1
		//返回值：成功读取内容的块数
		srcLen = fread(srcBuf, 1, SIZE, rFp);
		if (srcLen < SIZE) //如果读取内容<4k，跳出循环
		{
			break;
		}

		//=4k数据的加密处理
		//把明文srcBuf(长度为srcLen)加密为密文dstBuf(长度为dstLen)
		ret = DesEnc_raw(srcBuf, srcLen, dstBuf, &dstLen);
		if (ret != 0)
		{
			printf("FileEnc DesEnc_raw err: %d\n", ret);
			goto End;
		}

		//把密文dstBuf(长度为dstLen)写到文件wFp中
		wLen = fwrite(dstBuf, 1, dstLen, wFp);
		if (wLen != dstLen)
		{
			printf("（等于4k）写文件失败\n");
			goto End;
		}
	}

	//小于4k的处理
	//把明文srcBuf(长度为srcLen)加密为密文dstBuf(长度为dstLen)
	ret = DesEnc(srcBuf, srcLen, dstBuf, &dstLen);
	if (ret != 0)
	{
		printf("FileEnc DesEnc err: %d\n", ret);
		goto End;
	}

	//把密文dstBuf(长度为dstLen)写到文件wFp中
	wLen = fwrite(dstBuf, 1, dstLen, wFp);
	if (wLen != dstLen)
	{
		printf("（小于4k）写文件失败\n");
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

//解密文件
void FileDec()
{
	char srcFile[512] = { 0 };
	char dstFile[512] = { 0 };

	printf("\n请输入需要解密的文件: ");
	scanf("%s", srcFile);

	printf("\n请输入解密后的文件: ");
	scanf("%s", dstFile);

	FILE *rFp = NULL;
	FILE *wFp = NULL;

	unsigned char srcBuf[SIZE] = { 0 }; //密文
	int srcLen = 0; //密文长度
	unsigned char dstBuf[SIZE] = { 0 }; //明文
	int dstLen = 0;	//明文长度
	int ret = 0;
	int wLen = 0;

	//读、二进制方式打开需要解密的文件
	rFp = fopen(srcFile, "rb");
	if (rFp == NULL)
	{
		perror("FileDec fopen srcFile");
		goto End;
	}

	//写、二进制方式打开解密后的文件
	wFp = fopen(dstFile, "wb");
	if (wFp == NULL)
	{
		perror("FileDec fopen dstFile");
		goto End;
	}

	//从源文件中读取数据
	//4k: DesDec_raw()
	//<4k: DesDec()
	while (!feof(rFp)) //文件没有结束
	{
		//从文件中读取内容
		//srcBuf: 存放文件内容的buf
		//1：每次读1个字节
		//SIZE: 一次读4k内存， 读取内容的大小： SIZE * 1
		//返回值：成功读取内容的块数
		srcLen = fread(srcBuf, 1, SIZE, rFp);
		if (srcLen < SIZE) //如果读取内容<4k，跳出循环
		{
			break;
		}

		//=4k数据的解密处理
		//把明文srcBuf(长度为srcLen)解密为明文dstBuf(长度为dstLen)
		ret = DesDec_raw(srcBuf, srcLen, dstBuf, &dstLen);
		if (ret != 0)
		{
			printf("FileDec DesDec_raw err: %d\n", ret);
			goto End;
		}

		//把明文dstBuf(长度为dstLen)写到文件wFp中
		wLen = fwrite(dstBuf, 1, dstLen, wFp);
		if (wLen != dstLen)
		{
			printf("（等于4k）写文件失败\n");
			goto End;
		}

	}

	//小于4k的处理
	//把明文srcBuf(长度为srcLen)解密为明文dstBuf(长度为dstLen)
	ret = DesDec(srcBuf, srcLen, dstBuf, &dstLen);
	if (ret != 0)
	{
		printf("FileDec DesDec err: %d\n", ret);
		goto End;
	}

	//把密文dstBuf(长度为dstLen)写到文件wFp中
	wLen = fwrite(dstBuf, 1, dstLen, wFp);
	if (wLen != dstLen)
	{
		printf("（小于4k）写文件失败\n");
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