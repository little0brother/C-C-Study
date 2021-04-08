#include <stdio.h>
#define M 10

int* f(int a[]);

int main()
{
	int a[M] = { 0 }, i;

	for (i = 0; i < M; i++)
		scanf_s("%d", &a[i]);

	f(a);

	for (i = 0; i < M; i++)
		printf("%d ", a[i]);
	printf("\n");

	system("pause");
	return 0;
}

int* f(int a[])
{
	int i, j, k, n = 0, b;

	for (i = 0; i < M - 1; i++) {
		k = i;
		for (j = i + 1; j < M; j++) {
			if (a[k] < a[j])
				k = j;
			if (a[k] > a[j])
				n = j;
		}
	}
	b = a[k];
	a[k] = a[n];
	a[n] = b;

	return &a[0];
}