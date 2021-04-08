#include <stdio.h>

// 详细解释，看对应文档

// 内存对齐方式 按照结构体变量(字节长度)sizeof最长的变量进行对齐
// 结构体嵌套，原理相似，按照两个结构体变量中(字节长度)sizeof最长的进行对齐

// 如果使用 #pragma pack(2) 指定对齐长度
// 那么如果字符(字节长度)siezof超过指定对齐长度，那么就要以指定的对齐长度进行计算
// 例：
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
		a: 4 * 0 = 0	// 偏移位置
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
		b: 8 * 0 = 0	// 偏移位置
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
