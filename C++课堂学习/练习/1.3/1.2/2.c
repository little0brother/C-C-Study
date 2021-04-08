/*-------------------------------------------------------
【程序改错】
---------------------------------------------------------

题目：下列给定程序中fun函数功能是：将n个无序整数从小到大排序。

-------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

fun(int  n, int  *a)
{
	int  i, j, p, t;
	for (j = 0; j<n - 1; j++)
	{
		p = j;
		/***********FOUND***********/
		for (i = j + 1; i<n ; i++)
			if (a[p]>a[i])
				/***********FOUND***********/
				p = i;
		if (p != j)
		{
			t = a[j];
			a[j] = a[p];
			a[p] = t;
		}
	}
}

putarr(int  n, int  *z)
{
	int  i;
	for (i = 1; i <= n; i++, z++)
	{
		printf("%4d", *z);
		if (!(i % 10))
			printf("\n");
	}
	printf("\n");
}
main()
{
	int  aa[20] = { 9,3,0,4,1,2,5,6,8,10,7 }, n = 11;
	printf("\n\nBefore sorting %d numbers:\n", n);
	putarr(n, aa);
	fun(n, aa);
	printf("\nAfter sorting %d numbers:\n", n);
	putarr(n, aa);
	system("pause");
}


