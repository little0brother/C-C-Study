/* ѡ������ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if(0)
int main01()
{
	int a[] = { 10, 4, 5, 6 ,7, 8 ,9, 4 };
	int n;
	int i, j, temp;

	n = sizeof(a) / sizeof(a[0]);		// ���Ԫ�ظ���

	printf("����ǰ\n");
	for ( i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");


	// ѡ������

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])		// ����
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

	printf("�����\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");


	// ��ο������㷨�ĳ���
	/*
		1.����
		2.ÿ����书��
		3.����
		4.����
		5.ģ�¸�
		6.��������д
	*/

	printf("\n");
	return 0;
}
#endif


// ���������Ϊ���������������β��˻�Ϊָ��
//void print_array(int a[10], int n)
//void print_array(int a[], int n)
void print_array(int *a, int n)
{
	// a������ָ�����ã�ָ�����ͣ�32λ�������ĸ��ֽ�
	n = sizeof(a) / sizeof(a[0]);		// ���Ԫ�ظ���
	printf("print_array n = %d\n", n);

	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void sort_array(int* a, int n)
{
	int i, j, temp;

	// ѡ������
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])		// ����
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

int main()
{
	int a[] = { 10, 4, 5, 6 ,7, 8 ,9, 4 };
	int n;
	int i, j, temp;

	n = sizeof(a) / sizeof(a[0]);		// ���Ԫ�ظ���
	printf("n = %d\n", n);

	printf("����ǰ\n");
	print_array(a, n);

	sort_array(a, n);

	printf("�����\n");
	print_array(a, n);

	printf("\n");
	return 0;
}