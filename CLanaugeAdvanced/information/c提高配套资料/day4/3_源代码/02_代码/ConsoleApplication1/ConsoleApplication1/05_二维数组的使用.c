#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main01(void)
{
	int a1[3][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12}
	}; 

	int a2[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

	int a3[][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", a3[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	//+16
	//��ά���������������0�е��׵�ַ�������ڵ�0����Ԫ�ص�ַ����Ȼֵһ����
	//���ǲ�����һ��
	printf("a:%d, a+1:%d\n", a3, a3+1); 
	printf("%d�� %d\n", *(a3 + 0), *(a3 + 0)+1); //��0����Ԫ�ص�ַ
	printf("%d, %d\n", a3[0], a3[0]+1);

	int a[][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	// a : �����0���׵�ַ
	// a+i   ->  &a[i] : �����i���׵�ַ
	// *(a+i) -> a[i] : �����0����Ԫ�ص�ַ
	// *(a+i)+j  -> &a[i][j]: ��i�е�j��Ԫ�صĵ�ַ
	// *(*(a+i)+j) -> a[i][j] = ��i�е�j��Ԫ�ص�ֵ


	printf("\n");
	system("pause");
	return 0;
}

void printA(int *a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main02(void)
{
	int a[][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

	printA((int *)a, sizeof(a)/sizeof(a[0][0]) );

	printf("\n");
	system("pause");
	return 0;
}

int main03(void)
{
	int a[][10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	//3�� a[4]��һά����

#if 0
	//��������ָ�����
	//ָ��һά��������������׵�ַ
	int(*p)[10]; 
	//p = &a; //������ά�����׵�ַ p = a;
	p = a; //��0���׵�ַ, p�ȼ��ڶ�ά������
	printf("p:%d, p+1:%d\n", p, p+1); //10 * 4= 40
#endif

	//��������ָ�����ͣ��ٶ������
	typedef int(*P)[10];
	P p;
	p = a;

	int i = 0;
	int j = 0;
	int n = sizeof(a) / sizeof(a[0]);
	int nj = sizeof(a[0]) / sizeof(a[0][0]);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < nj; j++)
		{
			//printf("%d ", p[i][j]);
			printf("%d ", *( *(p+i)+j ) );

		}
		printf("\n");
	}


	int t[10];
	//��һά���鳤�ȣ� sizeof()������Ԫ�ص�ַ
	printf("sizeof(t)= %d, sizeof(&t) %d\n", sizeof(t), sizeof(&t) );

	//int a[2][10]
	printf("sizeof(a[0]):%d, sizeof(&a[0]):%d\n", sizeof(a[0]), sizeof(&a[0]) );
	printf("sizeof( *(a+0) ):%d, sizeof( a+0):%d\n", sizeof( *(a+0) ), sizeof( a+0));


	printf("\n");
	system("pause");
	return 0;
}

//�������βζ����˻�Ϊָ�룬ָ�벽����һ��һ��
void printArray(int a[3][4])//5k
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	printf("\n");
}

//a +1, һ�У� 4 * 4 = 16
void printArray2(int a[][4])//7k
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	printf("\n");
}

//ָ�벽����һ���� a+1: 4
void printArray3(int **a)//-7k
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	printf("\n");
}

//����ָ��
void printArray4(int (*a)[4])//9k
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	printf("\n");
}

//����ָ������
typedef int(*P)[4];

void printArray5(P a)//9k
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	printf("\n");
}

int main(void)
{
	int a[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

	printArray5(a);

	printf("\n");
	system("pause");
	return 0;
}