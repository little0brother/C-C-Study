#include <iostream>
using namespace std;

// 1. 若返回栈变量 不能成为其他引用的初始值
int getAA1()
{
	int a;
	a = 10;

	return a;
}

// 返回a的内存空间  返回a的一个副本
int& getAA2()
{
	int a;		// 如果是返回栈上的引用 可能会出问题
	a = 10;

	return a;
}

int* getAA3()
{
	int a;
	a = 10;

	return &a;
}

int main1()
{
	int a1 = getAA1();

	int a2 = getAA2();	// 会将返回的具体数值进行存储

	// getAA2()的返回值为一个引用变量， 在此函数运行结束后 会释放原来在函数中申请的内存空间，所以返回的引用没有指向可用的内存空间
	int& a3 = getAA2();  // 会将返回的地址进行存储

	printf("a1:%d, a2:%d, a3:%d\n", a1, a2, a3);
	printf("a1:%d\n", a1);
	printf("a2:%d\n", a2);
	printf("a3:%d\n", a3);

	return 0;
}


// 2.变量是static 或者是全局变量

int j()
{
	static int a = 10;
	a++;

	return a;
}

int& jj()
{
	static int a = 10;
	a++;

	return a;
}

// 若返回静态变量或全局变量
// 可以成为其他引用的初始值
// 即可作为右值使用 也可作为左值使用

int main2()
{
	int a1 = 10;
	int a2 = 10;

	a1 = j();

	a2 = jj();

	int& a3 = jj();

	printf("a1:%d\n", a1);
	printf("a2:%d\n", a2);
	printf("a3:%d\n", a3);

	return 0;
}

/////////////////////////////////////////////////

// 3.函数作左值
int fun()	// 返回变量的值
{
	static int b = 10;

	return b;
}

int& fun1()	 // 返回变量本身（返回变量所指向的内存空间）
{
	static int b = 10;

	printf("b:%d\n", b);

	return b;
}

int main()
{
	//fun() = 100;	 // err
	fun1() = 111;	// 相当于 ==>  b = 100;   函数返回值 是一个引用 并且当左值
	fun1();

	int c = fun1(); // 做右值

	return 0;
}