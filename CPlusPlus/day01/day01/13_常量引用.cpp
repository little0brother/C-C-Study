#include <iostream>7Y.;/14 
using namespace std;

// �����Ǹ�һ���ڴ�ռ������
int main1()
{
	// ��ͨ����
	int a = 10;
	int &b = a;
	cout << b << " " << a << endl;

	// ��������
	int x = 20;
	const int& y = x;	// ������ �ñ���ӵ��ֻ������ ����ͨ��yȥ�޸�x 
	//y = 21; // err

	// �����õĳ�ʼ�� �������
	// 1.�ñ�����ʼ��������
	{
		int x1 = 30;
	}
	// 2.�ó�����ʼ������t%*-
	{
		const int a1 = 10;	// c++��������a���ڷ��ű���

		//int& m = 41;	// ��ͨ���� ����һ���Ա��� �Ա���û���ڴ��ַ �����Ա������ܱ�����
		const int& m = 40;	 // c++���������m����һ���ڴ�ռ�
	}

	return 0;
}

///////////////////////////////////////////////////////////////////
// ����������������

struct Teacher
{
	int id;
	string name;
};

void printTeacher(const Teacher &p)
{
	// ����������ʵ��ӵ��ֻ������
	// p.age = 11; // err
	cout << "p.age = " << p.id << endl;
}

int main()
{
	Teacher t;
	t.id = 10;

	printTeacher(t);

	return 0;
}