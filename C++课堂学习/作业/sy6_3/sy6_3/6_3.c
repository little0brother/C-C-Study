#include <stdio.h>

int fun(int n)
{
	static int p = 0;
	p += n;

	return p;
}

int main()
{
	int n, i, f = 0;
	printf("n = ");
	scanf_s("%d", &n);

	for (i = 0; i <= n; i++)
		f = fun(i);

	printf("Sum = %d\n", f);

	system("pause");
	return 0;
}