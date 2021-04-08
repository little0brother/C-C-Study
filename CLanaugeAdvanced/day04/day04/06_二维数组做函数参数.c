#include <stdio.h>

// 数组做形参都会退化为指针，指针步长不一定一样
// a + 1，一行，4 * 4 = 16
void printArray(int a[][4])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%3d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

// 指针步长不一样
// a + 1 = 4
void printArray2(int **a)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%3d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void printArray3(int (*a)[4])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%3d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
	int a[][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

	printArray3(a);

	return 0;
}