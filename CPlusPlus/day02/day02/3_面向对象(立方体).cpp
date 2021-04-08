#include <iostream>
using namespace std;

class Rectangle
{
private:
	int length;
	int width;
	int height;

public:
	//Rectangle(int length, int width, int height);
	void setLength(int length);
	void setWidth(int width);
	void setHeight(int height);
	void setAll(int length = 0, int width = 0, int height = 0);

	int getLength();
	int getWidth();
	int getHeigth();

	int getV();
	int getS();

	// 判断两个立方体是否相同
	bool judgeCube(Rectangle rec1, Rectangle rec2);
	bool judgeCube(Rectangle& rec);
};

//Rectangle::Rectangle(int length, int width, int height)
//{
//	this->length = length;
//	this->width = width;
//	this->height = height;
//}

void Rectangle::setLength(int length)
{
	this->length = length;
}

void Rectangle::setWidth(int width)
{
	this->width = width;
}

void Rectangle::setHeight(int height)
{
	this->height = height;
}

void Rectangle::setAll(int length, int width, int height)
{
	this->length = length;
	this->width = width;
	this->height = height;
}

int Rectangle::getV()
{
	return length * width * height;
}

int Rectangle::getS()
{
	return 2 * (length * width + length * height + width * height);
}

// 存在冗余 不合理
bool Rectangle::judgeCube(Rectangle rec1, Rectangle rec2)
{
	if (rec1.width == rec2.width && rec1.length == rec2.length && rec1.height == rec2.height)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Rectangle::judgeCube(Rectangle& rec)
{
	// width属性属于rec1 因为是通过rec1来调用此成员函数
	if (width == rec.width && height == rec.height && length == rec.length)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	Rectangle rec;
	rec.setAll(1, 2, 3);

	cout << "V:" << rec.getV() << endl;
	cout << "S:" << rec.getS() << endl;

	Rectangle rec2;
	rec2.setAll(2, 3, 4);


	// 调用类的成员函数
	// 产生冗余  rec.judgeCube(rec, rec2)
	/*
	if (rec.judgeCube(rec, rec2))
	{
		cout << "两立方体相等" << endl;
	}
	else
	{
		cout << "两立方体不相等" << endl;
	}
	*/

	// 无冗余方法  rec.judgeCube2(rec1);
	rec.judgeCube(rec2); // 调用rec1对象类的成员函数
	if (rec.judgeCube(rec2))
	{
		cout << "两立方体相等" << endl;
	}
	else
	{
		cout << "两立方体不相等" << endl;
	}

	return 0;
}