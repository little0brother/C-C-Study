#include <iostream>
#include <string>
using namespace std;

// 1.��const���εı���ȡ��ַʱ���������ʱ�ڴ�
void test01()
{
	const int m_A = 10;
	int* p = (int*)&m_A;
}

// 2.constǰ������ extern �ؼ��ֺ�Ҳ������ڴ�

// 3.ʹ�ñ�����ʼ��const���εı���
void test02()
{
	int a = 10;
	const int m_A = a;

	int* p = (int*)&m_A;

	*p = 20;
	cout << m_A << endl;
}

// 4.�����Զ����������ͣ�Ҳ������ڴ�
struct Person
{
	string name;
	int age;
};

void test03()
{
	const Person p;
	// ������ֱ���޸�
	//p.age = 100;
	//p.name = "aaa";

	Person* pp = (Person*)&p;
	pp->name = "bbbb";
	pp->age = 10;

	cout << pp->name << "  " << pp->age << endl;
}

int main()
{
	//test02();
	test03();

	return 0;
}