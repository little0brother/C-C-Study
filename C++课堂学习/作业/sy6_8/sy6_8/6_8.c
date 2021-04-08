#include <stdio.h>

int i = 0;

int* EJZ(int x)
{
	static int a[50] = { 0 };
	const int TOW = 2;

	while (x > 0)
	{
		a[i] = x % TOW;
		x /= TOW;
		i++;
	}
	return &a[0];
}

int main()
{
	int x;
	int *p = 0;

	scanf_s("%d", &x);
	p = EJZ(x);

	for (i -= 1; i >= 0; i--)
		printf("%d", p[i]);

	system("pause");
	return 0;
}
