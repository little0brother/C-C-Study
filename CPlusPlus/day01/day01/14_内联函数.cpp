#include<iostream>
using namespace std;

// �������� �������� c������ �궨��Ĵ���Ƭ��

#define MYFUN(a, b) ((a) > (b) ? (a) : (b))


// ���������ĺ���ͷ����ͺ�������һ�� ��������������
inline int myfunc(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int a = 2;
	int b = 3;

	// ������ֱ�ӽ���������뵽�������õ�λ��
	myfunc(a, b);
	//{
	//	return a > b ? a : b;
	//}

	cout << MYFUN(a, b) << endl;

	return 0;
}