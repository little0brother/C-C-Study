#include <stdio.h>

#define PI 3.14

#define TEST(a, b) (a)*(b)

// 比较两个数大小
#define COMP(a, b) (a)>(b)?(a):(b)
// 比较三个数大小
#define COMP3(a, b, c) (a) > (COMP(b, c)) ? (a) : (COMP(b, c))

void fun2()
{
	//int a = A;	// err 因为 A 在下方定义
}

void fun()
{

#define A 10	// 定义了宏定义，下面的代码都可以用，作用域为全局
	int i = 10;

}

void test()
{
	int a = A;	// ok
	//int j = i;  // err

	// 取消宏定义
#undef A
	//int b = A; // err
}

int main()
{
	int r = 10;

	printf("%lf\n", PI * r * r);

	int a = TEST(1, 2);
	a = TEST(1 + 1, 2);		// a = 1+1*2	加上括号可避免
	printf("a = %d\n", a);

	printf("%d\n", COMP(1, 2));
	printf("%d\n", COMP3(2, 5, 1));		// 括号不能必须要给每个变量加 否则进行展开时会出现问题
	// 1, 2, 3   1 > 2 > 3

	return 0;
}