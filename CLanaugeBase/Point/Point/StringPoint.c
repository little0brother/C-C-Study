/**************/
/*  字符指针   */
/**************/

#include <stdio.h>

void coprstr()
{

}

int main2()
{
	char str[] = "hello world", str2[20], str3[20];
	char *p1, *p2, *temp1, *temp2;
	int i, j;

	// 数组方法进行复制
	for (i = 0; *(str + i) != '\0'; i++)
		*(str2 + i) = *(str + i);
	*(str2 + i) = '\0';

	printf("str = %s\n", str);
	printf("str2= %s\n\n", str2);

	// 指针方法执行复制
	p1 = str;
	p2 = str3;
	for (j = 0; *p1 != '\0'; p1++, p2++, j++)
		*p2 = *p1;
	*p2 = '\0';

	printf("str = %s\n", *p1);
	printf("str3= %s\n", str3);

	return 0;
}