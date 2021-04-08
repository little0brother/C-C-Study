#include <iostream>
using namespace std;

class Fraction
{
private:
	int nume, deno;  //����nume ��ĸdeno
	void simplify(); //�򻯷���
public:
	Fraction(int n = 0, int d = 1) : nume(n),deno(d) { simplify(); } //��ʼ�����캯��
	Fraction(double d);		//��double����ת��Ϊ������ʽ
	Fraction(const string &str);	//��string����ת��Ϊ������ʽ
	Fraction(const Fraction &f) : nume(f.nume), deno(f.deno){}	//���ƹ��캯��
	void display();

	Fraction& operator -=(const Fraction &b);
	Fraction& operator +=(const Fraction &b);
	friend ostream& operator << (ostream &os, const Fraction &a);
	friend istream& operator >> (istream &is, Fraction &a);
};

Fraction::Fraction(const string &str) : nume(0), deno(1)	//���ַ�����1/2��ת��Ϊ����
{
	char buf[20];
	int i = str.find('/'), j = str.length() - i - 1;
	if (i >= 0)
	{
		str.copy(buf, i, 0);
		buf[i] = 0;
		nume = atoi(buf); //��ǰ���ִ�ת��Ϊ����

		str.copy(buf, j, i + 1);
		buf[j] = 0;
		deno = atoi(buf); //�������ַ���ת��Ϊ��ĸ
	}

	simplify();
}

Fraction::Fraction(double d) : nume(d), deno(1) //���ӳ�ʼ��Ϊd����������
{
	d = d - nume;	//ȡ��d��С������	 
	while (int(d * 10) != 0)	//��0.25 -> 25/100
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

void Fraction::simplify()  //�򻯷���
{
	int m, n, r, s = 1;	//sΪ��������
	if (nume != 0 && deno != 0)
	{
		if (deno < 0) s = -s, deno = -deno;
		if (nume < 0) s = -s, nume = -nume;

		m = nume, n = deno;

		while (n != 0)
			r = m % n, m = n, n = r;	//��nume��deno���Լ��
		if (m != 0)
			nume = s * nume / m, deno = deno / m;	//���ӷ�ĸ��ȥ��Լ��
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