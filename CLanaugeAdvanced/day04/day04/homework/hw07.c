/**
* 7. 找到数组中指定字符串的位置
	#define NUM(a) (sizeof(a)/sizeof(*a))

	char* keywords[] = {
		"while", 
		"case",
		"static",
		"do"
	};

	int searcheKeyTable(const char* table[], const int size, 
				  const char* key, int *pos);
*/

/**
* 功能：找到数组中指定字符串的位置
*	table : 字符串数组（指针数组）首地址，需要再其中查找的字符串
*	size  :	table子串个数
*	key   : 匹配字符串，如 "do"
*	pos   :	匹配字符串在数组中的位置，如果"do"在keywords[]中位置为4
* 
*	return:
*		0 : 成功
*	  非0 :	失败
*/

#include <stdio.h>
#include <string.h>

#define NUM(a) (sizeof(a)/sizeof(*a))

int searcheKeyTable(const char* table[] /*指针数组*/, const int size, const char* key, int* pos)
{
	if (table == NULL || key == NULL)
	{
		return -1;
	}

	char** str = table;
	int count = -1;
	int i = 0;
	
	// 循环查找对应字符串
	for (i = 0; i < size; i++)
	{
		// 对比目前子串与目标子串，不相同则自增，相同则跳出循环
		if (str[i] == key)
		{
			count = i;
			break;
		}
	}

	// 没有查找到匹配子串
	if (count == -1)
	{
		return -2;
	}

	*pos = count + 1;

	return 0;
}

int main()
{
	int ret = 0;
	int posiston;
	char* key = "static";
	char* keywords[] = {
		"while",
		"case",
		"static",
		"do"
	};
	
	ret = searcheKeyTable(keywords, NUM(keywords), key, &posiston);
	if (ret != 0)
	{
		printf("searcheKeyTable err : %d\n", ret);
		return ret;
	}

	if (ret == -2)
	{
		printf("%s 不存在！\n", key);
	}
	else
	{
		printf("%s在字符串keywords中第%d位\n", key, posiston);
	}
	
	return 0;
}