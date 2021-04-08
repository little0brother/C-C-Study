#include <stdio.h>

int main()
{
	int *q, n = 0, i, j, m = 0;
	char str[50] = { 0 };
	int a[50] = { 0 };
	char *p, *cp;
	gets(str);
	p = str;
	q = a;

	while (*p != '\0') {
		if (*p > '0' && *p < '9') {
			while (*p > '0' && *p < '9') {
				p++;
				n++;
			}
		}
		else {
			while(*p < '0' || *p > '9')
			p++;
		}
		cp = p;

		if (n >= 2) {
			p -= n;

			while (n > 0) {
				*q = (*q * 10) + (*p - '0');
				p++;
				n--;
			}
			q++;
			p = cp;
		}
	}
	j = q - a;

	for (i = 0; i < j; i++)
		printf("%d\t", a[i]);
	printf("\n");

	system("pause");
	return 0;
}