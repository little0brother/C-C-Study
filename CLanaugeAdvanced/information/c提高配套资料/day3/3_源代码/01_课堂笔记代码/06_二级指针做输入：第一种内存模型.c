#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main01(void)
{

	//ÿ�����Ͷ���char *
	char *p0 = "111111111";
	//printf("%s\n", p0);
	char *p1 = "000000000";
	char *p2 = "bbbbbbbbb";
	char *p3 = "aaaaaaaaa";

	//ָ�����飬ָ������飬����һ�����飬ÿһ��Ԫ�ض���ָ��char *
	char *p[] = { "111111111", "000000000", "bbbbbbbbb", "aaaaaaaaa" };
	//p[0] = "111111111"
	int n = sizeof(p) / sizeof(p[0]);
	printf("sizeof(p) = %d, sizeof(p[0]) = %d\n", sizeof(p), sizeof(p[0]));

	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%s\n", p[i]);
	}

	char *q[10] = { "111111111", "000000000", "bbbbbbbbb", "aaaaaaaaa" };
	printf("sizeof(q) = %d, sizeof(q[0]) = %d\n", sizeof(q), sizeof(q[0]));



	printf("\n");
	system("pause");
	return 0;
}

int main02(void)
{
	//ָ�����飬ָ������飬����һ�����飬ÿһ��Ԫ�ض���ָ��char *
	char *p[] = { "111111111", "000000000", "bbbbbbbbb", "aaaaaaaaa" };
	//char **q = { "111111111", "000000000", "bbbbbbbbb", "aaaaaaaaa" }; //err
	//p[0] = "111111111"
	int n = sizeof(p) / sizeof(p[0]);
	int i = 0;
	int j = 0;
	char *tmp = NULL;

	printf("����ǰ��\n");
	for (i = 0; i < n; i++)
	{
		printf("%s, ", p[i]);
	}
	printf("\n");

	//ѡ������
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(p[i], p[j]) > 0)
			{
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}

	printf("\n�����\n");
	for (i = 0; i < n; i++)
	{
		printf("%s, ", p[i]);
	}
	printf("\n");


	printf("\n");
	system("pause");
	return 0;
}

void test(int a[])
//void test(int *a)
{

}

void fun()
{
	int a[10];
	test(a);


}

//void print_array(char *p[], int n)
void print_array(char **p, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%s, ", p[i]);
	}
	printf("\n");
}

void sort_array(char **p, int n)
{
	int i, j;
	char *tmp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(p[i], p[j]) > 0)
			{
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}
}

int main(void)
{
	//ָ�����飬ָ������飬����һ�����飬ÿһ��Ԫ�ض���ָ��char *
	char *p[] = { "111111111", "000000000", "bbbbbbbbb", "aaaaaaaaa" };
	//char **q = { "111111111", "000000000", "bbbbbbbbb", "aaaaaaaaa" }; //err
	//p[0] = "111111111"
	int n = sizeof(p) / sizeof(p[0]);

	printf("����ǰ:\n");
	print_array(p, n);

	sort_array(p, n);

	printf("\n�����:\n");
	print_array(p, n);


	printf("\n");
	system("pause");
	return 0;
}