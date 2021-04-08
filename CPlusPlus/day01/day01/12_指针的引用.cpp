
#include <iostream>
using namespace std;

#if 1
struct Teacher
{
	char name[64];
	int age;
};

// 在被调用函数 获取内存块
int getTeacher(Teacher** p)
{
	Teacher* tmp = NULL;

	tmp = (Teacher*)malloc(sizeof(Teacher));
	if (tmp == NULL)
	{
		return -1;
	}

	// p是形参的地址，*实参的地址 去间接修改实参的值
	*p = tmp;
}

// c++中指针的引用
int getTeacher2(Teacher*& myp)
{
	// 给myp赋值 相当于给main函数中的pT1赋值
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

	// c语言中的二级指针
	getTeacher(&pT1);
	cout << pT1->age << " " << pT1->name << endl;
	freeTeacher(pT1);

	// c++中指针的引用
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