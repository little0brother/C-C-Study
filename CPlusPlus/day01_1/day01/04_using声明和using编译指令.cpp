#include <iostream>
using namespace std;

namespace KingGlory
{
	int sunwukongId = 1;
}

void test01()
{
	//int sunwukongId = 2;

	// 1.using 声明
	// 当就近原则 和 using声明同时出现时，需要避免二义性
	using KingGlory::sunwukongId;

	cout << "sunwukongId = " << sunwukongId << endl;
}

namespace LOL
{
	int sunwukongId = 3;
}

void test02()
{
	int sunwukongId = 2;

	// 2.using编译指令
	using namespace KingGlory;
	using namespace LOL;

	// 如果有就近原则出现 优先使用就近原则
	cout << "sunwukongId = " << sunwukongId << endl;

	// 如果using编译指令 存在多个并且有同名出现，需要加作用域区分
	cout << "sunwukongId = " << LOL::sunwukongId << endl;
}

int main()
{
	test02();

	return 0;
}