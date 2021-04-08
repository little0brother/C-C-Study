#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fp = NULL;
	char *buf = NULL;

	//1、读方式打开文件
	fp = fopen("./song.txt", "rb");
	if (fp == NULL)
	{
		perror("fopen");
		return -1;
	}

	//2、文件光标移动到文件结尾
	fseek(fp, 0, SEEK_END);


	//3、获取文件的大小ftell
	long size = ftell(fp);

	//4、根据文件的大小动态分配一块buf
	if (size > 0)
	{
		buf = malloc(size + 1); //字符串结束符
		if (buf == NULL)
		{
			return -1;
		}
	}

	//5、文件光标恢复到开始位置
	rewind(fp);

	//6、按块方式读取文件内容
	int ret = fread(buf, size, 1, fp);
	//字符串结束符
	buf[size] = 0;
	if (ret == 1)
	{
		printf("buf = %s\n", buf);
	}

	if (buf != NULL)
	{
		free(buf);
		buf = NULL;
	}

	if (fp != NULL)
	{
		fclose(fp);
	}

	printf("\n");
	system("pause");
	return 0;
}