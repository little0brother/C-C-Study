#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ָ�뺯��
//()���ȼ���*�ߣ����Ǻ���������ֵ��ָ�����͵ĺ���
//����ָ�����͵ĺ���
int *fun2()
{
	int *p = (int *)malloc(sizeof(int));

	return p;
}

int fun(int a)
{
	printf("a ========== %d\n", a);

	return 0;
}

int main(void)
{
	//����ָ�룬����ָ�룬ָ������ָ��
	//���庯��ָ�������3�ַ�ʽ
	//1���ȶ��庯�����ͣ��������Ͷ���ָ������������ã�
	//��typedef�����ͣ�û���±���
	typedef int FUN(int a); //FUN��������
	FUN *p1 = NULL; //����ָ�����
	//p1 = &fun;
	p1 = fun; //p1 ָ�� fun����
	fun(5); //��ͳ����
	p1(6); //����ָ��������÷�ʽ

	//2���ȶ��庯��ָ�����ͣ��������Ͷ���ָ����������ã�
	typedef int(*PFUN)(int a); //PFUN, ����ָ������
	PFUN p2 = fun; //p2 ָ�� fun
	p2(7);

	//3��ֱ�Ӷ��庯��ָ�루���ã�
	int(*p3)(int a) = fun;
	p3(8);

	int(*p4)(int a);
	p4 = fun;
	p4(9);



	printf("\n");
	system("pause");
	return 0;
}