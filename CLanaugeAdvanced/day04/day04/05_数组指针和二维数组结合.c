#include <stdio.h>

int main()
{
	int a[][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	// 3个a[4]的一维数组

#if 0
	// 定义一个数组指针变量
	// 指向一维数组的整个数组首地址
	int(*p)[4];
	//p = &a;	// 整个二维数组首地址
	p = a;	// 第0行首地址，p等价于二维数组名

	printf("p = %d\np + 1 = %d\n", p, p + 1);	// 4 * 4 = 16
#endif

	// 定义数组指针类型，再定义变量
	typedef int(*P)[4];
	P p;
	p = a;

	int row = sizeof(a) / sizeof(a[0]);
	int len = sizeof(a[0]) / sizeof(a[0][0]);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < len; j++)
		{
			//printf("%3d ", p[i][j]);
			printf("%3d ", *(*(p + i) + j));
		}
		printf("\n");
	}

	int t[10];
	// 测一维数组长度：sizeof()首行首元素地址
	printf("sizeof(t)=%d, sizeof(&t)=%d\n", sizeof(t), sizeof(&t));

	// int a[3][4]
	printf("sizeof(a[0])=%d, sizeof(&a[0])=%d\n", sizeof(a[0]), sizeof(&a[0]));
	printf("sizeof(*(a+0))=%d, sizeof(a+0)=%d\n", sizeof(*(a+0)), sizeof(a+0));

	return 0;
}