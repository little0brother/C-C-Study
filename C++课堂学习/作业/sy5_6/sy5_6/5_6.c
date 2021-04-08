#include <stdio.h>

int main()
{
	int i, a[20], sum = 0, count;
	count = 0;

	for (i = 0; i < 20; i++)
		scanf_s("%d", &a[i]);

	for (i = 0; i < 20; i++)
	{
		if (a[i] < 0)
			continue;

		sum += a[i];
		count++;
	}
	printf("s=%d\t count=%d\n", sum, count);

	system("pause");
	return 0;
}