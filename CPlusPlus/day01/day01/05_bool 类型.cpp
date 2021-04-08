#include <iostream>
using namespace std;

int main()
{
	bool b1 = true;	// 告诉c++编译器分配一个字节的内存

	bool b2, b3, b4; // 多个变量定义 可能会放在同一个字节中

	cout << "sizeof(bool)=" << sizeof(bool) << endl;

	// bool： 1 或 0
	b1 = 10;
	cout << "bool:" << b1 << endl;
	b1 = 0;
	cout << "bool:" << b1 << endl;

	return 0;
}