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

// ҵ����
void fun(Test t)
{
	cout << t.getX() << endl;
}

void playObj()
{
	Test t1(1, 2);

	Test t2 = t1;

	Test t3;
	fun(t3);  //*** t3ʵ��ȥ��ʼ���β�t�� �����copy���캯��
}

int main()
{
	Test t1(1, 2);

	Test t2;
	
	playObj();

	return 0;
}