#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fun(char *p /* in */)
{
	//��pָ����ڴ����򿽱�
	strcpy(p, "abcddsgsd");
}

void fun2(char *p)
{
	if (p == NULL)
	{
		return;
	}

	//��pָ����ڴ����򿽱�
	strcpy(p, "abcddsgsd");
}

void fun3(char **p /* out */, int *len)
{
	if (p == NULL)
	{
		return;
	}

	char *tmp = (char *)malloc(100);
	if (tmp == NULL)
	{
		return;
	}
	strcpy(tmp, "adlsgjldsk");

	//��Ӹ�ֵ
	*p = tmp;
	*len = strlen(tmp);


}

int main(void)
{
	//���룬�������������ڴ�
	char buf[100] = { 0 };
	fun(buf);
	printf("buf  = %s\n", buf);

	char *str = NULL;
	fun2(str);

	//����������ú��������ڴ棬��ַ����
	char *p = NULL;
	int len = 0;
	fun3(&p, &len);
	if (p != NULL)
	{
		printf("p = %s, len = %d\n", p, len);
	}



	printf("\n");
	system("pause");
	return 0;
}