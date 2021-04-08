#include <iostream>
using namespace std;
#include "game1.h"
#include "game2.h"

// 1.命名空间的用途：解决命名冲突
void test()
{
	LOL::goAtk();
	kingGlory::goAtk();
}

// 2.命名空间下 可以存放变量、函数、结构体、类....
namespace A
{
	int m_A = 10;
	void func() {};
	struct Person
	{
		int age;
	};

	class Animal
	{
		int age;
	};
}

// 3.命名空间必须声明在 全局作用域下
//void func()
//{
//	// err
//	/*namespace B
//	{
//
//	}*/
//}

// 4.命名空间可以嵌套命名空间
namespace B
{
	int m_A = 10;

	namespace C
	{
		int m_A = 20;
	}
}
void test2()
{
	cout << "B空间下的m_A = " << B::m_A << endl;
	cout << "C空间下的m_A = " << B::C::m_A << endl;
}

// 5.命名空间是卡放的，可以随时向命名空间下添加新的成员
namespace B
{
	int m_B = 100;
}
void test3()
{
	cout << "B空间下的m_A = " << B::m_A << endl;
	cout << "B空间下的m_B = " << B::m_B << endl;
}

// 6.命名空间可以匿名
namespace
{
	int m_C = 100;	// 相当于全局变量
	int m_D = 200;
	// 相当于在变量前加了一个关键字 static
	// static int m_C = 100;
	// static int m_D = 200;
}
void test4()
{
	cout << "m_D = " << ::m_D << endl;
	cout << "m_D = " << m_D << endl;
}

// 7.命名空间可以起别名
namespace veryLongName
{
	int m_A = 1000;
}
void test5()
{
	namespace veryShortName = veryLongName;

	cout << veryShortName::m_A << endl;
	cout << veryLongName::m_A << endl;
}

int main()
{
	//test();
	//test2();
	//test3();
	//test4();
	test5();

	return 0;
}