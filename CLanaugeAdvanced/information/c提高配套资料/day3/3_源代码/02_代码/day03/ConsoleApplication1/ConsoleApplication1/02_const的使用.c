#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MyStruct
{
	int a;
	int b;
}MyStruct;

void fun(MyStruct *p)
{
	//ָ���ܱ�
	//p = NULL;
	//ָ��ָ����ڴ�Ҳ���Ա�
	//p->a = 10; //ok
}

void fun1(MyStruct const *p)
{
	//p = NULL; //ok
	//p->a = 10; //err
}

void fun2(MyStruct  * const p)
{
	//p = NULL; //err
	p->a = 10;//ok
}

//pֻ��
void fun3(MyStruct const * const p)
{
	MyStruct tmp;
	tmp.a = p->a;
}

int main(void)
{
	//const����һ������Ϊֻ��
	const int a = 10;
	//a = 100; //err

	//ָ������� ָ��ָ����ڴ棬 2����ͬ����
	char buf[] = "aklgjdlsgjlkds";

	//�������ҿ����������ͣ��������ĸ��ַ�
	//�����*�� ˵��ָ��ָ����ڴ治�ܸı�
	//�����ָ�������˵��ָ���ָ���ܸı䣬ָ���ֵ�����޸�
	const char *p = buf;
	// �ȼ������� char const *p1 = buf;
	//p[1] = '2'; //err
	p = "agdlsjaglkdsajgl"; //ok

	char * const p2 = buf;
	p2[1] = '3';
	//p2 = "salkjgldsjaglk"; //err

	//p3Ϊֻ����ָ���ܱ䣬ָ����ڴ�Ҳ���ܱ�
	const char * const p3 = buf;

	//�����������.c��const�������˽�
	extern const int aa; //�����ٸ�ֵ��ֻ������
	printf("aa = %d\n", aa);

	//const���εı���������ʱ��ʼ��

	//��c������, const��һ��ð�ƻ�
	const int b = 10;
	//b = 100; //err
	int *q = &b;
	*q = 22;
	printf("%d, %d\n", b, *q);


	printf("\n");
	system("pause");
	return 0;
}