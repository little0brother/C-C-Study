#include <iostream>
using namespace std;

// 1.ֵ����
void mySwap01(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

// 2.��ַ����
void mySwap02(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// 3.���ô���
void mySwap03(int& a, int& b) // int& a = a; int& b = b;
{
	int temp = a;
	a = b;
	b = temp;
}

// ���õ�ע������

// 1.��Ҫ���ؾֲ����������ã���Ϊ��ִ������ڴ�ռ����ͷţ����������ö���
int& myFunc()
{
	int a = 10;
	return a;
}
void test04()
{
	int& ret = myFunc();
	cout << "ret = " << ret << endl;	//�������Ż��˽��������ס֮ǰ������
}

// 2.��������ķ���ֵ�����ã���ô�������������Ϊ��ֵ��������
int& myFunc2()
{
	static int a = 10;
	return a;
}
void test05()
{
	int& ret = myFunc2();
	cout << "ret = " << ret << endl;	//�������Ż��˽��������ס֮ǰ������
	cout << "ret = " << ret << endl;
	cout << "ret = " << ret << endl;

	myFunc2() = 100;	// a = 100;
	cout << "ret = " << ret << endl;
	cout << myFunc2() << endl;

}

int main()
{
	int a = 10;
	int b = 20;

	//mySwap01(a, b);
	//mySwap02(&a, &b);
	//mySwap03(a, b);
	//test04();
	test05();

	/*cout << "a = " << a << endl;
	cout << "b = " << b << endl;*/

	return 0;
}