//设计并测试一个名为Rectangle的矩形类，其属性为矩形的左下角与右上角两个点的坐标，根据坐标能计算出矩形的面积

#include <iostream>
using namespace std;

class Rectangle
{
private:
	int rx;
	int ry;
	int lx;
	int ly;

public:
	Rectangle(int lx, int ly, int rx, int ry)
	{
		this->rx = rx;
		this->ry = ry;
		this->lx = lx;
		this->ly = ly;
	}

	float calArea();
};

float Rectangle::calArea()
{
	float width = abs(rx - lx);
	float height = abs(ly - ry);

	return width * height;
}

int main()
{
	Rectangle rec(1, 1, 4, 4);

	cout << "矩形面积为: " << rec.calArea() << endl;

	return 0;
}