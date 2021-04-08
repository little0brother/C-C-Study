#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* getA()
{
	static int a = 10;		// 静态变量存放在全局区，不会释放

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