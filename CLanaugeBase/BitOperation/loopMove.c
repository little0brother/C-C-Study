/************/
/* 循环移位 */
/************/

#include <stdio.h>

int main5()
{
	unsigned char a, b, c;
	int n;

	printf("输入需要实现循环右移的数字: ");
	scanf("%d", &a);
	printf("输入需要实现右移的位数: ");
	scanf("%d", &n);

	b = a << (sizeof(char) * 8 - n);
	c = a >> n;
	c = c | b;
	printf("结果是: %c\n", c);

	return 0;
}