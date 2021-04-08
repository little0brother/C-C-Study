#include <stdio.h>

int main()
{
	char a[100] = { 0 };
	 int b[100] = { 0 }, i = 0, j = 0;
	char *p;
	 int *q;

	gets(a);
	p = a;
	q = b;
	
	while (*p != '\0') {
		if (*p >= '0' && *p <= '9') {
			*(q + i) = *p - '0';
			i++;
		}
		*p++;
	}

	for (j = 0; j < i; j++)
		printf("%d", *(q + j));
	printf("\n");
	
	system("pause");
	return 0;
}