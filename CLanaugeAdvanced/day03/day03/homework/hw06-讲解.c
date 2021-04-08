/**
	6. 有一个字符串符合以下特征（“abcdef, acccd, eeee, aaaa, e3eeee, ssss, ”）

	写两个函数(API)，输出以下结果
	第一个API(第二种内存模型： 二维数组)
	1)以逗号分隔字符串，形成二维数组，并把结果传出
	2)把二维数组行数运算结果也传出
	int spitString(const char* str, char c, char buf[10][30], int* count);

	第二个API(第三种内存模型：动态生成二维内存)
	1)以逗号分隔字符串，形成一个二级指针。
	2)把一共拆分多少行字符串个数传出
	int spitString2(const char* str, char c, char** myp, int* count);

	要求：
	1, 能正确表达功能的要求，定义出接口。
	2, 正确实现接口和功能.
	3, 编写正确的测试用例.
*/

// 题目要求一
#if(0)
#include <stdio.h>
#include <string.h>

int spitString(const char* str, char c, char buf[10][30], int* count)
{
	if (str == NULL || count == NULL)
	{
		return -1;
	}

	// str = "abcdef, acccd, eeee, aaaa, e3eeee, ssss, ";
	const char* start = str;
	char* p = NULL;
	int i = 0;


	do
	{
		p = strchr(start, c);
		if (p != NULL)
		{
			int len = p - start;
			strncpy(buf[i], start, len);
			// 结束符
			buf[i][len] = '\0';

			i++;
			// 重新设置起点位置
			start = p + 1;
		}
		else
		{
			strcpy(buf[i], start);
			i++;
			break;
		}
	} while (*start != 0);

	// 如果i=0 说明没有找到','
	if (i == 0)
	{
		return -2;
	}

	*count = i;

	return 0;
}

int main()
{
	const char* str = "abcdef, acccd, eeee, aaaa, e3eeee, ssss, ";
	char buf[10][30] = { 0 };
	int n = 0;
	int ret = 0;

	ret = spitString(str, ',', buf, &n);
	if (ret != 0)
	{
		printf("splitString err: %d\n", ret);
		return ret;
	}

	for (int i = 0; i < n; i++)
	{
		printf("%s\n", buf[i]);
	}

	printf("\n");
	return 0;
}
#endif

// 题目要求二
#if(1)

#include <stdio.h>
#include <string.h>

int spitString(const char* str, char c, char** buf, int* count)
{

	if (str == NULL || count == NULL)
	{
		return -1;
	}

	// str = "abcdef, acccd, eeee, aaaa, e3eeee, ssss, ";
	const char* start = str;
	char* p = NULL;
	int i = 0;


	do
	{
		p = strchr(start, c);
		if (p != NULL)
		{
			int len = p - start;
			strncpy(buf[i], start, len);
			// 结束符
			buf[i][len] = '\0';

			i++;
			// 重新设置起点位置
			start = p + 1;
		}
		else
		{
			strcpy(buf[i], start);
			i++;
			break;
		}
	} while (*start != 0);

	// 如果i=0 说明没有找到','
	if (i == 0)
	{
		return -2;
	}

	*count = i;

	return 0;
}

char** getMem(int n)
{
	//char** buf = NULL;	// char *buf[n]
	char** buf = (char**)malloc(n * sizeof(char*));
	if (buf == NULL)
	{
		return NULL;
	}

	for (int i = 0; i < n; i++)
	{
		buf[i] = (char*)malloc(128 * sizeof(char));
	}

	return buf;
}

// 多级指针的使用
int getMem2(char*** buf, int n)
{
	char** tmp = NULL;
	tmp = (char**)malloc(n * sizeof(char*));
	if (tmp == NULL)
	{
		return -1;
	}

	for (int i = 0; i < n; i++)
	{
		tmp[i] = (char*)malloc(128 * sizeof(char));
	}

	// 间接赋值是指针存在最大意义
	*buf = tmp;

	return 0;
}

void freeMem(char** buf, int n)
{
	for (int i = 0; i < n; i++)
	{
		free(buf[i]);
		buf[i] = NULL;
	}

	if (buf != NULL)
	{
		free(buf);
		buf = NULL;
	}
}

void freeMem2(char ***tmp , int n)
{
	char** buf = *tmp;		// *tmp为指向的内存区域


	for (int i = 0; i < n; i++)
	{
		free(buf[i]);
		buf[i] = NULL;
	}

	if (buf != NULL)
	{
		free(buf);
		buf = NULL;
	}

	*tmp = NULL;
}

int main()
{
	const char* str = "abcdef, acccd, eeee, aaaa, e3eeee, ssss, ";
	char** buf = NULL;
	int n = 0;
	int ret = 0;

#if(0)
	buf = getMem(32);
	if (buf == NULL)
	{
		printf("getMem err: \n");
		return -1;
	}
#endif

	ret = getMem2(&buf, 32);
	if (ret != 0)
	{
		printf("getMem2 err: %d", ret);
		return ret;
	}

	ret = spitString(str, ',', buf, &n);
	if (ret != 0)
	{
		printf("splitString2 err: %d\n", ret);
		return ret;
	}

	for (int i = 0; i < n; i++)
	{
		printf("%s\n", buf[i]);
	}

#if(0)
	// 释放内存
	for (int i = 0; i < n; i++)
	{
		free(buf[i]);
		buf[i] = NULL;
	}
	if (buf != NULL)
	{
		free(buf);
		buf = NULL;
	}
#endif
	
	//freeMem(buf, n);
	//buf = NULL;

	freeMem2(&buf, n);
	if (buf != NULL)
	{
		free(buf);
		buf = NULL;
	}

	printf("\n");
	return 0;
}
#endif