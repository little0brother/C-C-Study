/*
1������һ��Point�࣬�����԰���������꣬�ṩ��������֮�����ķ�����
2������һ��Բ���࣬�����԰���Բ�ĺͰ뾶��
3����������Բ�ζ�����ʾ�û�����Բ������Ͱ뾶���ж�����Բ�Ƿ��ཻ������������
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

	cout << "��Բ���Ƿ��ཻ: ";
	if (c1.judgeCross(c2))
	{
		cout << "�ཻ��" << endl;
	}
	else
	{
		cout << "���ཻ��" << endl;
	}

	return 0;
}