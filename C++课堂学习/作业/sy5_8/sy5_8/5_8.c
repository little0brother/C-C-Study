#include <stdio.h>
#define M 2
#define N 3

int main()
{
	int a[M][N] = { 0 }, b[M][N] = { 0 }, c[M][N] = { 0 };
	int i, j;

	printf("����A�����е�ֵ��\n");
	for(i = 0; i < M; i++)
		for(j = 0; j < N; j++)
			scanf_s("%d", &a[i][j]);

	printf("����B�����е�ֵ��\n");
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			scanf_s("%d", &b[i][j]);

	printf("������֮��Ϊ��\n");
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
			printf("%d\t", c[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}