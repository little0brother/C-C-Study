#include <iostream>
using namespace std;


// ��Բ�����
// ��������̵ķ������Ԫ�����
int main01()
{
	double r = 0;
	double s = 0;

	cout << "������Բ�İ뾶: ";

	// cin ��׼����
	cin >> r;

	cout << " r = " << r << endl;

	s = 3.14 * r * r;

	cout << "Բ�����: " << s << endl;

	return 0;
}

// ���������Ĺ������Բ�����

// ��c++�ж�����һ���Զ�����������
struct Circle
{
	double m_r; // �뾶
	double m_s; // ���
};

// ��c++�ж�����һ���Զ�����������
class MyCircle
{
private:
	double m_s; // ���
	double m_r; // �뾶 ���� ��Ա����

public:
	void setR(double r)	//��Ա����
	{
		m_r = r;
	}

	double getR()	// ��Ա����
	{
		return m_r;
	}

	double getS()
	{
		m_s = 3.14 * m_r * m_r;
		return m_s;
	}
};

// �������
// 1.��ĳ��󣬳�Ա�����ͳ�Ա����
// 2.ʵ����
// 3.�����
	// ������̼ӹ���һ��һ���ĺ��� 
	// �������ӹ�����һ��һ������
// 4.mian���ɲ���

// ˼��1: ��ĵ��� ִ�й��̷��� ---�� ����벻��һ��һ��ִ�е�
// ����һ���������ͣ��̶���С���ڴ����), ����һ���࣬��һ����������������ڴ�
// ���������Ͷ���һ��������ʱ��Ż�����ڴ�

// ˼��2: c++����������δ��������󣬵�����ĳ�Ա������
int main02()
{
	MyCircle c1, c2, c3; //���ඨ�����
	double r;

	cout << "������c1Բ�İ뾶��";
	cin >> r;

	// ��c1Բ�ε����Ը�ֵ
	c1.setR(r);

	cout << "c1Բ������ǣ�" << c1.getS() << endl;

	return 0;
}

int main()
{
	MyCircle c1, c2, c3; //���ඨ�����
	double r1, r2, r3;

	cout << "������c1Բ�İ뾶��";
	cin >> r1;
	cout << "������c2Բ�İ뾶��";
	cin >> r2;
	cout << "������c3Բ�İ뾶��";
	cin >> r3;

	// ��c1Բ�ε����Ը�ֵ
	c1.setR(r1);
	c2.setR(r2);
	c3.setR(r3);

	cout << "c1Բ������ǣ�" << c1.getS() << endl;
	cout << "c2Բ������ǣ�" << c2.getS() << endl;
	cout << "c3Բ������ǣ�" << c3.getS() << endl;

	return 0;
}