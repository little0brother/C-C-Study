#include <stdio.h>

char* strCrossCat(char* a, char* b);

int main()
{
	char a[100] = { 0 };
	char b[100] = { 0 };
	char* p;

	printf("�����һ������");
	gets(a);
	printf("����ڶ�������");
	gets(b);

	p = strCrossCat(a, b);

	puts(p);

	system("pause");
	return 0;
}

char* strCrossCat(char* a, char* b)
{
	char c[200] = { 0 };
	int i = 0, j = 0, x;

	x = strlen(a) > strlen(b) ? strlen(a) : strlen(b);

	for (i = 0; i < x; i++) {
		if (*a != '\0') {
			c[j] = *a;
			a++;
			j++;
		}
		if (*b != '\0') {
			c[j] = *b;
			b++;
			j++;
		}
	}
	c[j] = '\0';
	memset(b, '\0', sizeof(b));

	b = c;
	return b;
}