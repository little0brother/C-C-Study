#include <stdio.h>

int main()
{
	char str[80] = { 0 };
	int  num[10] = { 0 };
	int  i = 0, n;

	gets(str);

	while (str[i] != '\0') {
		n = str[i] - '0';
		num[n]++;
		i++;
	}

	for (i = 1; i < 10; i += 2)
		printf("%d:%d\n", i, num[i]);

	system("pause");
	return 0;
}