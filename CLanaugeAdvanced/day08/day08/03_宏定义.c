#include <stdio.h>

#define PI 3.14

#define TEST(a, b) (a)*(b)

// �Ƚ���������С
#define COMP(a, b) (a)>(b)?(a):(b)
// �Ƚ���������С
#define COMP3(a, b, c) (a) > (COMP(b, c)) ? (a) : (COMP(b, c))

void fun2()
{
	//int a = A;	// err ��Ϊ A ���·�����
}

void fun()
{

#define A 10	// �����˺궨�壬����Ĵ��붼�����ã�������Ϊȫ��
	int i = 10;

}

void test()
{
	int a = A;	// ok
	//int j = i;  // err

	// ȡ���궨��
#undef A
	//int b = A; // err
}

int main()
{
	int r = 10;

	printf("%lf\n", PI * r * r);

	int a = TEST(1, 2);
	a = TEST(1 + 1, 2);		// a = 1+1*2	�������ſɱ���
	printf("a = %d\n", a);

	printf("%d\n", COMP(1, 2));
	printf("%d\n", COMP3(2, 5, 1));		// ���Ų��ܱ���Ҫ��ÿ�������� �������չ��ʱ���������
	// 1, 2, 3   1 > 2 > 3

	return 0;
}