#include <stdio.h>
#include <stdlib.h>

void draw(int m, int n, char c);

int main()
{
	int i;

	for (i = 1; i <= 7; ++i)
		draw(7 - i, 2 * i - 1, i);
	for (i = 6; i >= 1; --i)
		draw(7 - i, 2 * i - 1, i);

	system("pause");
	return 0;
}

void draw(int m, int n, char c)
{
	int j;

	for (j = 0; j < m; ++j)
		printf(" ");
	for (j = 0; j < n; ++j)
		printf("%d", c);

	printf("\n");
}