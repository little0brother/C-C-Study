#include <iostream>
using namespace std;

// copy���캯������һ������ȥ��ʼ������һ������

class Test
{
private:
	int a;
	int b;

public:
	// �вι��캯��
	Test(int a, int b)
	{
		this->a = a;
		this->b = b;

		cout << "�вι��캯��" << endl;
	}

	// ��ֵ���캯��(copy���캯��)
	Test(const Test& obj)
	{
		cout << "copy���캯��" << endl;
	}

};

int main()
{
	Test t0(1, 2);
	Test t1(1, 2);

	t0 = t1;  // ��ֵ���� ��t0��t1��ֵ   ��ʼ���븳ֵ��������ͬ�ĸ���

	// 1 copy���캯���ĵ�һ�ֵ��÷���
	Test t2 = t1;  // ��t1��ʼ��t2

	// 2
	Test t3(t1);


	return 0;
}