#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* getA()
{
	static int a = 10;		// ��̬���������ȫ�����������ͷ�

	return &a;
}

int main(void)
{
	int* p;
	p = getA();

	printf("%d", *p);

	printf("\n");
	return 0;
}