#include <stdio.h>

int main01()
{
	int a6[3][4] = { {1, 2, 3, 4},
					{5, 6, 7, 8},
					{9, 10, 11, 12}};

	int a2[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

	int a3[][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", a3[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	// ��ά���������������0�е��׵�ַ�������0����Ԫ�ص�ַ����Ȼֵһ�������ǲ�����ͬ��
	printf("a:%d, a+1:%d\n", a3, a3 + 1);	//+16

	printf("*a:%d, *a+1:%d\n", *(a3 + 0), *(a3 + 0) + 1); //��0����Ԫ��

	printf("%d, %d\n", a3[0], a3[0] + 1);


	int a[][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	// a: ���������׵�ַ
	// a+i -> &a[i]: �����i���׵�ַ
	// *(a+i) -> a[i]: �����i����Ԫ�ص�ַ
	// *(a+i)+j -> &a[i][j]: �����i�е�j��Ԫ�ص�ַ
	// *(*(a+j)+j) -> a[i][j]: ��i�е�j��Ԫ�ص�ֵ

	printf("\n");
	return 0;
}

void printA(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	int a[][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

	printf("n = %d\n", sizeof(a) / 4);
	printA((int*)a, sizeof(a) / sizeof(int));

	return 0;
}