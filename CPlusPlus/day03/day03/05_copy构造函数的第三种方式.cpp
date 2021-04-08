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

// 业务函数
void fun(Test t)
{
	cout << t.getX() << endl;
}

void playObj()
{
	Test t1(1, 2);

	Test t2 = t1;

	Test t3;
	fun(t3);  //*** t3实参去初始化形参t， 会调用copy构造函数
}

int main()
{
	Test t1(1, 2);

	Test t2;
	
	playObj();

	return 0;
}