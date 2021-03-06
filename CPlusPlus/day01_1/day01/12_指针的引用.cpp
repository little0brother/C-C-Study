#include <iostream>
using namespace std;

struct Person
{
	int age;
};

void allocateSpace(Person** p)	// **p 指向Person本体  *p 指针  p 指针的指针
{
	*p = (Person*)malloc(sizeof(Person));

	(*p)->age = 100;
}

void test01()
{
	Person* p = NULL;
	allocateSpace(&p);

	cout << "age = " << p->age << endl;
}

// 2.指针的引用
void allocateSpace2(Person*& p)	// Person*& p = p;
{
	p = (Person*)malloc(sizeof(Person));

	p->age = 200;
}

void test02()
{
	Person* p = NULL;
	allocateSpace2(p);

	cout << "age = " << p->age << endl;
}

int main()
{
	//test01();
	test02();

	return 0;
}