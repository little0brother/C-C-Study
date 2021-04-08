#include <stdio.h>
#include <string.h>

int str2num(char* p)
{
	int num = 0, k, len, j;
	len = strlen(p);

	for (; *p != '\0'; p++)
	{
		k = *p - '0';
		j = (--len);

		while (j-- > 0)
			k = k * 10;

		num = num + k;
	}
	return (num);
}

int main()
{
	char s[6];
	int n;
	gets(s);

	if (*s == '-')
		n = -str2num(s + 1);
	else
		n = str2num(s);

	printf("%d\n", n);

	system("pause");
	return 0;
}