#include <iostream>
using namespace std;

class Fraction
{
private:
	int nume, deno;  //分子nume 分母deno
	void simplify(); //简化分数
public:
	Fraction(int n = 0, int d = 1) : nume(n),deno(d) { simplify(); } //初始化构造函数
	Fraction(double d);		//将double类型转化为分数形式
	Fraction(const string &str);	//将string类型转化为分数形式
	Fraction(const Fraction &f) : nume(f.nume), deno(f.deno){}	//复制构造函数
	void display();

	Fraction& operator -=(const Fraction &b);
	Fraction& operator +=(const Fraction &b);
	friend ostream& operator << (ostream &os, const Fraction &a);
	friend istream& operator >> (istream &is, Fraction &a);
};

Fraction::Fraction(const string &str) : nume(0), deno(1)	//将字符串“1/2”转换为分数
{
	char buf[20];
	int i = str.find('/'), j = str.length() - i - 1;
	if (i >= 0)
	{
		str.copy(buf, i, 0);
		buf[i] = 0;
		nume = atoi(buf); //将前面字串转换为分子

		str.copy(buf, j, i + 1);
		buf[j] = 0;
		deno = atoi(buf); //将后面字符串转化为分母
	}

	simplify();
}

Fraction::Fraction(double d) : nume(d), deno(1) //分子初始化为d的整数部分
{
	d = d - nume;	//取出d的小数部分	 
	while (int(d * 10) != 0)	//将0.25 -> 25/100
	{
		nume = nume * 10 + int(d * 10);
		deno = deno * 10;
		d = d * 10 - int(d * 10);
	}

	simplify();
}

void Fraction::display()
{
	if (deno != 0 && deno != 1 && nume != deno)
		cout << nume << '/' << deno << endl;
	else
		cout << nume << endl;
}

void Fraction::simplify()  //简化分数
{
	int m, n, r, s = 1;	//s为分数符号
	if (nume != 0 && deno != 0)
	{
		if (deno < 0) s = -s, deno = -deno;
		if (nume < 0) s = -s, nume = -nume;

		m = nume, n = deno;

		while (n != 0)
			r = m % n, m = n, n = r;	//球nume和deno最大公约数
		if (m != 0)
			nume = s * nume / m, deno = deno / m;	//分子分母除去公约数
	}
	else
		nume = 0, deno = 1;
}

Fraction& Fraction::operator -=(const Fraction &b)
{
	nume = nume * b.deno + deno * b.nume;
	deno = deno * b.deno;
	simplify();

	return *this;
}

Fraction& Fraction::operator +=(const Fraction &b)
{
	nume = nume * b.deno - deno * b.nume;
	deno = deno * b.deno;
	simplify();

	return *this;
}

ostream& operator << (ostream &os, const Fraction &a)
{
	if (a.deno != 0 && a.deno != 1 && a.nume != a.deno)
		os << a.nume << '/' << a.deno;
	else
		os << a.nume;

	return os;
}

istream& operator >> (istream &is, Fraction &a)
{
	char ch;
	is >> a.nume >> ch >> a.deno;

	return is;
}

int main()
{
	Fraction a(1, 2), b(0.25), c("6/9");

	a.display();
	b.display();
	c.display();

	a -= b;
	a.display();
	b.display();

	Fraction e, f;
	cin >> e >> f;
	cout << "e = " << e << endl;

	system("pause");
	return 0;
}