#include <stdio.h>

int f(int x);

int main()
{
	int x;
	scanf_s("%d", &x);

	if (f(x))
		printf("  %d是质数。\n", x);
	else
		printf("%d不是质数。\n", x);

	system("pause");
	return 0;
}

int f(int x)
{
	int i;

	if (x == 2) return 1;

	for (i = 2; i < x; i++) {
		if (x % i == 0)
			return 0;
	}

	return 1;
}