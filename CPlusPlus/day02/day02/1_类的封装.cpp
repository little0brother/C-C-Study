#include <iostream>
using namespace std;

// 封装有2层含义
// 1. 把属性和方法进行封装
// 2. 对属性和方法进行访问控制

//类的访问控制关键字修饰的成员变量和成员函数(属性默认private)
// public: 可以在类的内部和类的外部访问
// private: 只能在类的内部被访问，不能在类的外部访问
// protected: 只能在类的内部被访问，不能在类的外部访问，用于继承
class MyCircle
{
public:
	double m_r;	 // 属性
	double m_s;

public:
	// 成员函数
	double getR()
	{
		return m_r;
	}

	void setR(double r)
	{
		m_r = r;
	}

	double getS()
	{
		m_s = 3.14 * m_r * m_r;
		return m_s;
	}
};

// 属性默认属性为public
struct MyStruct
{
	int a;
	int b;

	void fun();
};

// 类封装了成员变量和成员函数  通过类的指针可以调用类的成员函数
void printCircle1(MyCircle *pC)
{
	cout << pC->getR() << endl;
	cout << pC->getS() << endl;
}

void printCircle2(MyCircle& myc)
{
	cout << myc.getR() << endl;
	cout << myc.getS() << endl;
}

void printCircle3(MyCircle myc)
{
	cout << myc.getR() << endl;
	cout << myc.getS() << endl;
}

int main()
{
	MyCircle c1, c2;

	c1.setR(10);
	cout << "c1.s: " << c1.getS() << endl;

	// 引用
	printCircle1(&c1);

	c1.setR(20);
	printCircle1(&c1);

	printCircle2(c1);

	return 0;
}