#include <iostream>
using namespace std;

// 1 文件iostream中 没有引入标准的std， 需要手工写
// 2 如果不写using namespace std; 需要显示的引入std

int main01()
{
	cout << "namespace test" << endl;
	std::cout << std::endl;

	return 0;
}

// 3 定义命名空间
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

// 4 使用命名空间
int main()
{
	// 使命命名空间 namespaceA
	using namespace namespaceA;
	using namespace namespaceB;
	cout << namespaceA::a << endl;
	cout << namespaceB::a << endl;

	// 显示的定义
	namespaceB::namespaceC::Teacher t1;
	t1.age = 30;

	// 
	using namespaceB::namespaceC::Teacher;
	Teacher t2;
	t2.age = 40;

	return 0;
}