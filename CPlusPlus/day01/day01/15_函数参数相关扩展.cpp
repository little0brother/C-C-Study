#include <iostream>
using namespace std;

// ������д������Ĭ�� ��д����ʹ����д�Ĳ���
// ��Ĭ��ֵ�Ĳ��� ����λ����Ĭ��ֵ�����ĺ�
void myPrint(int m, int x = 3, int y = 4 /*int m /err*/)
{
	cout << "x = " << x << endl;
}

int main1()
{
	//myPrint();
	myPrint(4);

	return 0;
}

/////////////////////////////////
// ����ռλ����

// ��������ʱ����д����������
void fun(int a, int b, int)
{
	cout << "a = " << a << "b = " << b << endl;
}

int main2()
{
	//fun(1, 2);  //err

	fun(1, 2, 3);

	return 0;
}

/////////////////////////////////////
// Ĭ�ϲ�����ռλ����һ��

void fun2(int a, int b, int = 0)
{
	cout << "a = " << a << " b = " << b << endl;
}

int main()
{
	fun2(1, 2);
	fun2(1, 2, 3);

	return 0;
}