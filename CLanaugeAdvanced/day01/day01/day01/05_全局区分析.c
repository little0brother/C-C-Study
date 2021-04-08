#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	字符串存在文字常量区即全局区，不会进行释放，并且字符串相同的话，指针会指向同一地址即内容相同。
*/

char* get_str1()
{
	char* p = "abcdefg";	// 文字常量区

	return p;
}

char* get_str2()
{
	char* q = "abcdefg";	// 文字常量区

	return q;
}


int main(void)
{
	char* p = NULL;
	char* q = NULL;

	p = get_str1();
	// %s: 指针指向内存区域的内容
	// %d: 打印p本身的值
	printf("p = %s, p = %d\n", p, p);

	q = get_str2();
	printf("q = %s, q = %d\n", q, q);

	printf("\n");
	return 0;
}