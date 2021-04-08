#include <iostream>
using namespace std;

class Name
{
private:
	char* p;
	int len;

public:
	Name(const char* p)
	{
		this->len = strlen(p);
		this->p = (char*)malloc(len + 1);
		strcpy(this->p, p);

		cout << "һ���������캯��" << endl;
	}

	//Name obj2 = obj1;
	// ���Ĭ��copy���캯��ǳ������ȱ�ݣ�ʹ�����
	Name(const Name& obj)
	{
		this->len = obj.len;
		this->p = (char*)malloc(len + 1);
		strcpy(this->p, obj.p);

		cout << "copy���캯��" << endl;
	}

	~Name()
	{
		if (p != NULL)
		{
			free(p);
			p = NULL;
			len = 0;
		}

		cout << "��������" << endl;
	}
};


// ��������ʱ ����coredump����
void objplay()
{
	Name obj1("abcd");

	// ʹ�õ�Ĭ��copy���캯����Ϊǳcopy��û�������ڴ�ռ�(�ѱ���ָ���ֵ���и��ƣ�û�п����µ��ڴ�ռ����������)����������ʱ�������coredump����
	Name obj2 = obj1;

	Name obj3("obj3");
	obj3 = obj1;	// �ȺŲ��� ͬ��Ϊǳ����������coredump����  �������� ��=�� ������ ���ܽ������
}

int main()
{
	//Name obj1("abcd");

	//Name obj2 = obj1;

	objplay();

	return 0;
}