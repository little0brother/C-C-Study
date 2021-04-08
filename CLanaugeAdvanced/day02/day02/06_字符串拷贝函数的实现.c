#include <stdio.h>

#if(0)
int main(void)
{
	char src[] = "faiofhdsaohfa";
	char dst[100];
	int i = 0;

	for (i = 0; src[i] != '\0'; i++)
	{
		dst[i] = src[i];
	}
	// 补结束符
	dst[i] = 0;

	printf("%s\n", dst);


	printf("\n");
	return 0;
}
#endif

void my_strcpy(char* dst, char* src)
{
	int i = 0;

	for (i = 0; *(src + i) != '\0'; i++)
	{
		*(dst + i) = *(src + i);
	}
	// 补结束符
	*(dst + i) = 0;
}

void my_strcpy2(char* dst, char* src)
{
	while (*src != 0)
	{
		*dst++ = *src++;
	}
	*dst = 0;

	printf("fd%s", dst);
}

void my_strcpy3(char* dst, char* src)
{
	while (*dst++ = *src++);
}

// 成为返回0，失败返回非0
// 1.判断形参指针是否为NULL
// 2.最好不要直接使用形参
int my_strcpy4(char* dst, char* src)
{
	if (dst == NULL || src == NULL)
	{
		return -1;
	}

	// 辅助变量，接管形参
	char* to = dst;
	char* from = src;

	// *dst == *src
	// dst++, src++
	// 判断 *dst是否为0，为0跳出循环
	while (*to++ = *from++) 
	{
		NULL;
	}

	// dst指向字符串首地址，指针位置一直没有移动，当时to在移位时对*to中做了赋值运算，改变了地址的中存的数值
	printf("my_strcpy: dst = %s\n", dst);
	printf("my1_strcpy: to = %s\n", to);

	return 0;
}

int main(void)
{
	char src[] = "faiofhdsaohfa";
	char dst[100];
	int ret = 0;

	//my_strcpy(dst, src);
	//my_strcpy2(dst, src);
	ret = my_strcpy4(dst, src);
	if (ret != 0)
	{
		printf("my_strcpy4 err: %d\n", ret);
		return ret;
	}
	printf("%s\n", dst);

	printf("\n");
	return 0;
}