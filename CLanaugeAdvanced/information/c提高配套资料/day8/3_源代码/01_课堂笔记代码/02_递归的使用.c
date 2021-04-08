#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fun(int a)
{
	if (a == 1)
	{
		printf("a == %d\n", a);
		return; //中断函数很重要
	}

	fun(a - 1);


	printf("a = %d\n", a);
}

int add(int n)
{
	if (n == 100)
	{
		return n;
	}

	return n + add(n+1);
}

int add2(int n)
{
	if (n == 1)
	{
		return n;
	}

	return n + add2(n - 1);
}


int main(void)
{
	
	//fun(3);

	int i = 0;
	int n = 100;
	int sum = 0;
	for (i = 0; i <= n; i++)
	{
		sum += i;
	}

	printf("%d\n", sum);


	//printf("%d\n", add(1) );
	printf("%d\n", add2(100));



	printf("\n");
	system("pause");
	return 0;
}
