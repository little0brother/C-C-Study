#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	�ַ����������ֳ�������ȫ��������������ͷţ������ַ�����ͬ�Ļ���ָ���ָ��ͬһ��ַ��������ͬ��
*/

char* get_str1()
{
	char* p = "abcdefg";	// ���ֳ�����

	return p;
}

char* get_str2()
{
	char* q = "abcdefg";	// ���ֳ�����

	return q;
}


int main(void)
{
	char* p = NULL;
	char* q = NULL;

	p = get_str1();
	// %s: ָ��ָ���ڴ����������
	// %d: ��ӡp�����ֵ
	printf("p = %s, p = %d\n", p, p);

	q = get_str2();
	printf("q = %s, q = %d\n", q, q);

	printf("\n");
	return 0;
}