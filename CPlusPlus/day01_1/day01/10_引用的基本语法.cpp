#include <iostream>
using namespace std;

// ���ã���һ���ڴ�ռ������
// ���ʣ���һ��ָ�볣����int& aRef = a; // int* const aRef = &a;
// �﷨��Type &���� = ԭ��
void test01()
{
	int a = 10;
	int& b = a;
	b = 20;

	cout << "a = " << a << endl;
}

// 1.���ñ���Ҫ��ʼ��
void test02()
{
	int a = 10;
	//int& b;	err
	int& b = a;

	// 2.һ����ʼ���� �Ͳ������޸�ָ����
	int c = 20;
	b = c;	// ��ֵ

	cout << "a:" << a << "b:" << b << "c:" << c << endl;
}

// ���������������
void test03()
{
	int arr[10];


	// 1.ֱ�ӽ�������
	int(&pArr)[10] = arr;

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << pArr[i] << endl;
	}


	// 2.�ȶ��崦�������ͣ��ٶ�������
	typedef int(ARRAY_TYPE)[10];

	// �﷨��Type &���� = ԭ��
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