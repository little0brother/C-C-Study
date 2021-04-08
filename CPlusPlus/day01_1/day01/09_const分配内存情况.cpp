#include <iostream>
#include <string>
using namespace std;

// 1.对const修饰的变量取地址时，会分配临时内存
void test01()
{
	const int m_A = 10;
	int* p = (int*)&m_A;
}

// 2.const前加入了 extern 关键字后，也会分配内存

// 3.使用变量初始化const修饰的变量
void test02()
{
	int a = 10;
	const int m_A = a;

	int* p = (int*)&m_A;

	*p = 20;
	cout << m_A << endl;
}

// 4.对于自定义数据类型，也会分配内存
struct Person
{
	string name;
	int age;
};

void test03()
{
	const Person p;
	// 不可以直接修改
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