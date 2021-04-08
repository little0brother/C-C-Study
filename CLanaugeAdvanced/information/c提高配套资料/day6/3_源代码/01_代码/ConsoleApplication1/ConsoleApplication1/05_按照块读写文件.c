#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stu
{
	char name[50];
	int id;
}Stu;

void my_fwrite(char *path)
{
	FILE *fp = NULL;
	//��д��ʽ�򿪣�����ļ������ڣ�����
	fp = fopen(path, "w+");
	if (fp == NULL)
	{
		perror("my_fwrite fopen");
		return;
	}

	Stu s[3];
	int i = 0;
	char buf[50];
	for (i = 0; i < 3; i++)
	{
		sprintf(buf, "stu%d%d%d", i, i, i);
		strcpy(s[i].name, buf);

		s[i].id = i + 1;
	}

	//д�ļ�������ķ�ʽд
	//s, д���ļ����ݵ��ڴ��׵�ַ
	//sizeof(Stu), �����ݵĴ�С
	//3, ������ д�ļ����ݵĴ�С sizeof(Stu) *3
	//fp, �ļ�ָ��
	//����ֵ���ɹ�д���ļ��Ŀ���Ŀ
	int ret = fwrite(s, sizeof(Stu), 3, fp);
	printf("ret = %d\n", ret);

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

void my_fread(char *path)
{
	FILE *fp = NULL;
	//��д��ʽ�򿪣�����ļ������ڣ���ʧ��
	fp = fopen(path, "r+");
	if (fp == NULL)
	{
		perror("my_fwrite fopen");
		return;
	}

	Stu s[3];
	

	//���ļ�������ķ�ʽ��
	//s, ���ļ����ݵ��׵�ַ
	//sizeof(Stu), �����ݵĴ�С
	//3, ������ ���ļ����ݵĴ�С sizeof(Stu) *3
	//fp, �ļ�ָ��
	//����ֵ���ɹ���ȡ�ļ����ݵĿ���Ŀ
	int ret = fread(s, sizeof(Stu), 3, fp);
	printf("ret = %d\n", ret);

	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("s === %s, %d\n", s[i].name, s[i].id);
	}

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

int main(void)
{
	my_fwrite("../05.txt");
	my_fread("../05.txt");



	printf("\n");
	system("pause");
	return 0;
}