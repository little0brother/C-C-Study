#include <stdio.h>

int main()
{
	int a[][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	// 3��a[4]��һά����

#if 0
	// ����һ������ָ�����
	// ָ��һά��������������׵�ַ
	int(*p)[4];
	//p = &a;	// ������ά�����׵�ַ
	p = a;	// ��0���׵�ַ��p�ȼ��ڶ�ά������

	printf("p = %d\np + 1 = %d\n", p, p + 1);	// 4 * 4 = 16
#endif

	// ��������ָ�����ͣ��ٶ������
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
	// ��һά���鳤�ȣ�sizeof()������Ԫ�ص�ַ
	printf("sizeof(t)=%d, sizeof(&t)=%d\n", sizeof(t), sizeof(&t));

	// int a[3][4]
	printf("sizeof(a[0])=%d, sizeof(&a[0])=%d\n", sizeof(a[0]), sizeof(&a[0]));
	printf("sizeof(*(a+0))=%d, sizeof(a+0)=%d\n", sizeof(*(a+0)), sizeof(a+0));

	return 0;
}