#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main01(void)
{
	char *p0 = NULL; 
	p0 = (char *)malloc(100);
	strcpy(p0, "agdsgds");

	//10��char *�� ÿһ����ֵ���ǿ�
	int i = 0;
	char *p[10] = { 0 };
	for (i = 0; i < 10; i++)
	{
		p[i] = malloc(100);
		strcpy(p[i], "agdsg");
	}

	int a[10];
	int *q = (int *)malloc(10 * sizeof(int)); //q[10]


	//��̬����һ�����飬ÿ��Ԫ�ض���char *
	//char *ch[10]
	int n = 3;
	char **buf = (char **)malloc(n * sizeof(char *)); //char *buf[3]
	if (buf == NULL)
	{
		return -1;
	}
	for (i = 0; i < n; i++)
	{
		buf[i] = (char *)malloc(30 * sizeof(char));
		char str[30];
		sprintf(str, "test%d%d", i, i);
		strcpy(buf[i], str);
	}

	for (i = 0; i < n; i++)
	{
		printf("%s, ", buf[i]);
	}
	printf("\n");

	for (i = 0; i < n; i++)
	{
		free(buf[i]);
		buf[i] = NULL;
	}

	if (buf != NULL)
	{
		free(buf);
		buf = NULL;
	}







	printf("\n");
	system("pause");
	return 0;
}

char **getMem(int n)
{
	int i = 0;
	char **buf = (char **)malloc(n * sizeof(char *)); //char *buf[3]
	if (buf == NULL)
	{
		return NULL;
	}
	for (i = 0; i < n; i++)
	{
		buf[i] = (char *)malloc(30 * sizeof(char));
		char str[30];
		sprintf(str, "test%d%d", i, i);
		strcpy(buf[i], str);
	}

	return buf;
}

void print_buf(char **buf, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%s, ", buf[i]);
	}
	printf("\n");
}


void free_buf(char **buf, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		free(buf[i]);
		buf[i] = NULL;
	}

	if (buf != NULL)
	{
		free(buf);
		buf = NULL;
	}

}


int main(void)
{
	char **buf = NULL;
	int n = 3;

	buf = getMem(n);
	if (buf == NULL)
	{
		printf("getMem err\n");
		return -1;
	}

	print_buf(buf, n);

	free_buf(buf, n);
	buf = NULL;

	printf("\n");
	system("pause");
	return 0;
}