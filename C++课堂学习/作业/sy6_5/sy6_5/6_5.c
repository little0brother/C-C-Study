#include <stdio.h>
#include <stdlib.h>

int toNumber(char c[])
{
	int num = 0, i = 0;
	while (c[i] != '\0')
	{
		num = num * 10 + (c[i] - '0');
		++i;
	}
	return num;
}

int main()
{
	int num;
	char c[10];
	printf("input a number < 1000000000 as a string : ");
	gets(c);

	num = toNumber(c);
	printf("the number is : %d\n", num);

	system("pause");
	return 0;
}