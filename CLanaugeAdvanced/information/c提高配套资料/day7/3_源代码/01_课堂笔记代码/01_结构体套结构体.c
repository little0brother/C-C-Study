#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct A
{
	int a;
	int b;
	char *p;
}A;


/*
1���ṹ�����Ƕ������һ���ṹ����κ����ͱ���
2���ṹ��Ƕ�ױ��ṹ����ͨ�����������ԣ�
	���ṹ������ʹ�С�޷�ȷ�������ͱ��ʣ��̶���С�ڴ�����
3���ṹ��Ƕ�ױ��ṹ��ָ����������ԣ�
	ָ������Ŀռ���ȷ����32λ�� 4�ֽڣ� 64λ�� 8�ֽ�
*/
typedef struct B
{
	int a;
	A tmp1; //ok
	A *p1; //ok

	//struct B tmp2; 
	struct B *next; //32λ�� 4�ֽڣ� 64λ�� 8�ֽ�	
}B;

int main(void)
{
	

	printf("\n");
	system("pause");
	return 0;
}