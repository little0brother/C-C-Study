#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//文件最大大小
#define MAXSIZE 8*1024 //8K

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

//读配置文件
int ReadCfgFile(char *fileName, char *pKey, char *pVal, int *pLen)
{

	if (fileName == NULL || pKey == NULL || pVal == NULL || pLen == NULL)
	{
		return -1;
	}

	FILE *fp = NULL;
	char buf[1024] = { 0 };
	char *tmp = NULL;
	int flag = 0; //如果没有key所对应的value，flag则为0

	//读方式打开文件
	fp = fopen(fileName, "r");
	if (fp == NULL)
	{
		perror("ReadCfgFile[fopen]");
		return -2;
	}

	//如果文件没有结束
	while (!feof(fp))
	{
		memset(buf, 0, sizeof(buf));
		tmp = fgets(buf, sizeof(buf), fp);
		if (tmp == NULL)
		{
			break;
		}

		//判断每行中是否包含key
		tmp = strstr(buf, pKey);
		if (NULL == tmp)//如果没有包含key
		{
			continue; //跳出本次循环
		}

		//重新设置搜索字符串的位置（跳过key）
		// "k1 = 1111" -> " = 1111"
		tmp = tmp + strlen(pKey);

		//判断是否包含=
		tmp = strchr(tmp, '=');
		if (NULL == tmp)
		{
			continue; //跳出本次循环
		}
		//重新设置搜索字符串的位置(跳过=)
		//"= 1111" -> "   1111  "
		tmp = tmp + 1;

		//获取非空字符，两头堵模型
		if (0 == trimSpace(tmp, pVal))
		{
			//到这，已经找到你所要求的value
			*pLen = strlen(pVal); 
			flag = 1;
		}
		
		break; //很重要
	}

	if (0 == flag)
	{
		printf("没有%s所对应的值\n", pKey);
		return -6;
	}

	//关闭文件
	if (fp != NULL)
	{
		fclose(fp);
	}

	return 0;
}

//写、修改配置文件
//实现流程
//循环读每一行
//此行包含key，则把key的value修改
//如果所有行都不包含key，则在文件结尾追加： "key = value"
//难点：如何修改
int WriteCfgFile(char *fileName, char *pKey, char *pVal, int len)
{
	if (fileName == NULL || pKey == NULL || pVal == NULL)
	{
		return -1;
	}

	FILE *fp = NULL;
	char tmpBuf[MAXSIZE] = { 0 };
	char lineBuf[1024] = { 0 };
	int flag = 0; //0: 不包括key

	//打开文件，读写方式打开，文件不存在，打开失败
	fp = fopen(fileName, "r+");
	if (fp == NULL) //文件不存在时，新建文件
	{
		//perror("WriteCfgFile ")
		//return -2;

		//写读方式打开文件，文件不存在则创建
		fp = fopen(fileName, "w+");
		if (fp == NULL)
		{
			perror("WriteCfgFile fopen");
			return -2;
		}
	}

	//假如文件存在
	//获取文件内容大小，看是否超出范围

	//把文件光标移动到结尾处
	fseek(fp, 0, SEEK_END);

	//获取文件内容大小
	long size = ftell(fp);

	//如果文件大小超过8k，中断程序
	if (size >= MAXSIZE)
	{
		printf("文件大小超过8k，不支持\n");
		fclose(fp);
		return -3;
	}

	//把文件光标移动到最开始位置
	//fseek(fp, 0, SEEK_SET);
	rewind(fp);

	//循环读每一行
	//此行包含key，则把key的value修改
	//如果所有行都不包含key，则在文件结尾追加： "key = value"
	while (!feof(fp))
	{
		if (NULL == fgets(lineBuf, sizeof(lineBuf), fp))
		{
			break;
		}

		//此行是否包含key
		if (strstr(lineBuf, pKey) != NULL) //包含
		{
			//重写给lineBuf格式化
			sprintf(lineBuf, "%s = %s\n", pKey, pVal);
			strcat(tmpBuf, lineBuf);
			flag = 1;
		}
		else
		{
			strcat(tmpBuf, lineBuf);
		}
	}

	
	if (0 == flag) //文件中没有key值
	{//如果所有行都不包含key，则在文件结尾追加： "key = value"
		//sprintf(lineBuf, "%s = %s", pKey, pVal);	

		//到这一步，文件光标已经移动到结尾处
		//如果此时往文件中写内容，肯定是追加到结尾处
		//格式化方式写文件
		fprintf(fp, "%s = %s\n", pKey, pVal);
	}
	else
	{	//关闭文件
		//重写以写方式打开文件，重写给文件写内容
		if (fp != NULL)
		{
			fclose(fp);
			fp = NULL;
		}

		//写读方式打开文件，文件不存在则创建
		fp = fopen(fileName, "w+");
		if (fp == NULL)
		{
			perror("WriteCfgFile fopen");
			return -4;
		}

		//往文件写内容
		fputs(tmpBuf, fp);
	}


	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}

	return  0;
}