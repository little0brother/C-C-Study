#include <stdio.h>
#include <stdlib.h>

void fun2(int *p)
{
	p = 0xaabb;
	printf("fun2: p=*p\n", p);
}

void fun3(int** p)
{
	*p = 0xeeff;
}

// ����ָ���Ӹ�ֵ
int main(void)
{
	//// һ��������Ӧ�ö���һ���������͵�ָ�뱣�����ĵ�ַ
	//// ��ԭ�����ͻ����ϼ�һ��*
	//int a = 10;
	//int* p = &a;
	//int** q = &p;

	//int******** t = NULL;
	//int********* t2 = &t;

	int* p = 0x1122;
	printf("p1 = %p\n", p);

	fun2(p);		// ֵ����
	printf("p2 = %p\n", p);

	fun3(&p);		// ��ַ����
	printf("p3 = %p\n", p);

	printf("\n");
	return 0;
}


#if(0)
int get_a()
{
	int a = 10;

	return a;
}

void get_a2(int b)
{
	b = 22;
}

void get_a3(int* p)
{
	*p = 22;	// ͨ��*�����ڴ�
}

void get_a4(int* a1, int *a2, int* a3, int *a4)
{
	*a1 = 1;
	*a2 = 2;
	*a3 = 3;
	*a4 = 4;
}

int main(void)
{
	/* ͨ��ָ���Ӹ�ֵ����
	*  1. ��������
	*  2. ������ϵ��ָ��ָ��˭���Ͱ�˭�ĵ�ַ����ָ��
	*  3. ͨ��*�����ڴ�
	*/

	int a = 100;		
	int* p = NULL;
	p = &a;
	*p = 2;


	int b = get_a();
	printf("b ===== %d\n", b);

	get_a2(b);
	printf("b2 ==== %d\n", b);

	// �����ͨ���βθı�ʵ�ε��ڴ����ݣ�ֵ���������ַ����
	// ʵ�Σ��β� ��������
	get_a3(&b);		// �ں�������ʱ��������ϵ
	printf("b3 ==== %d\n", b);

	int a1, a2, a3, a4;
	get_a4(&a1, &a2, &a3, &a4);
	printf("a1 = %d, a2 = %d, a3 = %d, a4 = %d\n", a1, a2, a3, a4);

	printf("\n");
	return 0;
}
#endif