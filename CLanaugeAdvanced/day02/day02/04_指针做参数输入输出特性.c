#include <stdio.h>
#include <stdlib.h>

void fun(char* p /* in */)
{
	// ��pָ����ڴ����򿽱�
	strcpy(p, "abdfcsre");
}

void fun2(char* p)
{
	if (p == NULL)
	{
		return;
	}
	// ���ܹ����գ���δ֪���ڴ��ַ��ֵ
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

	// ��Ӹ�ֵ
	*p = tmp;
	*len = strlen(tmp);
}

int main(void)
{
	// ���룬�������������ڴ�
	char buf[100] = { 0 };
	fun(buf);
	printf("buf = %s\n", buf);

	// ���ܸ��յ�ַ��ֵ����Ϊ��Ұָ��
	char* str = NULL;
	fun2(str);

	// ���������Ӿ���������ڴ棬Ҫʹ�õ�ַ����
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