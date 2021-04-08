#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	// 栈地址的生长方向
	int a;
	int b;
	printf("a = %d, b = %d\n", &a, &b);


	int buf[100];
	printf("buf: %d, buf+1: %d\n", buf, buf + 1);

	printf("\n");
	return 0;
}