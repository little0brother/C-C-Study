/***************/
/* ����ð������ */
/***************/

#include <stdio.h>

int max, min;

void sw(int* a, int num)
{
	int i, j, temp;
	for (i = 0; i < num; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			if (a[i] < a[j])
			{
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
}

// ��¼�����Сֵ
void compareMaxMin(int* a, int num)
{
	int i;
	max = min = *a;
	for (i = 0; i < num; i++)
		if (a[i] < min)
			min = a[i];
		else if (a[i] > max)
			max = a[i];
}

int main8()
{
	int arr[100];
	int i = 0, b;
	char ch;

	// �����������֣��Իس���Ϊ������־
	do {
		scanf("%d", &arr[i++]);
	} while (ch = getchar() != '\n');
	b = i;

	compareMaxMin(arr, b);
	sw(arr, b);

	printf("maxValue=%d, minValue=%d\n", max, min);

	printf("Big to small:");
	for (i = 0; i < b; i++)
		printf("%d ", arr[i]);
	printf("\n\n");

	return 0;
}