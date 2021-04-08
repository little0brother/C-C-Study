#include <stdio.h>
#include <stdlib.h>

void fun2(int *p)
{
	p = 0xaabb;
	printf("fun2: p=*p\n", p);
}

void fun3(int** p)
{
	*p = 0xeeff;
}

// 二级指针间接赋值
int main(void)
{
	//// 一个变量，应该定义一个怎样类型的指针保存它的地址
	//// 在原来类型基础上加一个*
	//int a = 10;
	//int* p = &a;
	//int** q = &p;

	//int******** t = NULL;
	//int********* t2 = &t;

	int* p = 0x1122;
	printf("p1 = %p\n", p);

	fun2(p);		// 值传递
	printf("p2 = %p\n", p);

	fun3(&p);		// 地址传递
	printf("p3 = %p\n", p);

	printf("\n");
	return 0;
}


#if(0)
int get_a()
{
	int a = 10;

	return a;
}

void get_a2(int b)
{
	b = 22;
}

void get_a3(int* p)
{
	*p = 22;	// 通过*操作内存
}

void get_a4(int* a1, int *a2, int* a3, int *a4)
{
	*a1 = 1;
	*a2 = 2;
	*a3 = 3;
	*a4 = 4;
}

int main(void)
{
	/* 通过指针间接赋值条件
	*  1. 两个变量
	*  2. 建立关系：指针指向谁，就把谁的地址赋给指针
	*  3. 通过*操作内存
	*/

	int a = 100;		
	int* p = NULL;
	p = &a;
	*p = 2;


	int b = get_a();
	printf("b ===== %d\n", b);

	get_a2(b);
	printf("b2 ==== %d\n", b);

	// 如果想通过形参改变实参的内存内容（值），必须地址传递
	// 实参，形参 两个变量
	get_a3(&b);		// 在函数调用时，建立关系
	printf("b3 ==== %d\n", b);

	int a1, a2, a3, a4;
	get_a4(&a1, &a2, &a3, &a4);
	printf("a1 = %d, a2 = %d, a3 = %d, a4 = %d\n", a1, a2, a3, a4);

	printf("\n");
	return 0;
}
#endif