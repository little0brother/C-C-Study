#include <iostream>
using namespace std;

// 若不填写参数则默认 填写参数使用填写的参数
// 有默认值的参数 必须位于无默认值参数的后方
void myPrint(int m, int x = 3, int y = 4 /*int m /err*/)
{
	cout << "x = " << x << endl;
}

int main1()
{
	//myPrint();
	myPrint(4);

	return 0;
}

/////////////////////////////////
// 函数占位参数

// 函数调用时必须写够参数个数
void fun(int a, int b, int)
{
	cout << "a = " << a << "b = " << b << endl;
}

int main2()
{
	//fun(1, 2);  //err

	fun(1, 2, 3);

	return 0;
}

/////////////////////////////////////
// 默认参数和占位参数一起

void fun2(int a, int b, int = 0)
{
	cout << "a = " << a << " b = " << b << endl;
}

int main()
{
	fun2(1, 2);
	fun2(1, 2, 3);

	return 0;
}