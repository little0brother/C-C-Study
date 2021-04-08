#include <iostream>
#include <cmath>
#define M 3

using namespace std;

int main()
{
	//const int qw[3] = { 1, 2, 4 };
	int a = 0xe;
	int b = 0x7;
	int c = 0, d = 0, f = 0, j = M - 1, sum;
	double r = 2; int t = 0;

	while (1) {
		a = 0xe;
		b = 0x7;

		//向外扩展
		j = M - 1;
		for (int i = 0; i < M; i++)
		{
			a -= pow(2, i);
			c = a << 4;

			b += pow(2, j--);
			sum = c + b;
			cout << sum << endl;
		}

		//向内收缩
		j = 0;
		for (int i = M - 1; i >= 0; i--)
		{
			a += pow(2, i);
			c = a << 4;

			b -= pow(2, j++);
			sum = c + b;
			cout << sum << endl;
		}
		cout << endl;
	}

	system("pause");
}
/*
	1111 1111

 14	1110 0111 7
 13	1101 1011 11
 11	1011 1101 13
 7	0111 1110 14
*/
/*
	1101 + 1011 = 0110
	1101 << 4 = 1101 0000 + 1011 = 1101 1011
*/