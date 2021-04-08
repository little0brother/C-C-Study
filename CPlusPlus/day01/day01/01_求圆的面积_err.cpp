#include <iostream>
using namespace std;

class MyCircle
{
public:

	double r;
	
	double pi = 3.1415;
	double area = pi * r * r;	// 这条语句在初始化时就已经执行了，但是当时的r为一个随机值，所以在下方输入为乱码
};

// 能编译通过 但是结果为乱码
int main()
{
	MyCircle c1;
	double r;

	cout << "请输入圆的半径：";
	cin >> c1.r;

	cout << "圆的面积: " << c1.area << endl;		// 这条语句只是从类中拿值，并没有执行上述语句，所以值为初始化时产生的乱码值

	c1.r = 100;
	cout << c1.area << endl;
		
	return 0;
}