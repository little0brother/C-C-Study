#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add(int a, int b)
{
	return a + b;
}

//17:11
int minus(int a, int b)
{
	return a - b;
}

//�����Ĳ����Ǳ����������Ǻ���ָ�������
//��ܣ��̶������� 17��10
//��̬�� ������̬������ͬһ�ӿڣ���һ������
void fun(int x, int y,  int(*p)(int a, int b) )
{
	printf("fun11111111\n");

	int a = p(x, y); //�ص����� add(1,2)
	printf("a = %d\n", a);
}

typedef int(*Q)(int a, int b); //����ָ������
void fun2(int x, int y, Q p)
{
	printf("fun11111111\n");

	int a = p(x, y); //�ص����� add(1,2)
	printf("a = %d\n", a);
}


int main(void)
{
	//fun(1, 2, add);

	fun2(10, 5, minus);

	printf("\n");
	system("pause");
	return 0;
}