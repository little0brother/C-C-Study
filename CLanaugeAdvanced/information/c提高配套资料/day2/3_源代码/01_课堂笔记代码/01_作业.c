#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_mem(int size)
{
	char *p2 = NULL;            //����4���ֽڵ��ڴ� ջ��Ҳ����ʱ��
	p2 = (char *)malloc(size);

	return p2;
}

int main(void)
{
	char buf[100];
	int a = 10;     //����4���ֽڵ��ڴ� ջ��Ҳ����ʱ��
	int *p;         //����4���ֽڵ��ڴ�
	p = &a;

	*p = 20;

	char *mp = get_mem(100);
	strcpy(mp, "ABCDEFG");

	if (mp != NULL)
	{
		printf("before = %d\n", mp);
		free(mp); //����ϵͳ��mpԭ��ָ���ڴ���Ա�����ʹ��

		printf("after = %d\n", mp);
		//�ͷ��꣬mp����Ұָ�룬���Ǳ���֮ǰ�ĵ�ַ����ø�ֵΪNULL
		mp = NULL;
	}

	printf("\n");
	system("pause");
	return 0;
}
