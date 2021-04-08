#include <iostream>
#include <string>
using namespace std;

class man
{
protected:
	int age;
	string name;
public:
	man(int ag, string nam) : age(ag), name(nam) { }

	void display() { cout << "age:" << age << endl << "name:" << name << endl; }
	int getAge() { return age; }
	string getName() { return name; }
};

class superman : public man
{
private:
	int forceVlue;
public:
	superman(int ag, string nam, int force) : man(ag, nam), forceVlue(force) { }
	
	void display() { cout << "age:" << age << endl << "name:" << name << endl << "foreceVlue:" << forceVlue << endl; }
	int getAge() { return age; }
	string getName() { return name; }
	int getVlue() { return forceVlue; }
};

//写法1：传入值为派生类，接受值为基类，形参。
//int work(man a)
//{
//	if (a.getAge() >= 20)
//		return 1;
//	else
//		return 0;
//}

//写法2：传入值为指针，接收为基类指针。
//int work(man *a)
//{
//	if (a->getAge() >= 20)
//		return 1;
//	else
//		return 0;
//}

//写法3：传入值为引用，接收值为基类。
//int work(man &a)
//{
//	if (a.getAge() >= 20)
//		return 1;
//	else
//		return 0;
//}

int main()
{
	man m1(20, "xuyuxin");
	superman sm2(21, "mawenrui", 90);
	
	//int n = work(sm1);  //写法1
	//int n = work(&sm2); //写法2
	//int n = work(sm2);  //写法3

	if (n != 0)
		cout << "Yes!" << endl;
	else
		cout << "NO!" << endl;

	system("pause");
	return 0;
}