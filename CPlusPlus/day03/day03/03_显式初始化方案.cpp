#include <iostream>
using namespace std;

class Test
{
private:
	int a;
	int b;

public:
	void init(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
};

int main()
{
	// ����û�ж��幹�캯��  ���������Զ�����Ĭ�Ϲ��캯��
	// ����û�ж���copy���캯�������������Զ�����Ĭ��copy���캯��
	Test t1;
	t1.init(1, 2);  // ������ʽ��ʼ������

	// ���ֳ���֮�� ��ʽ��ʼ ���ʺ�
	Test tArr[3]; // �޷�������ʽ��ʼ������ �Ƚ��鷳
	tArr[0].init(1, 2);

	return 0;
}