#include <iostream>
using namespace std;

// 1. ������ջ���� ���ܳ�Ϊ�������õĳ�ʼֵ
int getAA1()
{
	int a;
	a = 10;

	return a;
}

// ����a���ڴ�ռ�  ����a��һ������
int& getAA2()
{
	int a;		// ����Ƿ���ջ�ϵ����� ���ܻ������
	a = 10;

	return a;
}

int* getAA3()
{
	int a;
	a = 10;

	return &a;
}

int main1()
{
	int a1 = getAA1();

	int a2 = getAA2();	// �Ὣ���صľ�����ֵ���д洢

	// getAA2()�ķ���ֵΪһ�����ñ����� �ڴ˺������н����� ���ͷ�ԭ���ں�����������ڴ�ռ䣬���Է��ص�����û��ָ����õ��ڴ�ռ�
	int& a3 = getAA2();  // �Ὣ���صĵ�ַ���д洢

	printf("a1:%d, a2:%d, a3:%d\n", a1, a2, a3);
	printf("a1:%d\n", a1);
	printf("a2:%d\n", a2);
	printf("a3:%d\n", a3);

	return 0;
}


// 2.������static ������ȫ�ֱ���

int j()
{
	static int a = 10;
	a++;

	return a;
}

int& jj()
{
	static int a = 10;
	a++;

	return a;
}

// �����ؾ�̬������ȫ�ֱ���
// ���Գ�Ϊ�������õĳ�ʼֵ
// ������Ϊ��ֵʹ�� Ҳ����Ϊ��ֵʹ��

int main2()
{
	int a1 = 10;
	int a2 = 10;

	a1 = j();

	a2 = jj();

	int& a3 = jj();

	printf("a1:%d\n", a1);
	printf("a2:%d\n", a2);
	printf("a3:%d\n", a3);

	return 0;
}

/////////////////////////////////////////////////

// 3.��������ֵ
int fun()	// ���ر�����ֵ
{
	static int b = 10;

	return b;
}

int& fun1()	 // ���ر����������ر�����ָ����ڴ�ռ䣩
{
	static int b = 10;

	printf("b:%d\n", b);

	return b;
}

int main()
{
	//fun() = 100;	 // err
	fun1() = 111;	// �൱�� ==>  b = 100;   ��������ֵ ��һ������ ���ҵ���ֵ
	fun1();

	int c = fun1(); // ����ֵ

	return 0;
}