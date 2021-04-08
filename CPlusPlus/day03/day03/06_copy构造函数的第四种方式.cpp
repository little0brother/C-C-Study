#include <iostream>
using namespace std;

class Test
{
private:
	int x;
	int y;

public:
	Test(int x = 0, int y = 0)
	{
		this->x = x;
		this->y = y;
	}

	// copy���캯��  ��ɶ���ĳ�ʼ��
	Test(const Test& obj)
	{
		x = obj.x;
		y = obj.y;

		cout << "copy���캯��" << endl;
	}

	~Test()
	{
		cout << "����" << endl;
	}

	int getX()
	{
		return x;
	}
};

// ����һ����������
// ����1����������ֵ��һ��Ԫ�أ���������), ���ص���һ���µ������������Ի���������������copy���캯����

// ����2�����������ȥ����
// ������������� ��ʼ������һ��ͬ���͵Ķ�����ô��������ת����������
// ������������� ��ֵ������һ��ͬ���͵Ķ����������� ������

Test fun()
{
	Test T(1, 2);

	// ����ʱ ����T������һ���������� ��T��ֵͨ��copy���캯��������������
	return T; // ����һ����������  �����copy���캯��
}

void playObj()
{
	fun();
}

void playObj2()
{
	// �����������ʼ��test ������ֱ�Ӱ���������ת��test��������ת��Ϊ�����ֵ�, ��������fun()�����еĶ���
	Test test = fun();
	cout << test.getX() << endl;

	Test test2(1, 2);
	test2 = fun();  // ��������û��ת��Ϊ�¶��� ��������fun()�е���������
	cout << test2.getX() << endl;
}

int main()
{
	//playObj();

	playObj2();

	return 0;
}