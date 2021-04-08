#include <stdio.h>

#define M 15

int main()
{
	int number[M], i, k;

	for (i = 0; i < M; i++)
		scanf_s("%d", &number[i]);

	k = 0;
	for (i = 1; i < M; i++) {
		if (number[k] > number[i]) {
			k = i;
		}
	}
	

	printf("weizhi:%d\nshuzi:%d\n", k + 1, number[k]);

	system("pause");
	return 0;
}
