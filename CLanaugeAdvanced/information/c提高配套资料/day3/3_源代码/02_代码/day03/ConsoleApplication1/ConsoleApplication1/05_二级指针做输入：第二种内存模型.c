#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main01(void)
{
	char a0[30] = "22222222222";
	char a1[30] = "11111111111";
	char a2[30] = "bbbbbbbbbbb";
	char a3[30] = "aaaaaaaaaaaa";

	//4��a[30]��һά���飬��ά����
	//�����ά���飬��д��һ��[]ֵ������, ����Ҫ��ʼ��
	//a�������е�ַ�����е�ַ��������Ԫ�ص�ַ�����𣬵������ǵ�ֵ��һ��
	//���𣺲�����һ��
	char a[][30] = { "22222222222", "11111111111", "bbbbbbbbbbb", "aaaaaaaaaaaa" };
	printf("a:%d, a+1: %d\n", a, a+1);

	char b[30];
	printf("&b:%d, &b+1:%d\n", &b, &b+1);
	printf("b:%d, b+1:%d\n", b, b+1);

	int n = sizeof(a) / sizeof(a[0]);
	printf("n = %d\n", n);


	//a[0] = "22222222222"
	int i = 0; 
	for (i = 0; i < 4; i++)
	{
		printf("%s\n",a[i]); //���е�ַ����������Ԫ�ص�ַ��ֵ��һ��
		// a+i, *(a+i)
	}



	printf("\n");
	system("pause");
	return 0;
}

void print_array_err(char **a, int n)
{
	printf("a: %d, a+1:%d\n", a, a+1);
	int i = 0;
	for (i = 0; i < n; i++)
	{
		//printf("%s\n", a[i]); //���е�ַ����������Ԫ�ص�ַ��ֵ��һ��
		// a+i, *(a+i)
	}
}

void print_array(char a[][30], int n)
{
	//printf("a: %d, a+1:%d\n", a, a + 1);
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%s, ", a[i]); //���е�ַ����������Ԫ�ص�ַ��ֵ��һ��

	}
	printf("\n");
}

void sort_array(char a[][30], int n)
{
	int i = 0;
	int j = 0;
	char tmp[30];

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(a[i], a[j])> 0)
			{
				//�������ڴ��
				strcpy(tmp, a[i]);
				strcpy(a[i], a[j]);
				strcpy(a[j], tmp);
			}
		}
	}

}

int main(void)
{
	char a[][30] = { "22222222222", "11111111111", "bbbbbbbbbbb", "aaaaaaaaaaaa" };
	int n = sizeof(a) / sizeof(a[0]);

	printf("before sort:\n");
	print_array(a, n);

	sort_array(a, n);

	printf("\nafter sort:\n");
	print_array(a, n);

	printf("\n");
	system("pause");
	return 0;
}