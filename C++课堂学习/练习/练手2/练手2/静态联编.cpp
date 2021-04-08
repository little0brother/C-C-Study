//#include <iostream>
//using namespace std;
//
//class Point
//{
//	double x, y;
//public:
//	Point(double x1, double y1):x(x1), y(y1) {}
//	virtual double area() { return 0; }
//};
//
//class Circle :public Point
//{
//	double r;
//public:
//	Circle(double x1, double y1, double r1):Point(x1, y1), r(r1) {}
//	double area() { return 3.14 * r * r; }
//};
//
//int main()
//{
//	Point p(3.1, 3.1);
//	Circle c(2, 2, 1);
//	cout << "Point area=" << p.area() << endl;
//	cout << "Circle area=" << c.area() << endl;
//
//	Point *pc = &p;
//	cout << "Circle area=" << pc->area() << endl;
//	pc = &c;
//	cout << "circle area=" << pc->area() << endl;
//
//	system("pause");
//	return 0;
//}

#include <iostream>
using namespace std;

class Base
{
public:
	virtual void printf() { cout << "Base" << endl; }
};

class Derived : public Base
{
public:
	virtual void printf() { cout << "Derived" << endl; }
};

void display(Base *p, void(Base::*pf)())
{
	p->printf();
}

int main()
{
	Derived d;
	Base b;
	display(&d, &Base::printf); //Êä³öDerived
	display(&b, &Base::printf); //Êä³öBase

	system("pause");
}