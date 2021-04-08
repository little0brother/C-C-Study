#include <iostream>
using namespace std;

class Complex
{
public:
	double a;
	double b;
	char c;
	char d;

	void Input() { cin >> a >> c >> b >> d; }
	Complex operator+(Complex &fushu);
	Complex operator-(Complex &fushu);
	Complex operator*(Complex &fushu);
	Complex operator/(Complex &fushu);
};
Complex Complex::operator+(Complex &fushu)
{
	a += fushu.a;
	b += fushu.b;

	return *this;
}

Complex Complex::operator-(Complex &fushu)
{
	a -= fushu.a;
	b -= fushu.b;

	return *this;
}

Complex Complex::operator*(Complex &fushu)
{
	int temp;
	temp = a * fushu.a - b * fushu.b;
	b = a * fushu.b + b * fushu.a;

	return *this;
}

Complex Complex::operator/(Complex &fushu)
{
	return *this;
}

void Printf(Complex fs)
{
	if (fs.b < 0)
		cout << "result= " << fs.a << fs.b << 'i' << endl;
	else
		cout << "result= " << fs.a << '+' << fs.b << 'i' << endl;
}

int main()
{
	Complex fs1, fs2;
	cout << "输入复数(a+bi/a-bi)：";
	fs1.Input();
	cout << "输入复数(a+bi/a-bi)：";
	fs2.Input();

	char fh;
	cout << "选择计算类型(+ or - or * or /)：";
	cin >> fh;

	if (fs1.c == '-') { fs1.b = 0 - fs1.b; }
	if (fs2.c == '-') { fs2.b = 0 - fs2.b; }

	Complex fs;
	if (fh == '+')
		fs = fs1 + fs2;
	if (fh == '-')
		fs = fs1 - fs2;
	if (fh == '*')
		fs = fs1 * fs2;
	if (fh == '/')
		fs = fs1 / fs2;

	Printf(fs);

	system("pause");
}