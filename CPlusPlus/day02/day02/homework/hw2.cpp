//��Ʋ�����һ����ΪRectangle�ľ����࣬������Ϊ���ε����½������Ͻ�����������꣬���������ܼ�������ε����

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

	cout << "�������Ϊ: " << rec.calArea() << endl;

	return 0;
}