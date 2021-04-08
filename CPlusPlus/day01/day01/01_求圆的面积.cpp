#include <iostream>
using namespace std;


// 求圆的面积
// 用面向过程的方法求解元的面积
int main01()
{
	double r = 0;
	double s = 0;

	cout << "请输入圆的半径: ";

	// cin 标准输入
	cin >> r;

	cout << " r = " << r << endl;

	s = 3.14 * r * r;

	cout << "圆的面积: " << s << endl;

	return 0;
}

// 用面向对象的过程求解圆的面积

// 在c++中定义了一个自定义数据类型
struct Circle
{
	double m_r; // 半径
	double m_s; // 面积
};

// 在c++中定义了一个自定义数据类型
class MyCircle
{
private:
	double m_s; // 面积
	double m_r; // 半径 属性 成员变量

public:
	void setR(double r)	//成员函数
	{
		m_r = r;
	}

	double getR()	// 成员函数
	{
		return m_r;
	}

	double getS()
	{
		m_s = 3.14 * m_r * m_r;
		return m_s;
	}
};

// 面向对象
// 1.类的抽象，成员变量和成员函数
// 2.实例化
// 3.求面积
	// 面向过程加工是一个一个的函数 
	// 面向对象加工的是一个一个的类
// 4.mian集成测试

// 思考1: 类的调用 执行过程分析 ---》 类代码不是一步一步执行的
// 类是一个数据类型（固定大小的内存别名), 定义一个类，是一个抽象概念，不会分配内存
// 用数据类型定义一个变量的时候才会分配内存

// 思考2: c++编译器是如何处理多个对象，调用类的成员函数，
int main02()
{
	MyCircle c1, c2, c3; //用类定义对象
	double r;

	cout << "请输入c1圆的半径：";
	cin >> r;

	// 给c1圆形的属性赋值
	c1.setR(r);

	cout << "c1圆的面积是：" << c1.getS() << endl;

	return 0;
}

int main()
{
	MyCircle c1, c2, c3; //用类定义对象
	double r1, r2, r3;

	cout << "请输入c1圆的半径：";
	cin >> r1;
	cout << "请输入c2圆的半径：";
	cin >> r2;
	cout << "请输入c3圆的半径：";
	cin >> r3;

	// 给c1圆形的属性赋值
	c1.setR(r1);
	c2.setR(r2);
	c3.setR(r3);

	cout << "c1圆的面积是：" << c1.getS() << endl;
	cout << "c2圆的面积是：" << c2.getS() << endl;
	cout << "c3圆的面积是：" << c3.getS() << endl;

	return 0;
}