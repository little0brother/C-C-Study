/*-------------------------------------------------------
������Ĵ�
---------------------------------------------------------

��Ŀ�����и��������к���fun�Ĺ����ǣ�
���㺯��F(x��y��z)��(x��y)/(x��y)��(z��y)/(z��y)��ֵ��
����x��y��ֵ����ȣ�z��y��ֵ����ȡ�

���磺��x��ֵΪ9��y��ֵΪ11��z��ֵΪ15ʱ������ֵΪ-3.50��

-------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/***********FOUND***********/
#define FU(m,n) (m)/(n)

float fun(float a, float b, float c)
{
	float  value;
	value = FU(a + b, a - b) + FU(c + b, c - b);
	/***********FOUND***********/
	return (value);
}
main()
{
	float  x, y, z, sum;
	printf("Input  x  y  z:  ");
	scanf_s("%f%f%f", &x, &y, &z);
	printf("x=%f,y=%f,z=%f\n", x, y, z);
	if (x == y || y == z)
	{
		printf("Data error!\n");
		exit(0);
	}
	sum = fun(x, y, z);
	printf("The result is : %5.2f\n", sum);
	system("pause");
}

