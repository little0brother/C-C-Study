#include <iostream>
using namespace std;
#include "game1.h"
#include "game2.h"

// 1.�����ռ����;�����������ͻ
void test()
{
	LOL::goAtk();
	kingGlory::goAtk();
}

// 2.�����ռ��� ���Դ�ű������������ṹ�塢��....
namespace A
{
	int m_A = 10;
	void func() {};
	struct Person
	{
		int age;
	};

	class Animal
	{
		int age;
	};
}

// 3.�����ռ���������� ȫ����������
//void func()
//{
//	// err
//	/*namespace B
//	{
//
//	}*/
//}

// 4.�����ռ����Ƕ�������ռ�
namespace B
{
	int m_A = 10;

	namespace C
	{
		int m_A = 20;
	}
}
void test2()
{
	cout << "B�ռ��µ�m_A = " << B::m_A << endl;
	cout << "C�ռ��µ�m_A = " << B::C::m_A << endl;
}

// 5.�����ռ��ǿ��ŵģ�������ʱ�������ռ�������µĳ�Ա
namespace B
{
	int m_B = 100;
}
void test3()
{
	cout << "B�ռ��µ�m_A = " << B::m_A << endl;
	cout << "B�ռ��µ�m_B = " << B::m_B << endl;
}

// 6.�����ռ��������
namespace
{
	int m_C = 100;	// �൱��ȫ�ֱ���
	int m_D = 200;
	// �൱���ڱ���ǰ����һ���ؼ��� static
	// static int m_C = 100;
	// static int m_D = 200;
}
void test4()
{
	cout << "m_D = " << ::m_D << endl;
	cout << "m_D = " << m_D << endl;
}

// 7.�����ռ���������
namespace veryLongName
{
	int m_A = 1000;
}
void test5()
{
	namespace veryShortName = veryLongName;

	cout << veryShortName::m_A << endl;
	cout << veryLongName::m_A << endl;
}

int main()
{
	//test();
	//test2();
	//test3();
	//test4();
	test5();

	return 0;
}