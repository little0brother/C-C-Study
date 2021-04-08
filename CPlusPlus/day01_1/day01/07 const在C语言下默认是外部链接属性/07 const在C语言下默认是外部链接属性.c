#include <stdio.h>

void test01()
{
	extern const int m_A;
	printf("a = %d\n", m_A);
}

int main()
{
	test01();

	return 0;
}