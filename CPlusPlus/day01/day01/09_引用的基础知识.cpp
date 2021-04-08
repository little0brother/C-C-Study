#include <iostream>
using namespace std;

// ���ʣ���һ��ָ�볣����int& aRef = a; // int* const aRef = &a;

// 1. ���õĻ�������
// ���Ѵ��ڱ�����ı���
int main1()
{
	int a = 10;

	// ���õ��﷨�� Type& name = var;
	
	int& b = a;
	
	b = 100; // �൱�ڰ�a�޸ĳ�100

	printf("b: %d\n", b);
	printf("a: %d\n", a);

	a = 200;

	printf("b: %d\n", b);
	printf("a: %d\n", a);

	return 0;
}

// 2.�������͵�����
// �޷����ֵ�Ľ���������ֵ����Ҫ�Ե�ַ����
void myswap(int a, int b)
{
	int c = a;
	a = b;
	b = c;
}

void myswap2(int* a, int* b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

// �������ý���ֵ�Ľ���
// a��x�ı���  b��y�ı���
void myswap3(int& a, int& b)
{
	int c;
	c = a;
	a = b;
	b = c;
}

int main2()
{
	int a = 10;
	int& b = a;
	//int& c;   // err ��ͨ���� ����Ҫ��ʼ��

	int x = 10;
	int y = 20;

	myswap(x, y);
	printf("x: %d, y: %d\n", x, y);

	myswap2(&x, &y);
	printf("x: %d, y: %d\n", x, y);

	myswap3(x, y);
	printf("x: %d, y: %d\n", x, y);

	return 0;
}

// ����������������������
struct Teacher
{
	char name[64];
	int age;
};

void printfT(Teacher *pT)
{
	cout << pT->age << endl;
}

// pT���βΣ�t1����һ�����ݸ�pT�� // ----> pT = t1;
void printfT2(Teacher pT)
{
	cout << pT.age << endl;

	pT.age = 21; // ����Ӱ�챾����ֵ
}

// pT��t1�ı���
void printfT3(Teacher& pT)
{
	cout << pT.age << endl;
	pT.age = 21;  // ���޸�t1ֵ
}

int main()
{
	Teacher t1;
	t1.age = 43;

	printfT(&t1);

	printfT2(t1);

	printfT3(t1);
	printf("t1->age: %d\n", t1.age);

	return 0;
}