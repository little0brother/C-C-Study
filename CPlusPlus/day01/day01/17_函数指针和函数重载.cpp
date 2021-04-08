#include <iostream>
using namespace std;

void myfun(int a)
{
	cout << a << endl;
}

void myfun(char* a)
{
	cout << a << endl;
}

void myfun(int a, int b)
{
	cout << a << endl;
}

void myfun(int a, float b)
{
	cout << a << endl;
}

// 函数指针的基础语法
// 声明一个函数类型 
typedef void (myTypeFunc)(int a, int b);
//myTypeFunc* myfunp = NULL;  // 定义一个函数指针 这个指针指向函数的入口地址

// 声明一个函数指针类型  
typedef void (*myPTypeFunc)(int a, int b); // 声明了一个指针的数据类型
//myPTypeFunc myfunp = NULL;  // 通过函数指针类型定义了一个函数指针

// 声明一个函数指针变量
void (*myVarPFunc)(int a, int b);

int main()
{
	myPTypeFunc fp;   // 定义了一个函数指针变量

	fp = myfun;  // 将重载函数的函数入口地址赋给fp  只能匹配参数列表为两个参数的函数 因为函数指针为两个参数

	fp(1, 2);
	fp(1, 2.0);

	return 0;
}