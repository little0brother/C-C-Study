#include <stdio.h>

#if(0)
int main()
{
	fputc('a', stdout);		// stdout -> ��Ļ(��ӡ��ͨ��Ϣ��

	char ch;
	ch = fgetc(stdin);		// stdin -> ����
	printf("ch = %c\n", ch);

	//fprintf(stderr, "%c", ch);		// stderr -> ��Ļ����ӡ������Ϣ��
	fputc(ch, stdout);

	return 0;
}
#endif

#if(1)

void my_fputc(char* path)
{
	FILE* fp = NULL;

	// "w+", д����ʽ�򿪣�����ļ������ڣ��򴴽��� ����ļ����ڣ�������ݣ���д��
	fp = fopen(path, "w+");
	if (fp == NULL)
	{
		perror("my_fputc fopen");
		return;
	}

	// д�ļ�
	char buf[] = "this is a test for fputc";
	int n = strlen(buf);
	for (int i = 0; i < n; i++)
	{
		fputc(buf[i], fp);		// ����ֵΪ���ɹ�д����ַ�
	}

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

void my_fgetc(char* path)
{
	FILE* fp = NULL;

	// ��д��ʽ�򿪣�����ļ������ڣ���ʧ��
	fp = fopen(path, "r+");
	if (fp == NULL)
	{
		perror("my_fgetc fopen");
	}

	char ch;
#if 0
	// ����һ
	while ((ch = fgetc(fp)) != EOF)		// fgetc�ķ���ֵΪ ��ȡ�����ַ�
	{
		printf("%c", ch);
	}
	printf("\n");
#endif
#if 1
	// ������
	while ( !feof(fp) )		// �ж��ļ��Ƿ����
	{
		ch = fgetc(fp);
		printf("%c", ch);
	}
	printf("\n");
#endif

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

int main()
{
	//my_fputc("../03.txt");
	my_fgetc("../03.txt");

	return 0;
}
#endif