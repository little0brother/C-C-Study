#include <stdio.h>
#include <string.h>

int main()
{
	char s[80], ch;
	int i, j, len, k;

	gets(s);
	len = strlen(s);

	for (i = 0, j = 0; i < len; i += 2)
	{
		ch = s[i];

		for (k = i; k > j; k--)
			s[k] = s[k - 1];

		s[j] = ch;
		j++;
	}

	printf("%s\n", s);

	system("pause");
	return 0;
}