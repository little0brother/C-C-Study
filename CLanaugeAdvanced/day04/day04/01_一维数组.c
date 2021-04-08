#include <stdio.h>
#include <string.h>

int main(void)
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	// sizeof(); �������ռ�Ŀռ�(��������Ӧ���͵Ŀռ�)

	//int b[]; //err �����Ǳ����ʼ��
	int a1[100] = { 1, 2, 3, 4 };  //û�и�ֵ�Ķ�Ϊ��

	int n = 0;
	// sizeof(a) = 4 * 8 = 32; ��������:��Ԫ�ظ�����Ԫ�����Ͷ�Ӧ int [8]
	// sizeof(a[0]) ��Ԫ�ش�С��ÿ��Ԫ��4���ֽ�
	n = sizeof(a) / sizeof(a[0]);	// n = 8

	for (int i = 0; i < n; i++)
	{
		// *(a+i): �����iԪ�ص�ַ��*(a+i)ָ��ָ����ڴ棨ȡֵ��
		// [] * �ȼ�
		printf("%d ", *(a + i)); 
		printf("%d ", a[i]);
	}
	printf("\n");

	
	// ��������
	// a������Ԫ�ص�ַ
	// &a��������������׵�ַ��������Ԫ�ص�ַһ���ģ��������ǵĲ�����һ��
	printf("a:%d, a+1:%d\n", a, a + 1);			//+4
	printf("&a: %d, &a+1:%d\n", &a, &a + 1);	//+32

	// ��������:��Ԫ�ظ�����Ԫ�����Ͷ�Ӧ int [8]
	// ͨ��typedef����һ����������
	// ��typedef�����ͣ�û�о��Ǳ���
	typedef int A[8];	// ������������,����һ�����ͣ����Ǳ���
	// typedef int (A)[8];

	A b; // int b[8]; ȥ��typedef��b�滻��A��λ��

	for (int i = 0; i < 8; i++)
	{
		b[i] = 2 * i + 1;
	}
	for (int i = 0; i < 8; i++)
	{
		//printf("%d ", b[i]);
		printf("%d ", *(b + i));
	}
	printf("\n");

	printf("b :%d, b+1:%d\n", b, b + 1);
	printf("&b :%d, &b+1:%d\n", &b, &b + 1);


	printf("\n");
	return 0;
}