#include <stdio.h>
#include <string.h>

int inverse(char* str)
{
	char dst[128] = { 0 };

	if (str == NULL)
	{
		return -1;
	}

	if (*str == '\0')	// µİ¹éÌõ¼ş
	{
		return 0;
	}

	if (inverse(str + 1) < 0)
	{
		return -1;
	}

	strncpy(dst, str, 1);

	printf("dst = %s\n", dst);

	return 0;
}

int main()
{
	inverse("abcdefghijklmnopqrstuvwxyz");

	return 0;
}