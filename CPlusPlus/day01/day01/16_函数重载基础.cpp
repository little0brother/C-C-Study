// ��������: ��������ͬ �����б�ͬ(1.�������Ͳ�ͬ  2.����������ͬ  3.����˳��ͬ)
// ����ֵ������Ϊ�������صı�׼

#include <iostream>
using namespace std;

void myPrint(int a)
{
	cout << a << endl;
}

void myPrint(string a)
{
	cout << a << endl;
}

void myPrint(int a, int b)
{
	cout << a << b << endl;
}

int main1()
{
	// ���غ����ĵ���
	myPrint(1);
	myPrint("12");
	myPrint(2, 3);

	return 0;
}

////////////////////////////////////////////////////////////////////
// ����Ĭ�ϲ����ͺ���������һ��

void myfunc(int a, int b, int c = 0)
{
	cout << a << b << c << endl;
}

void myfunc(int a, int b)
{
	cout << a << b << endl;
}

int main()
{
	//myfunc(1, 2);   //err ��������ʱ�����������

	return 0;
}