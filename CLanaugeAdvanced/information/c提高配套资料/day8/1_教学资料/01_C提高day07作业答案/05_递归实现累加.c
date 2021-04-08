#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fun(int n)
{
	if (n == 1)
	{
		return n;
	}
	else
	{
		return fun(n - 1) + n;
	}

}

int main(void)
{

	int i = 0;
	int sum = 0;
	for (i = 1; i <= 100; i++)
	{
		sum += i;
	}
	printf("sum1 = %d\n", sum);

	sum = fun(100);
	printf("\nsum2 = %d\n", sum);
	
	printf("\n");
	system("pause");
	return 0;
}