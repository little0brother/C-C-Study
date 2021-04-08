#include <iostream>
#include <math.h>
using namespace std;

class Dot
{
private:
	int x;
	int y;

public:
	void setDot(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	int getX()
	{
		return x;
	}

	int getY()
	{
		return y;
	}
};

class Circle
{
private:
	int r;
	int x;
	int y;
	
public:
	void setCircle(int r, int x, int y)
	{
		this->r = r;
		this->x = x;
		this->y = y;
	}

	bool judge(Dot& d)
	{
		int dis = sqrt((d.getX() - x) * (d.getX() - x) + (d.getY() - y) * (d.getY() - y));

		if(dis <= r)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	Circle c;
	c.setCircle(2, 1, 1);

	Dot d;
	d.setDot(2, 5);

	// 判断点是否在圆内
	bool flag = c.judge(d);
	if (flag)
	{
		cout << "在圆内" << endl;
	}
	else
	{
		cout << "在圆外" << endl;
	}

	return 0;
}