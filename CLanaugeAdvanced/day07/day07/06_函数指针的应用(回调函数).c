#include <stdio.h>
#include <string.h>

int add(int a, int b)
{
	return a + b;
}

int minus(int a, int b)
{
	return a - b;
}

// �����Ĳ����Ǳ���, �����Ǻ���ָ�������
// ��ܣ��̶�������17��10
// ��̬��������̬������ͬһ�ӿڣ���һ���ı���
void fun(int x, int y, int(*p)(int a, int b))
{
	printf("fun1111111\n");

	int a = p(x, y); // �ص����� add(1, 2) minus(10, 5);
	printf("a = %d\n", a);
}

typedef int(*Q)(int a, int b);  // ����ָ������
void fun1(int x, int y, Q p)
{
	printf("fun1111111\n");

	int a = p(x, y); // �ص����� add(1, 2) minus(10, 5);
	printf("a = %d\n", a);
}

int main()
{
	fun(1, 2, add);

	fun(10, 5, minus);

	fun1(2, 1, minus);

	return 0;
}