#include <iostream>
using namespace std;

// ��װ��2�㺬��
// 1. �����Ժͷ������з�װ
// 2. �����Ժͷ������з��ʿ���

//��ķ��ʿ��ƹؼ������εĳ�Ա�����ͳ�Ա����(����Ĭ��private)
// public: ����������ڲ�������ⲿ����
// private: ֻ��������ڲ������ʣ�����������ⲿ����
// protected: ֻ��������ڲ������ʣ�����������ⲿ���ʣ����ڼ̳�
class MyCircle
{
public:
	double m_r;	 // ����
	double m_s;

public:
	// ��Ա����
	double getR()
	{
		return m_r;
	}

	void setR(double r)
	{
		m_r = r;
	}

	double getS()
	{
		m_s = 3.14 * m_r * m_r;
		return m_s;
	}
};

// ����Ĭ������Ϊpublic
struct MyStruct
{
	int a;
	int b;

	void fun();
};

// ���װ�˳�Ա�����ͳ�Ա����  ͨ�����ָ����Ե�����ĳ�Ա����
void printCircle1(MyCircle *pC)
{
	cout << pC->getR() << endl;
	cout << pC->getS() << endl;
}

void printCircle2(MyCircle& myc)
{
	cout << myc.getR() << endl;
	cout << myc.getS() << endl;
}

void printCircle3(MyCircle myc)
{
	cout << myc.getR() << endl;
	cout << myc.getS() << endl;
}

int main()
{
	MyCircle c1, c2;

	c1.setR(10);
	cout << "c1.s: " << c1.getS() << endl;

	// ����
	printCircle1(&c1);

	c1.setR(20);
	printCircle1(&c1);

	printCircle2(c1);

	return 0;
}