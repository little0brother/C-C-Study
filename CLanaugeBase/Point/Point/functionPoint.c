/*****************************************/
/* 利用函数指针，比较 a 和 b 的大小，求大值 */
/*****************************************/

#include <stdio.h>

#if(0)
void main3()
{
	int comparemax(int, int);
	int a, b, c;

	scanf("%d %d", &a, &b);

	c = comparemax(a, b);

	printf("a=%d, b=%d, max=%d\n\n", a, b, c);
}
#endif

int comparemax(int a, int b)
{
	int c;
	c = a > b ? a : b;

	return c;
}

#if(1)
void main3()
{
	int comparemax(int, int);
	int (*p)();		// 声明函数指针
	int a, b, c;

	p = comparemax; // 将comparemax()作为首地址，使p指向comparemax
	scanf("%d %d", &a, &b);

	c = (*p)(a, b); // 通过函数指针调用comparemax()函数

	printf("a=%d, b=%d, max=%d\n\n", a, b, c);
}
#endif