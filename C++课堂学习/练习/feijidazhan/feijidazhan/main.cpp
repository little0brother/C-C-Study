#include <iostream>
#define uint unsigned int
#define uchar unsigned char

using namespace std;

void main()
{
	int P1;
	//	P1 = 0xe7;
	uint a, b;
	a = 0xe;  b = 0x7;

	a -= 1;
	a << 4;
	P1 = a + b;

	cout << P1 << endl;
}