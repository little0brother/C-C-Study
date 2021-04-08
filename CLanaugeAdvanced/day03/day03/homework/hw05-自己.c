/**
	有字符串有以下特征（“abcd11111abcd2222abcdqqqqq”）, 求写一个函数接口，输出以下结果。
	把字符串替换成（dcba11111dcba2222dcbaqqqqq），并把结果传出。
	要求：
	1. 正确实现接口和功能
	2. 编写测试用例
*/

/**
	src:    原字符串
	dst:    生成的或需要填充的字符串
	sub:    需要查找的子字符串
	new_sub:提换的新子字符串

	return : 0 成功
			-1 失败
*/

#include <stdio.h>
#include <string.h>

#define DSTLEN 100

// 第一版不完全功能，但基本原理已经实现
#if(0)
int replaceSubstr(/* in */char* src, /* out */char** dst, /* in */char* sub,  /* in */char* new_sub)
{
	if (src == NULL || sub == NULL || new_sub == NULL)
	{
		return -1;
	}

	char* src_bak  = src;
	char* flag_len = NULL;
	char* dst_bak  = (char*)malloc(DSTLEN);		// 临时变量存放dst的指向，最后通过*dst = dst_bak 完成地址转移
	// 记录出现下一次查找子串的间隔长度
	int n;

	while (src_bak != NULL)
	{
		src_bak = strstr(src_bak, sub);
		if (src_bak == NULL)
		{
			return -2;
		}
		src_bak += sizeof(sub);

		flag_len = strstr(src_bak, sub);
		// 如果flag_len 为NULL 说明知道字符串尾都没有匹配的字符串，即之后所有子串全部需要拼接在dst_bak中
		if (flag_len == NULL)
		{
			n = strlen(src);
		}
		else
		{
			n = (flag_len - src_bak);
		}

		// err 无法拷贝字符串至该变量中
		//char* sub_tmp = NULL;
		//sub_tmp = (char*)malloc((n) * sizeof(char));
		//if (sub_tmp == NULL)
		//{
		//	return -3;
		//}
		char sub_tmp[100] = { 0 };
		// 将两个目标子串中间的变量取出来
		strncpy(sub_tmp, src_bak, n);
		// 将src首地址移动到flag_len查找的位置之后
		src_bak += n;

		sprintf(dst_bak, "%s%s", new_sub, sub_tmp);
		dst_bak += n;
	}

	*dst = dst_bak;

	return 0;
}
#endif

int replaceSubstr(/* in */char* src, /* out */char** dst, /* in */char* sub,  /* in */char* new_sub)
{
	if (src == NULL || sub == NULL || new_sub == NULL || dst == NULL)
	{
		return -1;
	}

	/**
	* src     = "abcd11111abcd2222abcdqqqqqabcd";
	* sub     = "abcd";
	* new_sub = "dcabbb";
	*/

	char* src_bak  = src;
	char* flag_len = NULL;
	char* dst_bak  = (char*)malloc(DSTLEN);		// 临时变量存放dst的指向，最后通过*dst = dst_bak 完成地址转移
	//char dst_bak[100] = {0};
	int sstr2str_len; // 记录两个需要查找字符串中间子串的长度
	char sub_tmp[100] = { 0 }; // 存放两个要查找的目标子串中间的字符串
	int n = 0;		// 用于判断字符串最前端是不是匹配子串

	*dst = dst_bak;
	flag_len = src;

	while (*src_bak != 0)
	{
		src_bak = strstr(src_bak, sub);
		// 如果没有匹配子串，则直接将字符串原封不动复制到src_bak中，并且结束
		if (src_bak == NULL)
		{
			strcpy(dst_bak, src);
			break;
		}

		// 用于判断 需要查找的字符串 是不是在最前端，如果不是在最前端，则说明前端有其他字符串需要复制到dst中
		if (src != src_bak && n == 0)
		{
			n = src_bak - src;
			strncpy(dst_bak, src, n);
			dst_bak += n;
		}
		n++;		// 自增，记录循环次数，并且防止第二次判断为最前端。

		// 能进来肯定有匹配子串
		src_bak += strlen(sub);
		// 如果遇到字符串结尾，则跳出循环
		if (src_bak == NULL)
		{
			break;
		}

		flag_len = strstr(src_bak, sub);
		if (flag_len == NULL)
		{
			sstr2str_len = strlen(src);
		}
		else
		{
			sstr2str_len = (flag_len - src_bak);
		}

		strncpy(sub_tmp, src_bak, sstr2str_len);
		sprintf(dst_bak, "%s%s", new_sub, sub_tmp);

		src_bak += sstr2str_len;
		dst_bak += (sstr2str_len + strlen(new_sub));
	}

	return 0;
}

void print_str(char *str)
{
	printf("%s\b", str);
}

int main()
{
	char* str		   = "abcd11111abcd2222abcdqqqqqabcd";
	char* fill_str	   = NULL;		// 在replaceSubstr()函数中分配空间
	char* serch		   = "abcd";
	char* change_str   = "dsatggg";
	int ret = 0;

	ret = replaceSubstr(str, &fill_str, serch, change_str);
	if (ret != 0)
	{
		printf("replaceSubstr err:%d", ret);
		return ret;
	}

	printf("替换前字符串：\n");
	print_str(str);

	printf("\n替换后字符串：\n");
	print_str(fill_str);

	if (fill_str != NULL)
	{
		free(fill_str);
		fill_str = NULL;
	}

	printf("\n");
	return 0;
}