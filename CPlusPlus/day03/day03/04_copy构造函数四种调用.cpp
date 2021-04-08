#include <iostream>
using namespace std;

// copy构造函数：用一个对象去初始化另外一个对象

class Test
{
private:
	int a;
	int b;

public:
	// 有参构造函数
	Test(int a, int b)
	{
		this->a = a;
		this->b = b;

		cout << "有参构造函数" << endl;
	}

	// 赋值构造函数(copy构造函数)
	Test(const Test& obj)
	{
		cout << "copy构造函数" << endl;
	}

};

int main()
{
	Test t0(1, 2);
	Test t1(1, 2);

	t0 = t1;  // 赋值操作 用t0给t1赋值   初始化与赋值是两个不同的概念

	// 1 copy构造函数的第一种调用方法
	Test t2 = t1;  // 用t1初始化t2

	// 2
	Test t3(t1);


	return 0;
}