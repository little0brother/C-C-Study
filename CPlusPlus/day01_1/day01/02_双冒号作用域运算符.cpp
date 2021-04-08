#include <iostream>
using namespace std;

int atk = 1000;

void test()
{
	int atk = 2000;
	cout << "局部攻击力为：" << atk << endl;

	// :: 作用域运算符 当::前面没有任何作用域的情况下，代表使用全局作用域
	cout << "全局攻击力为：" << ::atk << endl;
}

int main()
{
	test();

	return EXIT_SUCCESS;
}