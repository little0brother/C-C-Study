#include<iostream>
using namespace std;

// 内联函数 用来代替 c语言中 宏定义的代码片段

#define MYFUN(a, b) ((a) > (b) ? (a) : (b))


// 内联函数的函数头必须和函数体在一起 不能做函数声明
inline int myfunc(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int a = 2;
	int b = 3;

	// 编译器直接将函数体插入到函数调用的位置
	myfunc(a, b);
	//{
	//	return a > b ? a : b;
	//}

	cout << MYFUN(a, b) << endl;

	return 0;
}