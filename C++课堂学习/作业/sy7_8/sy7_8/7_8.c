#include <stdio.h>

char* f(char* str);

int main()
{
	char a[100] = { 0 };
	char *p, *q;
	int i;
	gets(a);

	p = f(a);
	q = f(p);
	puts(q);

	system("pause");
	return 0;
}

char* f(char* str)
{
	int i = 0;
	static char b[100] = { 0 };

	while (*str != '\0') {
		if (*str >= 'a' && *str <= 'z') {
			if (*str >= 'x' && *str <= 'z')
				b[i] = *str - 55;
			else
				b[i] = *str - 29;
		}
		else if (*str >= 'A' && *str <= 'Z') {
			if (*str >= 'A' && *str <= 'C')
				b[i] = *str + 55;
			else
				b[i] = *str + 29;
		}
		else
			b[i] = *str;

		str++;
		i++;
	}

	return &b[0];
}