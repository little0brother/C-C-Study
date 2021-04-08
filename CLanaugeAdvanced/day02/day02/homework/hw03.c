/*
* 有一个字符串“1a2b3d4z”；
   要求写一个函数实现如下功能：
	功能1：把偶数位字符挑选出来，组成一个字符串1。
	功能2：把奇数位字符挑选出来，组成一个字符串2。
	功能3：把字符串1和字符串2，通过函数参数，传送给main，并打印。
	功能4：主函数能测试通过。
	int getStr1Str2(char *source, char *buf1, char *buf2);
*/

/*
*	功能：挑出奇数位与偶数位字符串，分别组成两个新子串
*	参数：
*		source: 要分拣的字符串
*		buf1:   存奇数位字符串
*		buf2:   存偶数位字符串
*	返回值:
*		成功：0
*		失败：非0
* 
*/

#include <stdio.h>

int getStr1Str2(char* source, char* buf1, char* buf2)
{
	int i = 0;

	if (source == NULL || buf1 == NULL || buf2 == NULL)
	{
		return -1;
	}

#if(0)
	while (source[i] != 0)
	{
		// 0 对 2 取余为 0 
		// 必须先做完取余运算，才可对 i 自增， 否则会缺失第一位
		if (i % 2 == 0)
		{
			*buf1++ = source[i];
		}
		else
		{
			*buf2++ = source[i];
		}

		i++;
	}
#endif

#if(1)
	int n = strlen(source); // 字符串长度
	for (i = 0; i < n; i++)
	{
		// 如果是偶数位
		if ( (i % 2) == 0 )
		{
			*buf1++ = source[i];
		}
		// 如果是奇数位
		else
		{
			*buf2++ = source[i];
		}
	}

	*buf1 = 0;
	*buf2 = 0;

#endif

	return 0;
}

int main(void)
{
	char* str = "1a2b3d4z";
	char buf1[100] = { 0 };
	char buf2[100] = { 0 };
	int ret = 0;

	ret = getStr1Str2(str, buf1, buf2);
	if (ret != 0)
	{
		printf("getStr1Str2 err:%d\n", ret);
		return ret;
	}

	printf("buf1 = %s\n", buf1);
	printf("buf2 = %s\n", buf2);

	printf("\n");
	return 0;
}