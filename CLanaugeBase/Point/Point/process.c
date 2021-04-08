/*****************************/
/* 用指向函数的指针做函数参数 **/
/* 设计函数process，在调用时，*/
/* 每次实现不同功能(类似多态) */
/****************************/

/* 输入两个数，第一次调用process时找出大者， 第二次找出小者，第三次求和*/

#include <stdio.h>

int main4()
{
	int compare2max(int, int);
	int compare2min(int, int);
	int add(int, int);

	// 声明直线函数的函数指针，int(*fun)()根据传入函数进行判断调用哪一个函数
	void process(int, int, int(*fun)());

	int a, b;

	printf("Enter a and b:");
	scanf("%d %d", &a, &b);
	
	printf("max = ");
	process(a, b, compare2max);		// 将compare2max为指针传入process函数中，通过指针判断调用哪一个函数

	printf("min = ");
	process(a, b, compare2min);

	printf("sum = ");
	process(a, b, add);

	return 0;
}

int compare2max(int a, int b)
{
	int c;
	return c = a > b ? a : b;
}

int compare2min(int a, int b)
{
	int c;
	return c = a < b ? a : b;
}

int add(int a, int b)
{
	int sum;
	return sum = a + b;
}

void process(int a, int b, int(*fun)())
{
	// 通过传入的参数确定函数指针， 调用函数计算
	printf("%d\n", (*fun)(a, b));
}