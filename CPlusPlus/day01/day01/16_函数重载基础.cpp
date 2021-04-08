// 函数重载: 函数名相同 参数列表不同(1.参数类型不同  2.参数个数不同  3.参数顺序不同)
// 返回值不能作为函数重载的标准

#include <iostream>
using namespace std;

void myPrint(int a)
{
	cout << a << endl;
}

void myPrint(string a)
{
	cout << a << endl;
}

void myPrint(int a, int b)
{
	cout << a << b << endl;
}

int main1()
{
	// 重载函数的调用
	myPrint(1);
	myPrint("12");
	myPrint(2, 3);

	return 0;
}

////////////////////////////////////////////////////////////////////
// 函数默认参数和函数重载在一起

void myfunc(int a, int b, int c = 0)
{
	cout << a << b << c << endl;
}

void myfunc(int a, int b)
{
	cout << a << b << endl;
}

int main()
{
	//myfunc(1, 2);   //err 函数调用时会产生二义性

	return 0;
}