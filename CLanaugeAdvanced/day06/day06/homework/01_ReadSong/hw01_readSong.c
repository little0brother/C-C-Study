#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_readSong(char* path)
{
	int ret = 0;

	FILE* fp = NULL;
	fp = fopen(path, "rb");
	if (fp == NULL)
	{
		perror("myreadSong fopen");
		return - 1;
	}

	// 将文件指针移动到文件尾，并计算文件长度
	fseek(fp, 0, SEEK_END);

	long fileLen = ftell(fp);
	printf("flieLen = %d\n", fileLen);
	if (fileLen < 0)
	{
		perror("fileLen");
		return -2;
	}

	// 动态申请内存空间，存储文件内容
	char* buf;
	buf = (char*)malloc(fileLen * sizeof(char) + 1);
	if (buf == NULL)
	{
		return -3;
	}

	// 将文件指针移动到头，进行文件内容读取
	rewind(fp);
	ret = fread(buf, fileLen, 1, fp);
	buf[fileLen] = 0;	// 字符串结束符

	if (ret == 1)
	{
		printf("文件内容为:\n%s\n", buf);
	}

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}

	if (buf != NULL)
	{
		free(buf);
		buf = NULL;
	}

	return 0;
}

int main()
{
	int ret = my_readSong("./homework/01_ReadSong/song.txt");
	if (ret != 0)
	{
		printf("my_readSong err: %d\n");
		return ret;
	}

	return 0;
}