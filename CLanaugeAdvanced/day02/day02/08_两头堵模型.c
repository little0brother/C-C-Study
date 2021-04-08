/* 在字符串左右两边有空格时，数出非空格字符个数,并且保存非空字符串 */

#include <stdio.h>
#include <ctype.h>

#if(0)
int main(void)
{
	char* p = "    abcdefg     ";
	int begin = 0;
	int end = strlen(p) - 1;
	int n = 0;

	// 从左边开始移动至非空格位置
	// 如果当前字符为空，而且没有结束
	while (isspace(p[begin]) && p[begin] != 0)
	{
		begin++;	// 位置向右移动一位
	}

	// 从右边开始移动至非空格位置
	while (isspace(p[end]) && p[end] != 0)
	{
		end--;		// 位置向左移动一位
	}

	n = end - begin + 1;

	printf("n = %d\n", n);

	printf("\n");
	return 0;
}
#endif

// 封装
#if(1)

// 计算非空字符串个数
int fun(char* p, int* n)
{
	char* str = p;
	int begin = 0;
	int end = strlen(str) - 1;

	if (str == NULL || n == NULL)
	{
		return -1;
	}

	// 从左边开始移动至非空格位置
	// 如果当前字符为空，而且没有结束
	while (isspace(str[begin]) && str[begin] != 0)
	{
		begin++;	// 位置向右移动一位
	}

	// 从右边开始移动至非空格位置
	while (isspace(str[end]) && str[end] != 0)
	{
		end--;		// 位置向左移动一位
	}

	*n = end - begin + 1;

	return 0;
}

// 取出非空字符串
int fun2(char *p, char *buf)
{
	char* str = p;
	int begin = 0;
	int end = strlen(str) - 1;
	int n = 0;

	if (str == NULL || buf == NULL)
	{
		return -1;
	}

	// 从左边开始移动至非空格位置
	// 如果当前字符为空，而且没有结束
	while (isspace(str[begin]) && str[begin] != 0)
	{
		begin++;	// 位置向右移动一位
	}

	// 从右边开始移动至非空格位置
	while (isspace(str[end]) && str[end] != 0)
	{
		end--;		// 位置向左移动一位
	}

	n = end - begin + 1;	// 非空元素个数

	strncpy(buf, str + begin, n);	// 字符串拷贝函数，可以指定copy个数
	buf[n] = 0;

	return 0;
}

int main(void)
{
	char* p = "    abcdefg     ";
	int n = 0;
	int ret1 = 0;
	int ret2 = 0;
	char buf[100] = { 0 };

	ret1 = fun(p, &n);
	if (ret1 != 0)
	{
		return ret1;
	}
	printf("n = %d\n", n);

	ret2 = fun2(p, buf);
	if (ret2 != 0)
	{
		return ret2;
	}
	printf("buf = %s", buf);

	return 0;
}

#endif