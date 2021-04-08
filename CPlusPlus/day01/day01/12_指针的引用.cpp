
#include <iostream>
using namespace std;

#if 1
struct Teacher
{
	char name[64];
	int age;
};

// �ڱ����ú��� ��ȡ�ڴ��
int getTeacher(Teacher** p)
{
	Teacher* tmp = NULL;

	tmp = (Teacher*)malloc(sizeof(Teacher));
	if (tmp == NULL)
	{
		return -1;
	}

	// p���βεĵ�ַ��*ʵ�εĵ�ַ ȥ����޸�ʵ�ε�ֵ
	*p = tmp;
}

// c++��ָ�������
int getTeacher2(Teacher*& myp)
{
	// ��myp��ֵ �൱�ڸ�main�����е�pT1��ֵ
	myp = (Teacher*)malloc(sizeof(Teacher));

	if (myp == NULL)
	{
		return -1;
	}

	myp->age = 20;
}

void freeTeacher(Teacher* p)
{
	if (p == NULL)
	{
		return;
	}

	free(p);
}

int main()
{
	Teacher* pT1 = NULL;

	// c�����еĶ���ָ��
	getTeacher(&pT1);
	cout << pT1->age << " " << pT1->name << endl;
	freeTeacher(pT1);

	// c++��ָ�������
	getTeacher2(pT1);
	cout << pT1->age << endl;
	freeTeacher(pT1);

	return 0;
}
#endif // 0

#if 0

#include <iostream>
using namespace std;

struct Stu
{
	int id;
	string name;
};

void fun(Stu &stu)
{
	stu.id = 10;
	stu.name = "hello";
}

int main()
{
	Stu stu;

	fun(stu);
	cout << stu.id << "  " << stu.name << endl;

	return 0;
}

#endif