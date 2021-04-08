#include <iostream>
using namespace std;

class Test
{
private:
	int x;
	int y;

public:
	Test(int x = 0, int y = 0)
	{
		this->x = x;
		this->y = y;
	}

	// copy构造函数  完成对象的初始化
	Test(const Test& obj)
	{
		x = obj.x;
		y = obj.y;

		cout << "copy构造函数" << endl;
	}

	~Test()
	{
		cout << "析构" << endl;
	}

	int getX()
	{
		return x;
	}
};

// 返回一个匿名对象
// 结论1：函数返回值是一个元素（复杂类型), 返回的是一个新的匿名对象（所以会调用匿名对象类的copy构造函数）

// 结论2：匿名对象的去和留
// 如果用匿名对象 初始化另外一个同类型的对象，那么匿名对象转成有名对象
// 如果用匿名对象 赋值给另外一个同类型的对象，匿名对象 被析构

Test fun()
{
	Test T(1, 2);

	// 返回时 利用T创建了一个匿名对象 将T的值通过copy构造函数赋给匿名对象
	return T; // 返回一个匿名对象  会调用copy构造函数
}

void playObj()
{
	fun();
}

void playObj2()
{
	// 用匿名对象初始化test 编译器直接把匿名对象转成test，从匿名转化为有名字的, 不会析构fun()函数中的对象
	Test test = fun();
	cout << test.getX() << endl;

	Test test2(1, 2);
	test2 = fun();  // 匿名对象没有转化为新对象 所以析构fun()中的匿名对象
	cout << test2.getX() << endl;
}

int main()
{
	//playObj();

	playObj2();

	return 0;
}