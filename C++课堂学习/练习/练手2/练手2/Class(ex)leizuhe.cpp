#include <iostream>
using namespace std;

class Circel
{
private:
	double r;

public:
	void Input();
	double CRadius();
	double CLen();
	double CArea();

	Circel();
	Circel(double x);
	Circel(Circel &x);
};

void Circel::Input()
{
	cin >> r;
	while (r < 0) {
		cout << "error!!(num must > zero)";
		cin >> r;
	}
}
double Circel::CRadius()
{
	return r; 
}
double Circel::CLen()
{ 
	return 2 * r; 
}
double Circel::CArea()
{ 
	return r * r; 
}

Circel::Circel()
{
	r = 0; 
}
Circel::Circel(double x)
{
	if (x < 0)
		r = 0;
	else
		r = x;
}
Circel::Circel(Circel &x)
{ 
	r = x.r; 
}


class TriCircle
{
public:
	Circel c0, c1, c2;

	double TLen();
	double TArea();

	TriCircle();
	TriCircle(TriCircle &robj);
	TriCircle(double x0, double x1, double x2);
};

double TriCircle::TLen()
{
	return ( c0.CLen() + c1.CLen() + c2.CLen() );
}
double TriCircle::TArea()
{
	return (c0.CArea() + c1.CArea() + c2.CArea());
}

TriCircle::TriCircle() { }
TriCircle::TriCircle(TriCircle &robj) :c0(robj.c0), c1(robj.c1), c2(robj.c2) { }
TriCircle::TriCircle(double x0, double x1, double x2):c0(x0), c1(x1), c2(x2) { }

int main()
{
	Circel c0(1), c1(2), c2(3);
	TriCircle obj(1 , 2, 3);

	cout << c0.CLen() << endl;
	cout << obj.TLen() << endl;

	system("pause");
	return 0;
}