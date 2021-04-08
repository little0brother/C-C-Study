#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fp = NULL;
	char *buf = NULL;

	//1������ʽ���ļ�
	fp = fopen("./song.txt", "rb");
	if (fp == NULL)
	{
		perror("fopen");
		return -1;
	}

	//2���ļ�����ƶ����ļ���β
	fseek(fp, 0, SEEK_END);


	//3����ȡ�ļ��Ĵ�Сftell
	long size = ftell(fp);

	//4�������ļ��Ĵ�С��̬����һ��buf
	if (size > 0)
	{
		buf = malloc(size + 1); //�ַ���������
		if (buf == NULL)
		{
			return -1;
		}
	}

	//5���ļ����ָ�����ʼλ��
	rewind(fp);

	//6�����鷽ʽ��ȡ�ļ�����
	int ret = fread(buf, size, 1, fp);
	//�ַ���������
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