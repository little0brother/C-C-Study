#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1024*8 

int trimSpace(char* inbuf, char* outbuf)
{
	if (inbuf == NULL || outbuf == NULL)
	{
		return -1;
	}

	char* p = inbuf;
	char* buf = outbuf;

	// 定义字符串vlaue的起点终点
	int begin = 0;
	int end = strlen(inbuf) - 1;
	int n = 0;

	// 因为键值对中间会有空格，所以要去除空格
	while (isspace(inbuf[begin]) && (inbuf[begin] != NULL))
	{
		begin++;
	}

	while (isspace(inbuf[end]) && end > 0)
	{
		end--;
	}

	// 如果字符串为0 那么字符串不存在
	if (end == 0)
	{
		return -2;
	}


	// 记录字符串长度
	n = end - begin + 1;

	// 将字符串拷贝至vbuf，并通过形参返回至主函数
	strncpy(outbuf, inbuf + begin, n);
	outbuf[n] = 0;

	return 0;
}


int ReadCfgFile(char* file, char* key, char* value, int* len)
{
	if (file == NULL || key == NULL || value == NULL || len == NULL)
	{
		return -1;
	}

	FILE* fp = NULL;

	char lineBuf[1024] = { 0 };
	char* p = NULL;

	int flag = 0; // 0代表没有找到key
	int ret = 0;

	// 打开文件
	fp = fopen(file, "r+");
	if (fp == NULL)
	{
		ret = -2;
		goto End;
	}

	while (1)
	{
		// 读取1行
		if (fgets(lineBuf, sizeof(lineBuf), fp) == NULL)
		{
			break;
		}

		// lineBuf = "k1 = abc";
		p = strstr(lineBuf, key);
		if (p == NULL)
		{
			continue; // 跳出本次循环
		}

		// 重新设置起点
		// "k1 = abc" -> " = abc"
		p = p + strlen(key);

		// 查找 = ，如果有 = 代表有value
		p = strstr(p, "=");
		if (p == NULL)
		{
			continue;
		}

		// 重新设置起点
		// " = abc" -> " abc"
		p = p + strlen("=");

		// 获取非空字符串
		ret = trimSpace(p, value);
		if (ret == 0) // 成功
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
		fp = NULL;
	}

	if (flag == 0)
	{
		ret = -3;
		printf("没有%s对应的value\n", key);
	}

	return ret;
}


int WriteCfgFile(char* file, char* key, char* value, int len)
{
	if (file == NULL || key == NULL || value == NULL)
	{
		return -1;
	}

	FILE* fp = NULL;

	char lineBuf[1024] = { 0 };	
	char buf[SIZE] = { 0 };
	char* p = NULL;

	int flag = 0; // 0代表没有找到key
	int ret = 0;

	// 读写 ，“+”
	fp = fopen(file, "r+");
	if (fp == NULL)		// 打开失败，有可能是配置文件没有创建
	{
		// 创建配置文件
		fp = fopen(file, "w+");
		{
			if (fp == NULL)
			{
				ret = -2;
				goto End;
			}
		}
	}

	// 获取文件大小
	// 光标移动到结尾
	fseek(fp, 0, SEEK_END);

	long size = ftell(fp);
	if (size >= SIZE)
	{
		ret = -3;
		printf("文件超过8k,不支持");
		goto End;
	}

	// 光标回到文件头
	rewind(fp);

	while (1)
	{
		// 按照行将文件进行读取到字符串中，在字符串进行操作
		if (fgets(lineBuf, sizeof(lineBuf), fp) == NULL)
		{
			break;
		}

		// 每一行是否包含key，如果包含key，则将用户需要修改的key值写入到字符串中，通过下方操作，将字符串中的数据覆盖掉之前的配置文件
		if (strstr(lineBuf, key) != NULL)	// 包含key
		{
			flag = 1;	// 1代表文件中已经有key
			sprintf(lineBuf, "%s = %s\n", key, value);

			strcat(buf, lineBuf);
		}
		else
		{
			strcat(buf, lineBuf);
		}
	}

	// 程序到这，两种情况
	if (flag == 0)	// 没有key
	{
		// 文件光标，已经移动到文件结尾, 直接在文件尾进行追加操作
		fprintf(fp, "%s = %s\n", key, value);
	}
	else    // 有key
	{
		// 关闭文件
		if (fp == NULL)
		{
			fclose(fp);
			fp = NULL;
		}

		// 重新写内容，将刚才修改后文件读取到字符串中，并且全部进行替换操作
		fp = fopen(file, "w+");
		if (fp == NULL)
		{
			ret = -4;
			goto End;
		}

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