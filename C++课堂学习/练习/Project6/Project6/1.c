#include <stdio.h>

void fun(char a[], char b[], int n);

int main()
{
	char str[100] = { 0 }, b[100] = { 0 };
	int n;
	gets(str);
	printf("输入删除元素的下标：");
	scanf_s("%d", &n);

	fun(str, b, n);

	system("pause");
	return 0;
}

void fun(char a[], char b[], int n)
{
	int i = 0, x = 0;
	a[n] = '0';
	while (a[i] != '\0')
	{
		if (a[i] != '0')
		{
			b[x++] = a[i];
		}
		i++;
	}

	puts(b);
	putchar('\n');
}