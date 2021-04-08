#include <iostream>
using namespace std;

class Test
{
private:
	int a;
	char* p;

public:
	// 构造函数(完成对属性的初始化工作)
	Test() 
	{
		p = (char*)malloc(100);
		strcpy(p, "123");
		cout << "我是无参的构造函数" << endl;
	}  

	// 析构函数
	~Test()
	{
		if (p != NULL)
		{
			free(p);
		}

		cout << "我是析构函数" << endl;
	}

	void printP()
	{
		cout << p << endl;
		cout << a << endl;
	}

};

// 研究对象行为
void objplay()
{
	Test t1, t2;

	t1.printP();
}

int main()
{
	// 先创建的对象 后析构
	//Test t1, t2;

	objplay();

	return 0;
}