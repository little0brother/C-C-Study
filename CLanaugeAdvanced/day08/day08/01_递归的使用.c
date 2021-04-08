#include <stdio.h>

void fun(int a)
{
	if (a == 1)
	{
		printf("a == %d\n", a);
		return;		// 中断函数很重要
	}

	fun(a - 1);

	printf("a = %d\n", a);
}

// 递归累加
int add(int n)
{
	if (n < 1)
	{
		return n;
	}

	return n + add(n - 1);
}

int add2(int n)
{
	if (n == 100)
	{
		return n;
	}

	return n + add2(n + 1);
}

int main()
{
	//fun(6);

	//递归计算1-100的和
	int a = add(100);
	printf("add:%d\n", a);
	a = add2(1);
	printf("add2:%d\n", a);

	int n = 100;
	int sum = 0;
	for (int i = 0; i <= 100; i++)
	{
		sum += i;
	}
	printf("sum=%d\n", sum);

	return 0;
}