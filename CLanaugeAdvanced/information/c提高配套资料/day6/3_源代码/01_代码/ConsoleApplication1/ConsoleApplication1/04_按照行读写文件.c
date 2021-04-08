#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void my_fputs(char *path)
{
	FILE *fp = NULL;

	//"w+", д����ʽ�򿪣�����ļ������ڣ��򴴽�
	//                     ����ļ����ڣ�������ݣ���д
	fp = fopen(path, "w+");
	if (fp == NULL)
	{
		//�ַ���
		perror("my_fputs fopen");
		return;
	}

	//д�ļ�
	char *buf[] = { "123456\n", "bbbbbbbbbb\n", "ccccccccccc\n" };
	int i = 0;
	int n = 3;
	for (i = 0; i < n; i++)
	{
		//����ֵ���ɹ�, ��ʧ�ܣ� �ɹ���0�� ʧ�ܷ�0
		int len = fputs(buf[i], fp);
		printf("len = %d\n", len);

	}

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}

}

void my_fgets(char *path)
{
	FILE *fp = NULL;
	//��д��ʽ�򿪣�����ļ������ڣ���ʧ��
	fp = fopen(path, "r+");
	if (fp == NULL)
	{
		perror("my_fgets fopen");
		return;
	}

	char buf[100];

	while (!feof(fp)) //�ļ�û�н���
	{
		//sizeof(buf), ���ֵ���Ų��£�ֻ�ܷ�100�� ��������ʵ�ʴ�С���
		//����ֵ���ɹ���ȡ�ļ�����
		//�ѡ�\n�����ȡ���ԡ�\n����Ϊ���еı�־
		//fgets()��ȡ��Ϻ��Զ����ַ���������0
		//memset(buf, 'a', sizeof(buf));
		char *p = fgets(buf, sizeof(buf), fp);
		if (p != NULL)
		{
			printf("buf = %s", buf);
			printf("p = %s", p);
		}
	
	}
	printf("\n");

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

int main(void)
{
	my_fputs("../04.txt");
	my_fgets("../04.txt");

	printf("\n");
	system("pause");
	return 0;
}