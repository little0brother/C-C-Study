#include <iostream>
using namespace std;

int main()
{
	float sum = 0;
	int high;
	cout << "输入最大界限:";
	cin >> high;

	int i = 1;
	while (i <= high)
	{
		sum += 1.0 / i;
		i++;
	}
	cout << sum;

	system("pause");
}