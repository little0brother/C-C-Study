#include <stdio.h>
#define  N   10

int main()
{
	int a[N + 4] = { 0 };
	int i, j, k;

	for (i = 0; i < N; i++)
		scanf_s("%d", &a[i]);

	for (i = 0; i < N - 1; i++)
	{
		k = i;
		for (j = i + 1; j < N; j++)
		{
			if (a[k] < a[j]) 
				k = j;	
		}

		if (k != i)
		{
			a[N + 3] = a[i];
			a[i] = a[k];
			a[k] = a[N + 3];
		}
	}

	for (i = 0; i < N; i++)
		printf("%4d", a[i]);
	printf("\n");

	scanf_s("%d", &a[N + 2]);

	for (i = 0; i < N; i++)
	{
		if (a[N + 2] > a[i])
		{
			k = i;
			break;
		}
	}
	
	for (i = N + 1; i > k; i--)
		a[i] = a[i - 1];

	a[k] = a[N + 2];

	for (i = 0; i < N + 1; i++)
		printf("%4d", a[i]);

	system("pause");
	return 0;
}