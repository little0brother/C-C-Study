#include <stdio.h>

#define M 100

int main()
{
	char a[M] = { 0 }, b[27] = { 0 };
	int x = 0, i, j = 0, num, k;

	printf("输入判断字符串的串数:");
	scanf_s("%d", &x);

	for (i = 0; i < x; i++)
	{
		scanf_s("%s", &a);

		while (a[j] != '\0')
		{
			if (x > 'a' && x < 'z')
			{
				num = a[j] - 'a';
				b[num]++;
			}
			j++;
		}

		for (j = 0, k = 0; j < 27; j++)
		{
			if (b[j] < b[j + 1])
				k = j + 1;
		}

		printf("\"%s\"%c:%d", a, a[k], a[k]);
	}
	return 0;
}
