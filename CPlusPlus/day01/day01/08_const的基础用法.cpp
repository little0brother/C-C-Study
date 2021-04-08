#include <iostream>
using namespace std;

// 1. 
// c++�е�const������ͨ���κ��ֶ��޸�ֵ�� c�����е�const����ͨ����Ӹ�ֵ�ķ�ʽ�޸�ֵ

// 2.ԭ�����
// c++��������ʶ��const֮�󣬾ͻὫ�ñ����ü�ֵ�Եķ�ʽ�洢�����ű���
// �����ͨ��*pȥ���øõ�ַ�����Զ�����һ���µ��ڴ�ռ䣬����Ӱ�쵽���ű��е�����

// 3.const �����ڴ��ʱ���������������ڼ�

struct Teacher
{
	char name[64];
	int age;
};

// ָ��ָ����ڴ�ռ䲻�ܱ��޸�
int operatorTeacher01(const Teacher* pT) 
{
	//pT->age = 10;  // err
	return 0;
}

// ָ����������ܱ��޸�
int operatorTeacher02(Teacher* const pT)
{
	pT->age = 10;
	//pT = NULL; // err
	return 0;
}

int operatorTeacher03(const Teacher * const pT)
{
	//pT->age = 10;	// err
	//pT = NULL; // err
	printf("age:%d\n", pT->age);
	return 0;
}

int main1()
{
	//const int a = 1;
	//int const b = 1;	// ������ͬ

	//const int* c = &a;	// const ���ε���ָ����ָ����ڴ�ռ䣬���ܱ��޸�
	//int* const d = &a;	// const ���ε��Ǳ���������ָ���ָ���ܱ��޸�
	//const int* const e = &a; // const ���α�����ָ�룬����ָ������ָ����ڴ��ַ�������޸�

	cout << "hello" << endl;

	//Teacher t1;
	//t1.age = 33;
	//operatorTeacher03(&t1);

	// 1. 
	// c++�е�const������ͨ���κ��ֶ��޸�ֵ�� c�����е�const����ͨ�����·�ʽ�޸�ֵ
	const int a = 10;
	int* p = NULL;
	p = (int*)&a;
	*p = 20;
	cout << "a = " << a << endl;

	return 0;
}

// 3.const �����ڴ��ʱ���������������ڼ�
void main2()
{
	int a;
	const int b = 10;
	int c;

	printf("&a: %d, &b: %d, &c: %d\n", &a, &b, &c);

}

// 4. const �� #define��֮ͬ��

// �ڱ���Ԥ����׶ν��д���
// const �������ɱ���������ģ��ṩ���ͼ�����������
#define d 20
void main3()
{
	int a = 10;
	int b = 20;
	//int array[a + b];	// err   liunx�ں��п���ʹ�ã���Ϊlinux�ں˵ı�����֧��
						// c��c++������������֧�������﷨

	const int c = 10;
	//const int d = 20;
	int array1[c + d]; // ���Ա���ͨ��
}

// 5 const����ĳ������ɱ����������ṩ���ͼ�����������
void fun1()
{
#define a 10
	const int b = 20;	// ֻ��������������Ч
//#undef a ж�غ궨�壬�����·���Ч
}

void fun2()
{
	printf("a = %d\n", a);
	//printf("b = %d\n", b);
}

int main()
{
	fun1();
	fun2();

	return 0;
}