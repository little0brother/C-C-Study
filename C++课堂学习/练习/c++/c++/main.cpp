#include <iostream>
using namespace std;

class Con
{
private:
	double a;
	double b;
	double c;
	double sum;
public:
	void input();
	void output();
	void change();
};
void Con::input()
{
	cin >> a;
}
void Con::output()
{
	cout << sum << endl;
}
void Con::change()
{
	int d = (int)a;
	int e(0);
	for (int i = 0; a > 1; i++)
	{
		e = d % 2;
		sum += e;
	}
}

int main()
{
	Con ex;

	ex.input();
	ex.change();
	ex.output();

	system("pause");
	return 0;
}