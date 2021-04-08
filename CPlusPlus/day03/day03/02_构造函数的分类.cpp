#include <iostream>
using namespace std;

class Test 
{
private:
	int a;
	int b;

public:
	// 无参构造函数
	Test()
	{
		cout << "无参构造函数" << endl;
	}

	// 有参构造函数
	Test(int a, int b)
	{
		this->a = a;
		this->b = b;

		cout << "有参构造函数" << endl;
	}
	Test(int a)
	{

	}

	// 赋值构造函数(copy构造函数)
	Test(const Test& obj)
	{
		cout << "copy构造函数" << endl;
	}

	void printT()
	{
		cout << "成员函数" << endl;
	}
};

int main()
{
	// 构造函数的调用
	Test t1; // 调用无参构造函数

	// 调用有参构造函数 三种方法
	Test t2_1(1, 2); // 括号法 c++编译器自动调用
	Test t2_2 = (3, 4); // 等号法 c++编译器自动调用  调用的为一个参数的构造函数  ==（t2_2 = 4); 逗号表达式结果为4
	Test t2_3 = Test(1, 2); // 直接调用构造函数 手工调用  (匿名对象)

	Test t3(t1); // 调用copy构造函数

	return 0;
}