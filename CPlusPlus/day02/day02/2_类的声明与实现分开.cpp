#include <iostream>
using namespace std;

class MyTeacher
{
private:
	int age;
	char name[32];

public:
	void setAge(int age);
	int getAge();
};

// ��ʵ����ʱҪ��������ռ�
void MyTeacher::setAge(int age)
{
	this->age = age;
}

int MyTeacher::getAge()
{
	return this->age;
}

int main()
{
	MyTeacher mt;
	mt.setAge(10);
	cout << mt.getAge() << endl;

	return 0;
}