#include <iostream>
using namespace std;

class Test 
{
private:
	int a;
	int b;

public:
	// �޲ι��캯��
	Test()
	{
		cout << "�޲ι��캯��" << endl;
	}

	// �вι��캯��
	Test(int a, int b)
	{
		this->a = a;
		this->b = b;

		cout << "�вι��캯��" << endl;
	}
	Test(int a)
	{

	}

	// ��ֵ���캯��(copy���캯��)
	Test(const Test& obj)
	{
		cout << "copy���캯��" << endl;
	}

	void printT()
	{
		cout << "��Ա����" << endl;
	}
};

int main()
{
	// ���캯���ĵ���
	Test t1; // �����޲ι��캯��

	// �����вι��캯�� ���ַ���
	Test t2_1(1, 2); // ���ŷ� c++�������Զ�����
	Test t2_2 = (3, 4); // �Ⱥŷ� c++�������Զ�����  ���õ�Ϊһ�������Ĺ��캯��  ==��t2_2 = 4); ���ű��ʽ���Ϊ4
	Test t2_3 = Test(1, 2); // ֱ�ӵ��ù��캯�� �ֹ�����  (��������)

	Test t3(t1); // ����copy���캯��

	return 0;
}