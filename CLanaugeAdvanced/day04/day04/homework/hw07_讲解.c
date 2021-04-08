#include <stdio.h>
#include <string.h>

#define NUM(a) (sizeof(a)/sizeof(*a))

int searcheKeyTable(const char* table[], const int size,
	const char* key, int* pos)
{
	if (table == NULL || key == NULL || pos == NULL)
	{
		return -1;
	}

	int count = -1;

	for (int i = 0; i < size; i++)
	{
		if (strcmp(table[i], key) == 0)
		{
			count = i;
			break;
		}
	}

	// 没有匹配字符串
	if (count == -1)
	{
		return -2;
	}

	*pos = count + 1;

	return 0;
}

int main()
{
	const char* keywords[] = {
		"while",
		"case",
		"static",
		"do"
	};

	char* str = "do";
	int pos = 0;
	int ret = 0;

	ret = searcheKeyTable(keywords, NUM(keywords), str, &pos);
	if (ret != 0)
	{
		printf("searchKeyTable err: %d\n", ret);
		return ret;
	}

	printf("%s在keywords中的位置为：%d\n", str, pos);

	return 0;
}