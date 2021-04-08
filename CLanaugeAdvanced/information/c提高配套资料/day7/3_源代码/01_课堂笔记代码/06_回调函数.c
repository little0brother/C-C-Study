#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add(int a, int b)
{
	return a + b;
}

//17:11
int minus(int a, int b)
{
	return a - b;
}

//函数的参数是变量，可以是函数指针变量吗？
//框架，固定变量， 17：10
//多态， 多种形态，调用同一接口，不一样表现
void fun(int x, int y,  int(*p)(int a, int b) )
{
	printf("fun11111111\n");

	int a = p(x, y); //回调函数 add(1,2)
	printf("a = %d\n", a);
}

typedef int(*Q)(int a, int b); //函数指针类型
void fun2(int x, int y, Q p)
{
	printf("fun11111111\n");

	int a = p(x, y); //回调函数 add(1,2)
	printf("a = %d\n", a);
}


int main(void)
{
	//fun(1, 2, add);

	fun2(10, 5, minus);

	printf("\n");
	system("pause");
	return 0;
}