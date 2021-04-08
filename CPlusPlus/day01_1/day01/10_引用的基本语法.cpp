#include <iostream>
using namespace std;

// 引用：给一个内存空间起别名
// 本质：是一个指针常量，int& aRef = a; // int* const aRef = &a;
// 语法：Type &别名 = 原名
void test01()
{
	int a = 10;
	int& b = a;
	b = 20;

	cout << "a = " << a << endl;
}

// 1.引用必须要初始化
void test02()
{
	int a = 10;
	//int& b;	err
	int& b = a;

	// 2.一旦初始化后 就不可以修改指向了
	int c = 20;
	b = c;	// 赋值

	cout << "a:" << a << "b:" << b << "c:" << c << endl;
}

// 建立对数组的引用
void test03()
{
	int arr[10];


	// 1.直接建立引用
	int(&pArr)[10] = arr;

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << pArr[i] << endl;
	}


	// 2.先定义处数组类型，再定义引用
	typedef int(ARRAY_TYPE)[10];

	// 语法：Type &别名 = 原名
	ARRAY_TYPE& pArr2 = arr;

	for (int i = 0; i < 10; i++)
	{
		cout << pArr2[i] << endl;
	}

}

int main()
{
	//test01();
	//test02();
	test03();

	return 0;
}