#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	// 变量本质，一段连续内存空间别名
	// 变量相当于门牌号，内存相当于房间
	int a;
	int* p;

	// 直接赋值
	a = 10;
	printf("a = %d\n", a);

	// 间接赋值
	printf("&a = %d\n", &a);
	p = &a;
	printf(" p = %d\n", p);

	*p = 11;
	printf("a = %d, *p = %d\n", a, *p);

	printf("\n");
	return 0;
}