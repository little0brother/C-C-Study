/* 选择排序法 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if(0)
int main01()
{
	int a[] = { 10, 4, 5, 6 ,7, 8 ,9, 4 };
	int n;
	int i, j, temp;

	n = sizeof(a) / sizeof(a[0]);		// 算出元素个数

	printf("排序前\n");
	for ( i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");


	// 选择法排序

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])		// 升序
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

	printf("排序后\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");


	// 如何看懂带算法的程序
	/*
		1.流程
		2.每个语句功能
		3.试数
		4.调试
		5.模仿改
		6.不看代码写
	*/

	printf("\n");
	return 0;
}
#endif


// 如果数组作为函数参数，数组形参退化为指针
//void print_array(int a[10], int n)
//void print_array(int a[], int n)
void print_array(int *a, int n)
{
	// a，当作指针来用，指针类型，32位，长度四个字节
	n = sizeof(a) / sizeof(a[0]);		// 算出元素个数
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

	// 选择排序
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])		// 升序
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

	n = sizeof(a) / sizeof(a[0]);		// 算出元素个数
	printf("n = %d\n", n);

	printf("排序前\n");
	print_array(a, n);

	sort_array(a, n);

	printf("排序后\n");
	print_array(a, n);

	printf("\n");
	return 0;
}