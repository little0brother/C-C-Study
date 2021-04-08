#include <stdio.h>


typedef struct MyStruct
{
	int a;
	int b;
}MyStruct;

void fun(MyStruct* p)
{
	// ָ���ܱ�
	p = NULL;  //ok
	// ָ��ָ���ڴ�Ҳ�ɸı�
	p->a = 10; //ok
}

void fun1(MyStruct const* p)
{
	p = NULL; //ok
	//p->a = 10; //err
}

void fun2(MyStruct * const p)
{
	//p = NULL; //err
	p->a = 10;; //ok
}

// ֻ��
void fun3(MyStruct const* const p)
{
	//p = NULL; //err
	//p->a = 10; //err

	MyStruct tmp;
	tmp.a = p->a;
}




int main(void)
{
	// const����һ������Ϊֻ��
	const int a = 10;
	//a = 100;   // err

	// ָ�������ָ��ָ����ڴ棬2����ͬ����
	char buf[] = "fdafdaa";

	// �������ҿ����������ͣ��������ĸ��ַ�
	// �����*��˵��ָ��ָ����ڴ治���޸� (����ͨ��ָ���޸�ָ���ڴ������)
	// �����ָ�������˵��ָ���ָ���ܸı䣬ָ���ֵ�����޸�
	const char* p = buf;
	// �ȼ������� char const *p1 = buf;

	// p[1] = '2';  //err ����ͨ��ָ���޸�ָ���ڴ������
	p = "fuoiunblj";  //ok

	
	char* const p1 = buf;
	p1[1] = '3';   //ok
	//p1 = "uijrewlr";  //err


	// p2Ϊֻ����ָ���ܱ䣬ָ����ڴ治�ܱ�
	const char* const p2 = buf;


	// ����������� .c �е� const ����
	extern const int aa;  // �����ٸ�ֵ��ֻ������
	printf("aa = %d\n", aa);

	// const���εı���������ʱ��ʼ��
	const int b;
	//b = 10; //err

	// ��c�����У�const��ð�ƻ�������ͨ��ָ�����޸�
	const int b1 = 10;
	//b = 100; // err
	int* q = &b;
	*q = 11; //ok
	printf("%d, %d\n", b1, *q);

	printf("\n");
	return 0;
}