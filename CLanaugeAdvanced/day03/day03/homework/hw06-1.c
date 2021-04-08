/**
6. 有一个字符串符合以下特征（“abcdef, acccd, eeee, aaaa, e3eeee, ssss, ”）

写两个函数(API)，输出以下结果
第一个API(第二种内存模型： 二维数组)
1)以逗号分隔字符串，形成二维数组，并把结果传出
2)把二维数组行数运算结果也传出
 int spitString(const char* str, char c, char buf[10][30], int* count);

要求：
1, 能正确表达功能的要求，定义出接口。
2, 正确实现接口和功能.
3, 编写正确的测试用例.

*/

/**
*	str    : 需要分隔的字符串
*	c      : 分隔字符串的标志
*	buf    : 接收分隔字符串
*	count  : 计数，记录一共有多少子串
* 
*	return :  0    成功
*			  非0  失败
*/

#include <stdio.h>
#include <string.h>

// 声明
int spitString(const char* str, char *c, char buf[10][30]/*in*/, int* count);

int spitString(const char* str, char *c, char buf[10][30]/*in*/, int* count)
{
	if (str == NULL || count == NULL || buf == NULL)
	{
		return -1;
	}

	char* str_bak = str;	// 存放查找str中 , 位置
	char* str_bak1 = str;	// 存放上一次查找位置 
	int cstrlen = 0;		// 用上述两个变量计算 中间 子串长度
	char tmp[30] = { 0 };
	int count_bak = 0;

	while (str_bak = strchr(str_bak, *c))
	{
		// 查找","位置 并将","位置返回值str_bak
		if (str_bak == NULL)
		{
			break;
		}

		// 计算逗号之间子字符串的长度
		cstrlen = (str_bak - str_bak1);

		// 将子串存入
		strncpy(buf[count_bak++], str_bak1, cstrlen);

		// 将用于计算差值位置的 指向进行移位，移向下一个位置
		str_bak1 += (cstrlen + strlen(c));
		str_bak += strlen(c);	// 因为指针指向逗号，无法正常查找下一位
	}

	if (str_bak == NULL && str_bak1 != NULL)
	{
		cstrlen = strlen(str_bak1);
		strncpy(buf[count_bak++], str_bak1, cstrlen);
	}
	
	*count = count_bak;

	return 0;
}

void print_arr(char* title, char buf[][30], int count)
{
	printf("%s:\n", title);
	for (int i = 0; i < count; i++)
	{
		printf("%s\n", buf[i]);
	}
}

int main()
{
	char *str			   =  "abcdef, acccd, eeee, aaaa, e3eeee, ssss, aaa3";
	char *split_ch	  	   = ","; 
	char rec_split[10][30] = { 0 };
	int split_count		   = 0;
	int ret				   = 0;

	printf("分隔前：\n");
	printf("%s\n", str);

	ret = spitString(str, split_ch, rec_split, &split_count);
	if (ret != 0)
	{
		printf("spitString err:%d", ret);
		return ret;
	}

	printf("\n分隔后：\n");
	print_arr("spitString2", rec_split, split_count);

	printf("\n");
	return 0;
}