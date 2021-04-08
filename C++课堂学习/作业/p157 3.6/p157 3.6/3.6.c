#include <stdio.h>
#define M 10000

void f();

int main()
{
	f();

	system("pause");
	return 0;
}

void f()
{
	int i, b = 0, x = 0, a = 3, j = 0, n = 0, m = 0;
	int c[500] = { 0 };

	for (a = 3; a < M; a++) 
	{
		for (i = 2, n = 0; i < a; i++)
			if (a % i == 0)
				n++;

		if (n == 0)
		{
			x = a;
			while (x > 0)
			{
				b = b * 10 + x % 10;
				x /= 10;
			}

			for (i = 2, m = 0; i < b; i++)
			{
				if (b % i == 0)
					m++;
			}
			b = 0;

			if (m == 0)
				c[j++] = a;
		}
	}

	for (i = 0; i < j; i++) {
		printf("%d\t", c[i]);

		if ((i + 1) % 6 == 0)
			printf("\n");
	}
}