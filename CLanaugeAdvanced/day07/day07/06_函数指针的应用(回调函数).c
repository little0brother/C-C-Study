#include <stdio.h>
#include <string.h>

int add(int a, int b)
{
	return a + b;
}

int minus(int a, int b)
{
	return a - b;
}

// 函数的参数是变量, 可以是函数指针变量吗？
// 框架，固定变量，17：10
// 多态，多种形态，调用同一接口，不一样的表现
void fun(int x, int y, int(*p)(int a, int b))
{
	printf("fun1111111\n");

	int a = p(x, y); // 回调函数 add(1, 2) minus(10, 5);
	printf("a = %d\n", a);
}

typedef int(*Q)(int a, int b);  // 函数指针类型
void fun1(int x, int y, Q p)
{
	printf("fun1111111\n");

	int a = p(x, y); // 回调函数 add(1, 2) minus(10, 5);
	printf("a = %d\n", a);
}

int main()
{
	fun(1, 2, add);

	fun(10, 5, minus);

	fun1(2, 1, minus);

	return 0;
}