#include <stdio.h>
#define N 10

int main()
{
	int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, k;
	int low = 0, high = N - 1, mid, find = 0;
	printf("������Ԥ���ҵ�ֵ��\n");
	scanf_s("%d", &k);

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (a[mid] == k)
		{
			printf("�ҵ�λ��Ϊ�� %d\n", mid + 1);
			find = 1;
			break;
		}
		if (a[mid] > k)
			--high;
		else
			++low;
	}
	if (! find)
		printf("%dδ�ҵ�\n", k);

	system("pause");
	return 0;
}