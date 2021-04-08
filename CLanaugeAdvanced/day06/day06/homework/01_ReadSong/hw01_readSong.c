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

	// ���ļ�ָ���ƶ����ļ�β���������ļ�����
	fseek(fp, 0, SEEK_END);

	long fileLen = ftell(fp);
	printf("flieLen = %d\n", fileLen);
	if (fileLen < 0)
	{
		perror("fileLen");
		return -2;
	}

	// ��̬�����ڴ�ռ䣬�洢�ļ�����
	char* buf;
	buf = (char*)malloc(fileLen * sizeof(char) + 1);
	if (buf == NULL)
	{
		return -3;
	}

	// ���ļ�ָ���ƶ���ͷ�������ļ����ݶ�ȡ
	rewind(fp);
	ret = fread(buf, fileLen, 1, fp);
	buf[fileLen] = 0;	// �ַ���������

	if (ret == 1)
	{
		printf("�ļ�����Ϊ:\n%s\n", buf);
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