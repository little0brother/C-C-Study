#include <iostream>
using namespace std;

// 1.ȫ�ֱ����ļ����ǿ
// �ض��� err
//int a;
//int a = 10;

// 2.���������ǿ ���βα������ͼ����ǿ�����������ķ���ֵ��ǿ�������ķ���ֵ�����ǿ������ʱ����������������ǿ��
int getRectS(int w, int h)
{
	return w * h;
}

void test02()
{
	// 
	//getRectS(10, 10, 10);
}

// 3.����ת�������ǿ
void test03()
{
	char* p = (char*)malloc(64);
}

// 4.struct��ǿ
struct Person
{
	int age;
	void func() { age++; }; //C++�����£��ṹ����Էź���
};

void test04()
{
	Person p1;   // c++�����£������ṹ��ʱ ���Բ���struct�ؼ���
	p1.age = 17;
	p1.func();

	cout << "p������" << p1.age << endl;
}

// 5.bool������ǿ  C++��������bool����
// bool ������� ��true--1 ��false--0
bool flag = false;

void test05()
{
	cout << "sizeof bool = " << sizeof(bool) << endl;
	flag = 100;
	cout << flag << endl;
}

// 6.��Ŀ�������ǿ
void test06()
{
	int a = 10;
	int b = 20;

	printf("ret = %d\n", a > b ? a : b);

	a > b ? a : b = 100;  // b = 100;   c++���������ֵ�Ǳ���

	printf("a = %d\n", a);
	printf("b = %d\n", b);
}

// 7.const��ǿ
const int m_A = 100;  // ȫ��const���α��� �ܵ���������������ʹ�﷨ͨ�������н׶λᱨ��
void test07()
{
	// m_A = 200;
	//int* p = (int*)&m_A;
	//*p = 200;

	const int m_B = 100;	// �ֲ�const����ڷ��ű��� �ڽ���ȡ��ַ����ʱ��������ʱ����������Ӱ�챾���ֵ
	//m_B = 200;
	int* p2 = (int*)&m_B;
	*p2 = 200;
	cout << "m_B = " << m_B << endl;

	int arr[m_B];	// ����������ʼ������ ����
}

int main()
{
	return 0;
}