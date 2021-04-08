#include <stdio.h>

int sum(int x[], int i1, int i2)
{
	int i, s = 0;
	for (i = i1 - 1; i < i2; i++)
	{
		s = s + x[i];
	}
	return s;
}

int main()
{
	int i, i1, i2, result;
	int x[10];

	for (i = 0; i < 10; i++)
	{
		printf("x[%d] = ", i);
		scanf_s("%d", &x[i]);
	}
	printf("Input i1 amg i2:");
	scanf_s("%d%d", &i1, &i2);

	result = sum(x, i1, i2);
	printf("Sum = %d\n", result);

	system("pause");
	return 0;
}