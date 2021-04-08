#include <stdio.h>

int main()
{
	char str[50] = { 0 };
	int n = 1;
	char* p;
	gets(str);
	p = str;

	while (*p++) 
		if (*p == ',')
			n++;
	
	p -= 2;
	if (*p == ',')
		n--;

	printf("µ¥´Ê¸öÊı£º%d\n", n);

	system("pause");
	return 0;
}