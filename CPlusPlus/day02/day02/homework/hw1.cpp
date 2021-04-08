/*
1）定义一个Point类，其属性包括点的坐标，提供计算两点之间距离的方法；
2）定义一个圆形类，其属性包括圆心和半径；
3）创建两个圆形对象，提示用户输入圆心坐标和半径，判断两个圆是否相交，并输出结果。
*/

#include <iostream>
using namespace std;

class Point
{
public:
	int x;
	int y;

public:
	float ditance(Point& d);
};

float Point::ditance(Point& d)
{
	float dd = sqrt((d.x - x) * (d.x - x) + (d.y - y) * (d.y - y));

	return dd;
}

class Circle
{
private:
	Point p;
	int r;
public:
	int getX() { return p.x; }
	int getY() { return p.y; }
	void setX(int x) { p.x = x; }
	void setY(int y) { p.y = y; }
	void setR(int r) { this->r = r; }

	bool judgeCross(Circle& c);
};

bool Circle::judgeCross(Circle& c)
{
	float dist = p.ditance(c.p);
	float r2r = r + c.r;

	if (dist > r2r)
	{
		return false;
	}
	else
	{
		return true;
	}
	
}

int main()
{
	Circle c1;
	Circle c2;

	c1.setX(1);
	c1.setY(1);
	c1.setR(3);

	c2.setX(10);
	c2.setY(10);
	c2.setR(3);

	cout << "两圆形是否相交: ";
	if (c1.judgeCross(c2))
	{
		cout << "相交！" << endl;
	}
	else
	{
		cout << "不相交！" << endl;
	}

	return 0;
}