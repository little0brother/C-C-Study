#include <iostream>
using namespace std;

class MyCircle
{
public:

	double r;
	
	double pi = 3.1415;
	double area = pi * r * r;	// ��������ڳ�ʼ��ʱ���Ѿ�ִ���ˣ����ǵ�ʱ��rΪһ�����ֵ���������·�����Ϊ����
};

// �ܱ���ͨ�� ���ǽ��Ϊ����
int main()
{
	MyCircle c1;
	double r;

	cout << "������Բ�İ뾶��";
	cin >> c1.r;

	cout << "Բ�����: " << c1.area << endl;		// �������ֻ�Ǵ�������ֵ����û��ִ��������䣬����ֵΪ��ʼ��ʱ����������ֵ

	c1.r = 100;
	cout << c1.area << endl;
		
	return 0;
}