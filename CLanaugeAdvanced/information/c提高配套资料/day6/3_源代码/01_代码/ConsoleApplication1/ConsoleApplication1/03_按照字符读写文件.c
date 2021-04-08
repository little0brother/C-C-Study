#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main01(void)
{


	fputc('a', stdout); //stdout -> ��Ļ, ��ӡ��ͨ��Ϣ

	char ch;
	ch = fgetc(stdin); //std -> ����
	printf("ch = %c\n", ch);

	//fprintf(stderr, "%c", ch ); //stderr -> ��Ļ�� ������Ϣ
	fputc(ch, stderr);

	printf("\n");
	system("pause");
	return 0;
}

int main02(void)
{
	FILE *fp = NULL;

	//���������ȼ�
	//C:\\Users\\apple\\Documents\\C�����Ƶ\\03.txt��  windows
	//C:/Users/apple/Documents/C�����Ƶ/03.txt��  windows linux

	// "C:\\Users" windows��д��
	// "C:/Users" linux, windows��֧�֣� ����"/"
	
	//���·����/ , 45�ȣ� ./, ../(����), linux, windows
	//vs: �������ʱ��·���������Ŀ����(��ǰ����)
	//ֱ�����п�ִ�г���·������ڳ���
	
	char *p = "1234353454364"\
		"lgkjfdljhlkfdjhlfdjk";
	printf("%s\n", p);
	



	fp = fopen("./03.txt", "r+");
	if (fp == NULL)
	{
		perror("fopen");
		system("pause");
		return -1;
	}

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}

	printf("\n");
	system("pause");
	return 0;
}

void my_fputc(char *path)
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
	char buf[] = "this is a test for fputc";
	int i = 0;
	int n = strlen(buf);
	for (i = 0; i < n; i++)
	{
		//����ֵ���ɹ�д���ļ����ַ�
		int ch = fputc(buf[i], fp);
		printf("ch = %c\n", ch);
	}

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}

}

void my_fgetc(char *path)
{
	FILE *fp = NULL;
	//��д��ʽ�򿪣�����ļ������ڣ���ʧ��
	fp = fopen(path, "r+");
	if (fp == NULL)
	{
		perror("my_fgetc fopen");
		return;
	}

	char ch;
#if 0
	while ( ( ch = fgetc(fp) ) != EOF )
	{
		printf("%c", ch);
	}
	printf("\n");
#endif

	while (!feof(fp)) //�ļ�û�н���
	{
		ch = fgetc(fp);
		printf("%c", ch);
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
	//my_fputc("../03.txt");

	my_fgetc("../03.txt");

	printf("\n");
	system("pause");
	return 0;
}