#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x;
	printf("input a number : ");
	scanf_s("%d", &x);

	if (huiwen(x))
		printf("%d是回文数。\n", x);
	else
		printf("%d不是回文。\n", x);

	system("pause");
	return 0;
}

int huiwen(int x)
{
	int b = 0, i;
	i = x;

	while (x > 0)
	{
		b = b * 10 + x % 10;
		x /= 10;
	}

	if (b == i)
		return 1;
	else
		return 0;

}