/**
* 6. 有一个字符串符合以下特征（“abcdef, acccd, eeee, aaaa, e3eeee, ssss, ”）
* 
第二个API(第三种内存模型：动态生成二维内存)
1)以逗号分隔字符串，形成一个二级指针
2)把一共拆分多少行字符串个数传出
int spitString2(const char* str, char c, char** myp, int* count);

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

#define MALLOCLEN 10
#define CSTRLEN	  128

int spitString2(const char* str, char* c, char** myp /*in*/, int* count)
{
	if (str == NULL || count == NULL || myp == NULL)
	{
		return -1;
	}

	char* str_bak = str;	// 存放查找str中“,”位置
	char* str_bak1 = str;	// 存放上一次查找位置 
	int cstrlen = 0;		// 用上述两个变量计算 中间 子串长度
	char tmp[30] = { 0 };
	int count_bak = 0;

	while (str_bak = strstr(str_bak, c))
	{
		// 下方以实现此功能
		//// 如果没找查找到目标，则将整串字符串复制到myp中并退去循环
		//if (str_bak == NULL)
		//{
		//	strncpy(myp[count_bak], str_bak1, strlen(str_bak1));
		//	myp[count_bak][strlen(str)] = '\0';
		//	break;
		//}

		// 查找","位置 并将","位置返回值str_bak
		if (str_bak == NULL)
		{
			break;
		}

		// 计算逗号之间子字符串的长度
		cstrlen = (str_bak - str_bak1);

		// 将子串存入
		strncpy(myp[count_bak], str_bak1, cstrlen);
		myp[count_bak][cstrlen] = '\0';		// 添加结束符

		// 将用于计算差值位置的指向进行移位，移向下一个位置
		str_bak1 += (cstrlen + strlen(c));
		str_bak += strlen(c);	// 因为指针指向逗号，无法正常查找下一位
		count_bak++;	// 计数器自增
	}

	// 如果没找查找到目标，则将整串字符串复制到myp中并退去循环
	if (str_bak == NULL && str_bak1 != NULL)
	{
		cstrlen = strlen(str_bak1);
		strncpy(myp[count_bak], str_bak1, strlen(str_bak1));
		myp[count_bak][cstrlen] = '\0';
		count_bak++;
	}

	*count = count_bak;

	return 0;
}

// 申请内存空间
char** getMem_rec(int n)
{
	char** buf = (char**)malloc(n * sizeof(char*));
	if (buf == NULL)
	{
		return NULL;
	}

	for (int i = 0; i < n; i++)
	{
		buf[i] = (char*)malloc(CSTRLEN * sizeof(char));
	}

	return buf;
}

// 申请内存空间，不需要返回地址,直接在函数中完成内存申请
int getMem_rec2(char*** buf, int n)
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

void print_arr(char** buf, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%s\n", buf[i]);
	}
}

// 释放申请的内存空间
void free_rec(char** buf, int n)
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

int calLen(char *str, char *c)
{
	int count = 1;
	while (str = strstr(str, c))
	{
		count++;
		str += strlen(c);
	}

	return count + 1;
}

int main()
{
	char* str        = ",abcdef ,acccd ,eeee, aaaa ,e3eeee ,ssss ,aaa3";
	char* split_ch   = ",";
	char** rec_split = NULL;
	int split_count  = 0;
	int ret          = 0;
	int clen         = 0;
	
	// 申请内存长度可以通过测算','个数,来确定
	clen = calLen(str, split_ch);

#if(0)
	rec_split = getMem_rec(clen);
	if (rec_split == NULL)
	{
		printf("getMen_rec err:");
		return -1;
	}
#endif

#if(1)
	ret = getMem_rec2(&rec_split, clen);
	if (ret != 0)
	{
		printf("getMem_rec2 err:%d", ret);
		return -2;
	}
#endif

	printf("拆分之前：\n");
	printf("%s", str);

	ret = spitString2(str, split_ch, rec_split, &split_count);
	if (ret != 0)
	{
		printf("spitString2 err:%d", ret);
		return ret;
	}

	printf("\n拆分之后：\n");
	print_arr(rec_split, split_count);

	free_rec(rec_split, clen);
	rec_split = NULL;

	printf("\n");
	return 0;
}