#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define  SIZE 1024*8

/*
功能：获取非空字符串
参数：
inbuf： 原始字符串buf首地址
outbuf：非空字符串buf首地址
返回值：
成功：0
失败：非0
*/
int trimSpace(char *inbuf, char *outbuf)
{
	if (inbuf == NULL || outbuf == NULL)
	{
		return -1;
	}

	char *p = inbuf;
	int begin = 0;
	int end = strlen(p) - 1;
	int n = 0;

	if (end < 0){
		return -2;
	}

	//从左往右移动，如果当前字符为空，而且没有结束
	while (isspace(p[begin]) && p[begin] != 0)
	{
		begin++; //位置从右移动一位
	}

	//从右往左移动，如果当前字符为空
	while (isspace(p[end]) && end > 0)
	{
		end--; //往左移动
	}

	if (end == 0)
	{
		return -2;
	}

	n = end - begin + 1; //非空元素个数

	strncpy(outbuf, p + begin, n);
	outbuf[n] = 0;

	return 0;
}


int ReadCfgFile(char *file, char *key, char *value, int *len)
{

	if (file == NULL || key == NULL || value == NULL || len == NULL)
	{
		return -1;
	}

	FILE *fp = NULL;
	int ret = 0;
	char lineBuf[1024] = { 0 };
	char *p = NULL;
	int flag = 0; //0代表没有找到， 1代表找到

	//打开文件
	fp = fopen(file, "r+");
	if (fp == NULL)
	{
		ret = -2;
		goto End;
	}

	while (1)
	{
		//读取1行
		if (fgets(lineBuf, sizeof(lineBuf), fp) == NULL)
		{
			break;
		}

		//lineBuf = "k1 = abc"
		//找key
		p = strstr(lineBuf, key);
		if (p == NULL)//没有
		{
			continue; //跳出本次循环
		}

		//重新设置起点
		//"k1 = abc" -> " = abc"
		p = p + strlen(key);

		//找“=”
		p = strstr(p, "=");
		if (p == NULL)//没有
		{
			continue; //跳出本次循环
		}

		//重新设置起点
		//" = abc" -> " abc"
		p = p + strlen("=");

		//获取非空字符
		ret = trimSpace(p, value);
		if (ret == 0) //成功
		{
			*len = strlen(value);
			flag = 1;
			goto End;
		}
		else
		{
			goto End;
		}

	}




End:
	if (fp != NULL)
	{
		fclose(fp);
	}

	if (0 == flag)
	{
		ret = -3;
		printf("没有%s对应的value\n", key);
	}


	return ret;
}

int WriteCfgFile(char *file, char *key, char *value, int len)
{
	if (file == NULL || key == NULL || value == NULL)
	{
		return -1;
	}

	FILE *fp = NULL;
	int ret = 0;
	char lineBuf[1024] = { 0 };
	char buf[SIZE] = { 0 };
	char *p = NULL;
	int flag = 0; //0代表没有找到， 1代表找到

	//读写，“+”必须
	fp = fopen(file, "r+");
	if (fp == NULL)//打开失败，有可能是配置文件没有创建
	{
		//创建配置文件
		fp = fopen(file, "w+");
		{
			if (fp == NULL)
			{
				ret = -2;
				goto End;
			}
		}
	}

	//获取文件大小
	//光标移动到结尾
	fseek(fp, 0, SEEK_END);

	long size = ftell(fp);
	if (size >= SIZE)
	{
		ret = -3;
		printf("文件大小超过8k，不支持");
		goto End;
	}

	//光标回到文件开头
	rewind(fp);

	while (1)
	{
		if (fgets(lineBuf, sizeof(lineBuf), fp) == NULL)
		{
			break;
		}

		//每一行是否包含key
		if (strstr(lineBuf, key) != NULL)
		{//包含key
			flag = 1; //1代表文件中已经有key
			sprintf(lineBuf, "%s = %s\n", key, value);
			strcat(buf, lineBuf);

		}
		else
		{
			strcat(buf, lineBuf);
		}

	}

	//程序到这，2中情况
	if (0 == flag)//没有key
	{
		//文件光标已经移动到文件结尾
		fprintf(fp, "%s = %s\n", key, value);

	}
	else//有key
	{
		//关闭文件
		if (fp != NULL)
		{
			fclose(fp);
			fp = NULL;
		}

		fp = fopen(file, "w+"); 
		if (fp == NULL)
		{
			ret = -4;
			goto End;
		}

		//重写写内容
		fputs(buf, fp);
	}

End:
	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}

	return ret;
}