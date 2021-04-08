#include <stdio.h>
#include <stdlib.h>

void fun(char* p /* in */)
{
	// 给p指向的内存区域拷贝
	strcpy(p, "abdfcsre");
}

void fun2(char* p)
{
	if (p == NULL)
	{
		return;
	}
	// 不能够给空，或未知的内存地址赋值
	strcpy(p, "fdafda");
}

void fun3(char** p /* out */, int* len)
{
	if (p == NULL)
	{
		return;
	}

	char* tmp = (char*)malloc(100);
	if (tmp == NULL)
	{
		return;
	}
	strcpy(tmp, "fdadffddf");

	// 间接赋值
	*p = tmp;
	*len = strlen(tmp);
}

int main(void)
{
	// 输入，主调函数分配内存
	char buf[100] = { 0 };
	fun(buf);
	printf("buf = %s\n", buf);

	// 不能给空地址赋值，因为是野指针
	char* str = NULL;
	fun2(str);

	// 输出，被电泳函数分配内存，要使用地址传递
	char* p = NULL;
	int len = 0;
	fun3(&p, &len);
	if (p != NULL)
	{
		printf("p = %s, len = %d\n", p, len);
	}

	printf("\n");
	return 0;
}