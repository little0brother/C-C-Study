/**
* 6. 有一个字符串符合以下特征（“abcdef, acccd, eeee, aaaa, e3eeee, ssss, ”）
*
第二个API(第三种内存模型：动态生成二维内存)
1)以逗号分隔字符串，形成一个二级指针
2)把一共拆分多少行字符串个数传出
int spitString(const char* str, char c, char** myp, int* count);

要求：
1, 能正确表达功能的要求，定义出接口。
2, 正确实现接口和功能.
3, 编写正确的测试用例.

* /

/**
*	str    : 需要分隔的字符串
*	c      : 分隔字符串的标志
*	myp    : 接收分隔字符串
*	count  : 计数，记录一共有多少子串
*
*	return :  0    成功
*			  非0  失败
*/

#include <stdio.h>
#include <string.h>

#define MALLOCLEN 512

int spitString(const char* str, char* c, char** myp, int* count)
{
	if (str == NULL || c == NULL || myp == NULL)
	{
		return -1;
	}

	char* start = str;
	char* p = NULL;
	int len = 0;

	do 
	{
		p = strchr(start, *c);
		// 如果正常查找到字符
		if (p != NULL)
		{
			len = 0;
			len = p - start;

			if (len > 0)
			{
				strncpy(myp[*count], start, len);
				myp[*count][len] = '\0';
			}
			
			// 移动起始位置
			start += (len + strlen(c));
			(*count)++;
		}
		// 如果没有查找到字符
		else
		{
			strcpy(myp[*count], str);
			myp[*count][strlen(start)] = '\0';
			(*count)++;
			break;
		}
	} while (*start != 0);

	return 0;
}

char** getMemRec(int n)
{
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

int freeMem(char** buf, int n)
{
	if (buf == NULL)
	{
		return -1;
	}

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

int main()
{
	char* str        = ",abcdef, acccd ,eeee ,aaa e3e eee, ssss ";
	char* c          = ",";
	char** split_str = NULL;
	int count        = 0;
	int ret          = 0;

	split_str = getMemRec(MALLOCLEN);
	if (split_str == NULL)
	{
		printf("getMemRec err !");
		return -1;
	}

	ret = spitString(str, c, split_str, &count);
	if (ret != 0)
	{
		printf("spitString err : %d\n", ret);
		return ret;
	}

	for (int i = 0; i < count; i++)
	{
		printf("%s\n", split_str[i]);
	}

	ret = freeMem(split_str, MALLOCLEN);
	if (ret != 0)
	{
		printf("freeMem err : %d\n");
		return ret;
	}

	return 0;
}