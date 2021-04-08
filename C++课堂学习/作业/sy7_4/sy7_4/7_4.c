#include<stdio.h>

int main(void)
{
	int a[8], *p;
	int i, j, t, k;

	p = a;
	printf("Input the number:");
	for (i = 0; i < 8; i++)
		scanf_s("%d", p + i);

	t = *p;
	for (i = 0; i < 8; i++) {

		for (j = i; j < 8; j++)
			if (j == i || *(p + j) < t)
			{
				t = *(p + j);
				k = j;
			}

		if (k != i)
		{
			t = *(p + k);
			*(p + k) = *(p + i);
			*(p + i) = t;

		}
	}
	for (i = 0; i < 8; i++)
		printf("%5d", *(p + i));

	system("pause");
}