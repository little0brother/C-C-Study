#include <iostream>
using namespace std;

// �ڶ�����ʱ��ֻҪ�Զ����˹��캯������ϵͳ���������κι��캯��

class Test
{
private:
	int a;
	int b;

public:
	//Test(const Test& obj)
	//{
	//	a = obj.a;
	//	b = obj.b;
	//}

	Test(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
};

// �����ж����˿������캯��ʽ��ϵͳ�����ṩ�޲ι��޺���
// �����ж������вι��캯����ϵͳ�����ṩ�޲ι��캯��

int main()
{
	//Test t1;  // �����޲ι��캯��   err  ��Ϊ�Լ������˹��캯�� ����ϵͳ�������ṩĬ�ϵĹ��캯��

	//Test t2;  // err

	return 0;
}