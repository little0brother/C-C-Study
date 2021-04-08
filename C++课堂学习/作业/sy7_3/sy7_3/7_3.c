#include <stdio.h>
#include <string.h>

int main()
{
	int i, a[26];
	char ch, str[80], *p = str;
	gets(str);

	for (i = 0; i < 26; i++)
		a[i] = 0;

	while (*p)
	{
		ch = *p++;
		ch = ch >= 'A' && ch <= 'Z' ? ch + 'a' - 'A' : ch;

		if (ch >= 'a' && ch <= 'z')
			a[ch - 'a']++;
	}
	for (i = 0; i < 26; i++)
		printf("%2c", 'a' + i);
	printf("\n");

	printf("出现的次数为：\n");
	for (i = 0; i < 26; i++)
		printf("%2d", a[i]);
	printf("\n");

	system("pause");
	return 0;
}