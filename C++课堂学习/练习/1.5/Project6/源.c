/*-------------------------------------------------------
【程序设计】
---------------------------------------------------------

题目：从键盘输入10个学生的成绩，统计及格（60分及其60分
以上）的人数。请编fun函数。

-------------------------------------------------------*/
#include "stdio.h"

void wwjt();

int fun(int a[])
{

	/**********Program**********/
	int i, x = 0;
	for (i = 0; i < 10; i++)
		if (a[i] >= 60)
			x++;

	return x;
	/**********  End  **********/

}

void main()
{
	int a[10], i, s;
	for (i = 0; i < 10; i++)
		scanf("%d", &a[i]);
	s = fun(a);
	printf("%d", s);

	wwjt();
}

void wwjt()
{
	FILE *IN, *OUT;
	int iIN[10], i;
	int iOUT, iCOUNT;
	IN = fopen("in.dat", "r");
	if (IN == NULL)
	{
		printf("Please Verify The Currernt Dir..it May Be Changed");
	}
	OUT = fopen("out.dat", "w");
	if (OUT == NULL)
	{
		printf("Please Verify The Current Dir.. It May Be Changed");
	}
	for (i = 0; i < 5; i++)
	{
		for (iCOUNT = 0; iCOUNT < 10; iCOUNT++)
			fscanf(IN, "%d", &iIN[iCOUNT]);
		iOUT = fun(iIN);
		fprintf(OUT, "%d\n", iOUT);
	}
	fclose(IN);
	fclose(OUT);
}
