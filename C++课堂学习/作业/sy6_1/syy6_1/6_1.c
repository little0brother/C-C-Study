#include <stdio.h>
#include <string.h>

void sub(char s[], char t[]);

int main()
{
	char s[100], t[100];
	printf("Please enter string s:");
	gets(s);

	sub(s, t);
	printf("The result is: %s\n", t);

	system("pause");
	return 0;
}

void sub(char s[], char t[])
{
	int i, d = strlen(s);

	for (i = 0; i < d; i++)
		t[i] = s[d - 1 - i];

	for (i = 0; i < d; i++)
		t[d + i] = s[i];

	t[2 * d] = '\0';
}