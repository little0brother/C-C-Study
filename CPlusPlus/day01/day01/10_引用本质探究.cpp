#include <iostream>
using namespace std;

// 1. a �� b ָ��ͬһ���ڴ�ռ� 
int main1()
{
	const int c1 = 10;

	int a = 10;
	int& b = a;   // b ����һ������ ��Ϊ����Ҫ����ֵ

	printf("&a = %d\n", &a);
	printf("&b = %d\n", &b);	// a �� b ����ͬһ���ڴ�ռ�����ƺ�
 
	return 0;
}

// 2. ����ռ��ռ�ڴ�ռ�
// ռ�ÿռ� ��ָ������

struct Teacher
{
	char name[64]; // 64
	int age;	   // 4
	
	int& a;		   // 4		// ����ָ�� ��ռ���ڴ�ռ��С
	int& b;		   // 4
};

int main2()
{
	printf("sizeof(Teacher): %d", sizeof(Teacher));

	return 0;
}

// 3. ���õı���
// modifyA() = modifyA2()
void modifyA(int &a1)
{
	a1 = 10;
}

void modifyA2(int * const a1)
{
	*a1 = 20;	// *ʵ�εĵ�ַ��ȥ����޸�ʵ�ε�ֵ
}

int main3()
{
	// 1. ������c++�е��ڲ���һ������ָ��
	int a = 10;

	int& b = a; // =====> int* const b = &a;

	int c = 10;

	modifyA(c);
	printf("c: %d\n", c);

	modifyA2(&c);
	printf("c: %d\n", c);

	return 0;
}

// 4.��Ӹ�ֵ
//   1).��������  2).������ϵ  3).ͨ��*��ֵ
// ���õļ�Ӹ�ֵ  �൱�ڽ����� 2) 3) ������

void modifyA3(int* p)
{
	*p = 200;
}

int main()
{
	int a = 10;
	int* p = NULL;  // ������������

	p = &a;
	*p = 100;

	{
		*p = 200;
	}
	modifyA3(&a); // ��������

	return 0;
}