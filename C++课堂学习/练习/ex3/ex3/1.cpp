#include <iostream>
using namespace std;

class zhengfang
{
public:
	double a;

	double bianchang() {
		return 4 * a;
	}

	zhengfang(double x) {
		a = x;
	}
};

int main()
{
	zhengfang obj[3] = { zhengfang(2), zhengfang(3), zhengfang(4) };

	for (int i = 0; i < 3; i++)
	{
		cout << obj[i].a << "\t";
		cout << obj[i].bianchang() << endl;
	}

	system("pause");
	return 0;
}