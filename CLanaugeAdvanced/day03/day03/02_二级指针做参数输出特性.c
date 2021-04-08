#include <stdio.h>

#if(0)
// 值传递，形参的任何修改不会影响到实参
// 不加取地址符 就是值传递 不会影响地址内的内容
int getMem(char* p)
{
	p = (char*)malloc(sizeof(char) * 100);
	if (p == NULL)
	{
		return -1;
	}
	strcpy(p, "dfae");
	printf("p = %s\n", p);

	return 0;
}

int main(void)
{
	char* p = NULL;
	int ret = 0;

	ret = getMem(p);
	if (ret != 0)
	{
		printf("getMen err:%d\n", ret);
		return ret;
	}
	printf("p = %s\n", p);

	printf("\n");
	return 0;
}
#endif


#if(1)
// 二级指针，通过地址传递，修改形参来改变实参
int getMem(char** p /* 做输出 */)
{
	if (p == NULL)
	{
		return -1;
	}

	// 创建临时变量
	char* tmp = (char*)malloc(100);
	if (tmp == NULL)
	{
		return -2;
	}

	strcpy(tmp, "dfae");

	*p = tmp;

	return 0;
}

int main(void)
{
	char* p = NULL;
	int ret = 0;

	ret = getMem(&p);
	if (ret != 0)
	{
		printf("getMen err:%d\n", ret);
		return ret;
	}
	printf("p = %s\n", p);

	if (p != NULL)
	{
		free(p);
		p = NULL;
	}


	printf("\n");
	return 0;
}
#endif