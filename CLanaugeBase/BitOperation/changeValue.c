/**************************************/
/* �����м������������ (�����ڼ����㷨) */
/**************************************/

#include <stdio.h>

int main2()
{
	int a = 3;
	int b = 4;

	printf("Older Value: a=%d, b=%d", a, b);


	// ���������棬���Է���
	a = a ^ b;
	b = b ^ a;
	a = a ^ b;

	printf("\n  New Value: a=%d, b=%d", a, b);

	int c = 3;
	c = c >> -1;
	printf("\nc=%d", c);

	int d = 3;
	d = d << 3;
	printf("\nd=%d", d);

	return 0;
}