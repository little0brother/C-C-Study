#include <iostream>
using namespace std;

int atk = 1000;

void test()
{
	int atk = 2000;
	cout << "�ֲ�������Ϊ��" << atk << endl;

	// :: ����������� ��::ǰ��û���κ������������£�����ʹ��ȫ��������
	cout << "ȫ�ֹ�����Ϊ��" << ::atk << endl;
}

int main()
{
	test();

	return EXIT_SUCCESS;
}