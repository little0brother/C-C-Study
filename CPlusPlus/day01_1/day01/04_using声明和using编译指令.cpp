#include <iostream>
using namespace std;

namespace KingGlory
{
	int sunwukongId = 1;
}

void test01()
{
	//int sunwukongId = 2;

	// 1.using ����
	// ���ͽ�ԭ�� �� using����ͬʱ����ʱ����Ҫ���������
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

	// 2.using����ָ��
	using namespace KingGlory;
	using namespace LOL;

	// ����оͽ�ԭ����� ����ʹ�þͽ�ԭ��
	cout << "sunwukongId = " << sunwukongId << endl;

	// ���using����ָ�� ���ڶ��������ͬ�����֣���Ҫ������������
	cout << "sunwukongId = " << LOL::sunwukongId << endl;
}

int main()
{
	test02();

	return 0;
}