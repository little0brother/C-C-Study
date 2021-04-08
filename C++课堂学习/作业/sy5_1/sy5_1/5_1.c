#include <stdio.h>

int main()
{
	int n = 10, i, sum = 0;
	int a[10];

	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", &a[i]);
		sum = sum + a[i];
	}
	printf("sum = %d\n", sum);

	system("pause");
	return 0;
}