#include <stdio.h>

#if(0)

// do-while 模型
int main(void)
{
	char* str = "abcd123abcd543442abcdifa088abcdafdabcd1abcdabcdabcdabcd";
	int count = 0;

	do{
		str = strstr(str, "abcd");
		if (str != NULL)
		{
			count++;				// 累计个数
			str = str + sizeof("abcd") - 1;	// 重新设置查找的起点
		}
		else	// 如果没有匹配的字符串，跳出循环
		{
			break;
		}
	} while (*str != 0);	// 判断是否到达字符串结尾

	printf("\"abcd\"共出现 %d 次", count);

	printf("\n");
	return 0;
}
#endif

#if(0)

// while模型 
int main(void)
{
	char* str = "abcd123abcd543442abcdifa088abcdafdabcd1abcdabcdabcd";
	int count = 0;

	while ( (str = strstr(str, "abcd")) != NULL )
	{
		// 能进来，肯定有匹配的子串

		// 重新设置查找起点
		str = str + strlen("abcd");
		count++;

		if (*str == 0)  // 如果到结束符
		{
			break;
		}
	}
	printf("\"abcd\"共出现 %d 次\n", count);

	printf("\n");
	return 0;
}

#endif

#if(1)

// 封装函数

int my_strstr(char* str, int* count)
{
	// 辅助变量
	int i = 0;
	char* tmp = str;

	while (tmp = strstr(tmp, "abcd"))
	{
		// 能进来，肯定有匹配的子串

		// 重新设置查找起点
		tmp = tmp + strlen("abcd");
		i++;

		if (*tmp == 0)  // 如果到结束符
		{
			break;
		}
	}
	*count = i;

	return 0;
}

int main(void)
{
	char* str = "abcd123abcd543442abcdifa088abcdafdabcd1abcdabcdabcdabcd";
	int count = 0;
	int ret = 0;

	ret = my_strstr(str, &count);
	if (ret != 0)
	{
		return ret;
	}
	printf("\"abcd\"共出现 %d 次\n", count);

	printf("\n");
	return 0;

}

#endif