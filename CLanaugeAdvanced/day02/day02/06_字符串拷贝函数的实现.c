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
	// ��������
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
	// ��������
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

// ��Ϊ����0��ʧ�ܷ��ط�0
// 1.�ж��β�ָ���Ƿ�ΪNULL
// 2.��ò�Ҫֱ��ʹ���β�
int my_strcpy4(char* dst, char* src)
{
	if (dst == NULL || src == NULL)
	{
		return -1;
	}

	// �����������ӹ��β�
	char* to = dst;
	char* from = src;

	// *dst == *src
	// dst++, src++
	// �ж� *dst�Ƿ�Ϊ0��Ϊ0����ѭ��
	while (*to++ = *from++) 
	{
		NULL;
	}

	// dstָ���ַ����׵�ַ��ָ��λ��һֱû���ƶ�����ʱto����λʱ��*to�����˸�ֵ���㣬�ı��˵�ַ���д����ֵ
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