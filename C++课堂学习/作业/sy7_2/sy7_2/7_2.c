#include<stdio.h>

int* len(char* s)
{
	char *p = s;
	while (*p != '\0')
		*p++;

	return p - s;
}

int main(void)
{
	char s[80];
	gets(s);
	printf("\"%s\"include %d characters .\n", s, len(s));

	system("pause");
	return 0;
}