#include <iostream>
using namespace std;

int main()
{
	bool b1 = true;	// ����c++����������һ���ֽڵ��ڴ�

	bool b2, b3, b4; // ����������� ���ܻ����ͬһ���ֽ���

	cout << "sizeof(bool)=" << sizeof(bool) << endl;

	// bool�� 1 �� 0
	b1 = 10;
	cout << "bool:" << b1 << endl;
	b1 = 0;
	cout << "bool:" << b1 << endl;

	return 0;
}