#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  MAX2(a, b) (a) > (b) ? (a) : (b)
#define MAX3(a, b, c) (a) > ( MAX2(b, c) ) ? (a) : ( MAX2(b, c) )
// 1, 2, 3 

#define  PI   3.14

#define TEST(a, b)   (a)*(b)
void fun2()
{
	//int a = A; //err
}

void fun()
{

#define A 10 //定义了宏定义，下面的代码都可以用，类似于全局变量
	int i = 10;

}

void test()
{
	int a = A; //ok
	//int j = i; //err

	//取消宏定义
#undef A
	//int b = A; //err


}

int main(void)
{
	int r = 10;

	printf("%lf\n", PI*r*r);
	//printf("%lf\n", 3.14*r*r);

	int a = TEST(1, 2);
	//int a = 1*2
	a = TEST(1 + 1, 2); // 2 * 2
	//a = 1+1*2 = 3
	printf("a = %d\n", a);

	printf("%d\n", MAX2(1, 2) );
	printf("%d\n", MAX3(1, 2, 3));
	//


	printf("\n");
	system("pause");
	return 0;
}