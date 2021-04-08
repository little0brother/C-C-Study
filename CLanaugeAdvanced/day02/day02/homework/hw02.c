/*
* 有一个字符串开头或结尾含有n个空格 （”   abcdefgdddd    ”），欲去掉前后空格，返回一个新字符串。
	要求1：请自己定义一个接口（函数），并实现功能；
	要求2：编写测试用例。
	int trimSpace(char *inbuf, char *outbuf);
*/

/*
	功能获取非空字符串
	参数：
		inbuf:  原始字符串buf首地址
		outbuf: 非空字符串buf首地址
	返回之：
		成功：0
		失败：非0
*/

#include <stdio.h>
#include <ctype.h>

int trimSpace(char* inbuf, char* outbuf)
{
	char* p = inbuf;
	char* buf = outbuf;
	int begin = 0;
	int end = strlen(p) - 1;
	int n = 0;

	if (p == NULL || buf == NULL)
	{
		return -1;
	}

	while (isspace(p[begin]) && p[begin] != NULL)
	{
		begin++;
	}

	while (isspace(p[end]) && p[end] != NULL)
	{
		end--;
	}

	n = end - begin + 1;
	printf("n = %d\n", n);

	strncpy(buf, p + begin, n);

	return 0;
}

int main(void)
{
	char* str = "   abcdefgdddd    ";
	char buf[100] = { 0 };
	int ret = 0;

	ret = trimSpace(str, buf);
	if (ret != 0)
	{
		return ret;
	}
	printf("取出的字符串为: %s\n", buf);

	printf("\n");
	return 0;
}