/*-------------------------------------------------------
��������ա�
---------------------------------------------------------

���ܣ����溯��Ϊ���ַ�����keyֵ��������Ԫ���ѵ�������
���ҵ�key�򷵻ض�Ӧ���±꣬���򷵻�-1��

-------------------------------------------------------*/
#include <stdio.h>
fun(int a[], int n, int key)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	/***********SPACE***********/
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key<a[mid])
			/***********SPACE***********/
			high = mid - 1;
		else if (key>a[mid])
			/***********SPACE***********/
			low = mid + 1;
		else
			/***********SPACE***********/
			return mid;
	}
	return -1;
}
main()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int b, c;
	b = 4;
	c = fun(a, 10, b);
	if (c == 1)
		printf("not found");
	else
		printf("position %d\n", c);
	system("pause");
}
