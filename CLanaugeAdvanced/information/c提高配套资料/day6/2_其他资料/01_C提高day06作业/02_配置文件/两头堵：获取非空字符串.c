#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
2. 有一个字符串开头或结尾含有n个空格 （"   abcdefgdddd    "），欲去掉前后空格，返回一个新字符串。
	要求1：请自己定义一个接口（函数），并实现功能；
	要求2：编写测试用例。
	int trimSpace(char *inbuf, char *outbuf);
*/


/* 
功能：获取非空字符串
参数：
	inbuf： 原始字符串buf首地址
	outbuf：非空字符串buf首地址
返回值：
	成功：0
	失败：非0
*/
int trimSpace(char *inbuf, char *outbuf)
{
	if (inbuf == NULL || outbuf == NULL)
	{
		return -1;
	}

	char *p = inbuf;
	int begin = 0;
	int end = strlen(p) - 1;
	int n = 0;

	if (end < 0){
		return -2;
	}

	//从左往右移动，如果当前字符为空，而且没有结束
	while (isspace(p[begin]) && p[begin] != 0)
	{
		begin++; //位置从右移动一位
	}

	//从右往左移动，如果当前字符为空
	while (isspace(p[end]) && end > 0)
	{
		end--; //往左移动
	}

	if (end == 0)
	{
		return -2;
	}

	n = end - begin + 1; //非空元素个数

	strncpy(outbuf, p + begin, n);
	outbuf[n] = 0;

	return 0;
}

int main(void)
{
	char *p = "   abcdefgdddd    ";
	char buf[128] = { 0 };
	int ret = 0;

	ret = trimSpace(p, buf);
	if (ret != 0)
	{
		printf("trimSpace err: %d\n", ret);
	}

	printf("buf:%s\n", buf);
	
	printf("\n");
	system("pause");
	return 0;
}