#include <iostream>
using namespace std;

void myfun(int a)
{
	cout << a << endl;
}

void myfun(char* a)
{
	cout << a << endl;
}

void myfun(int a, int b)
{
	cout << a << endl;
}

void myfun(int a, float b)
{
	cout << a << endl;
}

// ����ָ��Ļ����﷨
// ����һ���������� 
typedef void (myTypeFunc)(int a, int b);
//myTypeFunc* myfunp = NULL;  // ����һ������ָ�� ���ָ��ָ��������ڵ�ַ

// ����һ������ָ������  
typedef void (*myPTypeFunc)(int a, int b); // ������һ��ָ�����������
//myPTypeFunc myfunp = NULL;  // ͨ������ָ�����Ͷ�����һ������ָ��

// ����һ������ָ�����
void (*myVarPFunc)(int a, int b);

int main()
{
	myPTypeFunc fp;   // ������һ������ָ�����

	fp = myfun;  // �����غ����ĺ�����ڵ�ַ����fp  ֻ��ƥ������б�Ϊ���������ĺ��� ��Ϊ����ָ��Ϊ��������

	fp(1, 2);
	fp(1, 2.0);

	return 0;
}