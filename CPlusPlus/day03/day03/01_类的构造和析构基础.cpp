#include <iostream>
using namespace std;

class Test
{
private:
	int a;
	char* p;

public:
	// ���캯��(��ɶ����Եĳ�ʼ������)
	Test() 
	{
		p = (char*)malloc(100);
		strcpy(p, "123");
		cout << "�����޲εĹ��캯��" << endl;
	}  

	// ��������
	~Test()
	{
		if (p != NULL)
		{
			free(p);
		}

		cout << "������������" << endl;
	}

	void printP()
	{
		cout << p << endl;
		cout << a << endl;
	}

};

// �о�������Ϊ
void objplay()
{
	Test t1, t2;

	t1.printP();
}

int main()
{
	// �ȴ����Ķ��� ������
	//Test t1, t2;

	objplay();

	return 0;
}