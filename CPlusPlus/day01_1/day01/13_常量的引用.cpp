#include <iostream>
using namespace std;

void test01()
{
	//int& ref = 10;	// ���ñ�����һ��Ϸ����ڴ�ռ�
	const int& ref = 10; // ���Ǽ���const֮���﷨��ͨ���ˣ��������Ż��������� int temp = 10; const int& ret = tmp;
	
	//ref = 20;	// ����ֱ���޸�

	int* p = (int*)&ref;
	*p = 100;
	cout << ref << endl;
}

// �������� ʹ�ó��� ���κ����е��β� ��ֹ�����
void showValue(const int& a)
{
	//a = 10000; // �ڴ�ֵʱ������const��ֹ�����
	cout << a << endl;
}

void test02()
{
	int a = 100;
	showValue(a);
}

int main()
{
	//test01();
	test02();

	return 0;
}