/*****************/
/* 指向指针的指针 */
/*****************/

#include <stdio.h>

int main7()
{
	char** str[] = { "www.HelloWorld.com", "Hello", "www.Hello.com", "www..com", "HelloWorld" };
	char** p;
	int i;

	for (i = 0; i < 5; i++)
	{
		p = str + i;
		printf("%s\n", *p);
	}

	return 0;
}