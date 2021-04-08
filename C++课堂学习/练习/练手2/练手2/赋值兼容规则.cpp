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

//д��1������ֵΪ�����࣬����ֵΪ���࣬�βΡ�
//int work(man a)
//{
//	if (a.getAge() >= 20)
//		return 1;
//	else
//		return 0;
//}

//д��2������ֵΪָ�룬����Ϊ����ָ�롣
//int work(man *a)
//{
//	if (a->getAge() >= 20)
//		return 1;
//	else
//		return 0;
//}

//д��3������ֵΪ���ã�����ֵΪ���ࡣ
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
	
	//int n = work(sm1);  //д��1
	//int n = work(&sm2); //д��2
	//int n = work(sm2);  //д��3

	if (n != 0)
		cout << "Yes!" << endl;
	else
		cout << "NO!" << endl;

	system("pause");
	return 0;
}