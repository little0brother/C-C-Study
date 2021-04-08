#include <iostream>
using namespace std;

#define PI 3.14159
enum Color {Red, Yellow, Green, Withe};

class Circle
{
private:
	float radius;
public:
	Circle(float r) { radius = r; cout << "Circle initlized" << endl; }
	~Circle() { cout << "Circle destoryed" << endl; }

	float Area() { return PI * radius * radius; }
};

class Table
{
private:
	float hight;
public:
	Table(float h) { hight = h; cout << "Table initlized" << endl; }
	~Table() { cout << "Table destoryed" << endl; }

	float High() { return hight; }
};

class RoundTable : public Circle, public Table
{
private:
	Color color;
public:
	RoundTable(float r, float h, Color c) : Circle(r), Table(h) { color = c; cout << "RoundTable initlized" << endl; }
	~RoundTable() { cout << "RoundTable destoryed" << endl; }

	int Getcolor() { return color; }
};

int main() 
{
	RoundTable obj(2, 3, Red);

	cout << obj.Area() << endl;
	cout << obj.High() << endl;
	cout << obj.Getcolor() << endl;

	system("pause");
	return 0;
}