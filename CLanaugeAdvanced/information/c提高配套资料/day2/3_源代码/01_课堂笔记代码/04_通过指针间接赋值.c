#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_a()
{
	int a = 10;

	return a;
}

void get_a2(int b)
{
	b = 22;
}

void get_a3(int *p)
{	
	*p = 33; //ͨ��*�����ڴ�
}

void get_a4(int *a1, int *a2, int *a3, int *a4)
{
	*a1 = 1;
	*a2 = 2;
	*a3 = 3;
	*a4 = 4;
}



int main01(void)
{
	int a = 100;	//��������
	int *p = NULL;

	//������ϵ
	//ָ��ָ��˭���Ͱ�˭�ĵ�ַ��ֵ��ָ��
	p = &a;

	//ͨ��*�����ڴ�
	*p = 22;

	/*ͨ��ָ���Ӹ�ֵ
	1����������
	2��������ϵ
	3��ͨ��*�����ڴ�
	*/

	int b = get_a();
	printf("b ===== %d\n", b);

	get_a2(b);
	printf("b2 ===== %d\n", b);

	//�����ͨ���βθı�ʵ�ε��ڴ����ݣ�ֵ���������ַ����
	//ʵ�Σ��β�
	get_a3(&b); //�ں�������ʱ��������ϵ
	printf("b3 ===== %d\n", b);

	int a1, a2, a3, a4;
	get_a4(&a1, &a2, &a3, &a4);
	printf("a1 = %d��a2 = %d, a3 = %d, a4 = %d\n", a1, a2, a3, a4);

	printf("\n");
	system("pause");
	return 0;
}

void fun2(int *p)
{
	p = 0xaabb;
	printf("fun2:p = %p\n", p);
}

void fun3(int **p)
{
	*p = 0xeeff;
}

int main(void)
{
	//һ��������Ӧ�ö���һ����ô���͵�ָ�뱣�����ĵ�ַ
	//��ԭ�����ͻ����ϼ�һ��*
// 	int a = 10;
// 	int *p = &a;
// 	int **q = &p;
// 
// 	int ************t = NULL;
// 	int * ************t2 = &t;

	int *p = 0x1122;
	printf("p1 = %p\n", p);


	fun2(p); //ֵ����
	printf("p2 = %p\n", p);

	fun3(&p); //��ַ����
	printf("p2 = %p\n", p);


	printf("\n");
	system("pause");
	return 0;
}