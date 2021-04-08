#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f(char s[])
{
	int m, n, i, j, L = strlen(s);

	for (i = 0, j = 0; j < L; j++)
	{
		if (s[j] >= '0' && s[j] <= '9')
			s[i++] = s[j];
	}
	s[i] = '\0';
	L = i;

	m = 0;
	n = 0;
	for (i = 0; i < L; i += 2)
	{
		m += (s[i] - '0') * 1;
		n += (s[i + 1] - '0') * 3;
	}

	m = (m + n) % 10;
	m = (10 - m) % 10;

	return m;
}

int main()
{
	char s[20] = {0};
	printf("ÇëÊäÈëÂëÖµ£º");
	gets(s);
	printf("ISBN: %d\n", f(s));
	
	system("pause");
	return 0;
}