#include <stdio.h>

int main()
{
	char a[10] = "wel", b[] = "come";
	int i, n = 0;

	while (! a[n] == '\0')
		n++;

	for (i = 0; b[i] != '\0'; i++)
		a[n + i] = b[i];
		a[n + i] = '\0';

	printf("%s\n", a);

	system("pause");
	return 0;
}