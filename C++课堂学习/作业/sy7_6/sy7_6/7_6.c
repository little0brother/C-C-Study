#include <stdio.h>

int main()
{
	int i, k = 0;
	char a[80], b[80], *p;

	p = a;
	gets(p);

	while (*p)
	{
		for (i = 1; *p; p++, k++, i++) {
			if (i % 3 == 0)
			{
				b[k] = '*';
				k++;
			}
			b[k] = *p;
		}
	}
	b[k] = '\0';
	puts(b);

	system("pause");
	return 0;
}