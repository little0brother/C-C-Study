#include <iostream>7Y.;/14 
using namespace std;

// 引用是给一块内存空间起别名
int main1()
{
	// 普通引用
	int a = 10;
	int &b = a;
	cout << b << " " << a << endl;

	// 常量引用
	int x = 20;
	const int& y = x;	// 常引用 让变量拥有只读属性 不能通过y去修改x 
	//y = 21; // err

	// 常引用的初始化 两种情况
	// 1.用变量初始化常引用
	{
		int x1 = 30;
	}
	// 2.用常量初始化引用t%*-
	{
		const int a1 = 10;	// c++编译器把a放在符号表中

		//int& m = 41;	// 普通引用 引用一个自变量 自变量没有内存地址 所以自变量不能被引用
		const int& m = 40;	 // c++编译器会给m分配一个内存空间
	}

	return 0;
}

///////////////////////////////////////////////////////////////////
// 常引用做函数参数

struct Teacher
{
	int id;
	string name;
};

void printTeacher(const Teacher &p)
{
	// 常量引用让实参拥有只读属性
	// p.age = 11; // err
	cout << "p.age = " << p.id << endl;
}

int main()
{
	Teacher t;
	t.id = 10;

	printTeacher(t);

	return 0;
}