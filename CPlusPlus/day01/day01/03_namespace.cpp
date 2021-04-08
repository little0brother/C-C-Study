#include <iostream>
using namespace std;

// 1 �ļ�iostream�� û�������׼��std�� ��Ҫ�ֹ�д
// 2 �����дusing namespace std; ��Ҫ��ʾ������std

int main01()
{
	cout << "namespace test" << endl;
	std::cout << std::endl;

	return 0;
}

// 3 ���������ռ�
namespace namespaceA
{
	int a = 10;
}

namespace namespaceB
{
	int a = 20;

	namespace namespaceC
	{
		struct Teacher
		{
			char name[32];
			int age;
		};
	}
}

// 4 ʹ�������ռ�
int main()
{
	// ʹ�������ռ� namespaceA
	using namespace namespaceA;
	using namespace namespaceB;
	cout << namespaceA::a << endl;
	cout << namespaceB::a << endl;

	// ��ʾ�Ķ���
	namespaceB::namespaceC::Teacher t1;
	t1.age = 30;

	// 
	using namespaceB::namespaceC::Teacher;
	Teacher t2;
	t2.age = 40;

	return 0;
}