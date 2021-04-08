#include <stdio.h>

int* hh(char* n)
{
	char* p;
	p = n;
	printf("1 %s\n", p);
	p += 2;
	printf("2 %s\n", p);

	return n;
}

int main100()
{
	char* p;
	char nn[] = "hello world!";

	printf("3 %s\n", hh(nn));
}