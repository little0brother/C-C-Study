#include <stdio.h>
#include <string.h>

typedef struct Stu
{
	char name[50];
	int id;
}Stu;

void my_fwrite(char* path)
{
	FILE* fp = NULL;

	// �ļ��򿪲���������ļ��������򴴽�
	fp = fopen(path, "w+");
	if (fp == NULL)
	{
		perror("my_fwrite fopen");
		return;
	}

	Stu s[3];
	char buf[50];
	for (int i = 0; i < 3; i++)
	{
		sprintf(buf, "stu%d%d", i, i);
		strcpy(s[i].name, buf);

		s[i].id = i + 10;
	}

	// д�ļ�, ���鷽ʽд
	// ����1��д���ļ����ݵ��ڴ��׵�ַ
	// ����2��д�����ݿ����ݵĴ�С
	// ����3��������д�ļ����ݵĴ�С = 3 * sizeof(Stu)
	// ����4���ļ�ָ��
	// ����ֵ���ɹ�д���ļ��Ŀ���Ŀ
	int ret = fwrite(s, sizeof(Stu), 3, fp);
	printf("[my_fread] ret = %d\n", ret);

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

void my_fread(char* path)
{
	FILE* fp = NULL;

	// �Զ��ķ�ʽ���ļ�������ļ����������ʧ��
	fp = fopen(path, "r+");
	if (fp == NULL)
	{
		perror("my_fread fopen:");
	}

	Stu s[3];

	// ���ļ�, ���鷽ʽд
	// ����1�����ļ����ݵ��׵�ַ
	// ����2�������ݿ����ݵĴ�С
	// ����3�����������ļ����ݵĴ�С = 3 * sizeof(Stu)
	// ����4���ļ�ָ��
	// ����ֵ���ɹ���ȡ�ļ����ݵĿ���Ŀ
	int ret = fread(s, sizeof(Stu), 3, fp);
	printf("[my_fread] ret = %d\n", ret);

	for (int i = 0; i < 3; i++)
	{
		printf("id=%d, name=%s\n", s[i].id, s[i].name);
	}

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

int main()
{
	my_fwrite("../05.txt");
	my_fread("../05.txt");

	return 0;
}