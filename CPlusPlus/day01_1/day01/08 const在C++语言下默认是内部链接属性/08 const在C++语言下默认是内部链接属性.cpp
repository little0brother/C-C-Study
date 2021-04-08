#include <iostream>
using namespace std;

void test()
{
	extern const int m_B;
	cout << "m_B = " << m_B << endl;
}

int main()
{
	test();

	return 0;
}