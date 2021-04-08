#include <stdio.h>

// ��ϸ���ͣ�����Ӧ�ĵ�

// �ڴ���뷽ʽ ���սṹ�����(�ֽڳ���)sizeof��ı������ж���
// �ṹ��Ƕ�ף�ԭ�����ƣ����������ṹ�������(�ֽڳ���)sizeof��Ľ��ж���

// ���ʹ�� #pragma pack(2) ָ�����볤��
// ��ô����ַ�(�ֽڳ���)siezof����ָ�����볤�ȣ���ô��Ҫ��ָ���Ķ��볤�Ƚ��м���
// ����
/*
	#pragma pack(2)
	struct
	{
		int a;
		double b;
		short c;
		char d;
	}D;

	a: 2 * 0 = 0;
	b: 2 * 2 = 4;
	c: 2 * 6 = 12;
	d: 1 * 12 = 12;

	a a
	a a
	b b
	b b
	b b
	b b
	c c
	d *
*/

//#pragma pack(2)
int main()
{
	struct
	{
		int a;
		short b;
	}A;
	/*
		a: 4 * 0 = 0
	*/
	printf("%d\n", sizeof(A));

	struct
	{
		int a;
		double b;
		short c;
	}B;
	/*
		a: 4 * 0 = 0	// ƫ��λ��
		b: 8 * 1 = 8
		c: 2 * 8 = 16

		a a a a * * * *
		b b b b b b b b
		c c * * * * * * 
	*/
	printf("%d\n", sizeof(B));

	struct
	{
		double b;
		int a;
		short c;
	}C;
	/*
		b: 8 * 0 = 0	// ƫ��λ��
		a: 4 * 2 = 8
		c: 2 * 6 = 12

		b b b b b b b b
		a a a a c c * *
	*/
	printf("%d\n", sizeof(C));

	//struct
	//{
	//	int a;
	//	double b;
	//	short c;
	//	char d;
	//}D;
	//printf("%d\n", sizeof(D));

	return 0;
}
