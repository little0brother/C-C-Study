/********************/
/*     2维数组      */
/*******************/

#include <stdio.h>

int main1()
{
	int a[3][4] = { {1, 2, 3, 12}, {4, 5, 6, 11}, {7, 8, 9, 10} };
	int(*p)[4]; //定义数组指针 *p为指向a[],4为二维数组长度

	p = a;

	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%3d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%3d ", *(*(p + i) + j));
		}
		printf("\n");
	}

	// 输出指定行列元素值
	int lin, col;
	do {
		printf("i = ");
		scanf("%d", &lin);
		printf("j = ");
		scanf("%d", &col);
	} while (lin > 3 || col > 4);
	printf("%d", a[lin - 1][col - 1]);

	return 0;
}