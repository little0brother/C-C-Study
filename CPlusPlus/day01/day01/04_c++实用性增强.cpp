#include <iostream>
using namespace std;

#if 0 
//C�����еı�����������������ʼ��λ�ö��壡��
//C++�и�ǿ�����Եġ�ʵ���ԡ������еı�������������Ҫʹ��ʱ�ٶ���

int main()
{
	int i;
	printf("hell\n");

	int k;
	
	i = 10;
	k = 11;

	return 0;
}
#endif

#if 0
// register ����ǿ
int main()
{
	register int a = 0;
	printf("&a: %d\n", &a);	// C���Բ����ټĴ���������ȡ��ַ

	for (int i = 0; i < 1000; i++)	// ���Զ��� i ���ڼĴ����У��ӿ����ִ���ٶ�
	{
		printf("i:%d\n", i);
	}

	return 0;
}
#endif

#if 0
// c++�ܾ������Ե�����
//int g_a;
int g_a = 100;

int mian()
{
	printf("hello g_a:%d\n", g_a);

	return 0;
}
#endif

#if 1

// struct�ؼ��� class�ؼ��� ��ɵĹ�����ͬ
class c1
{
public:
private:
};

struct Teacher
{
public:
	char name[32];
	int age;
};

int main()
{
	// C++�в���typedefҲ����ֱ�Ӷ���ṹ�����
	Teacher t1;
	t1.age = 10;

	return 0;
}

#endif

// 