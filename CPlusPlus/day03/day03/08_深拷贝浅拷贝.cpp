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

		cout << "一个参数构造函数" << endl;
	}

	//Name obj2 = obj1;
	// 解决默认copy构造函数浅拷贝的缺陷，使用深拷贝
	Name(const Name& obj)
	{
		this->len = obj.len;
		this->p = (char*)malloc(len + 1);
		strcpy(this->p, obj.p);

		cout << "copy构造函数" << endl;
	}

	~Name()
	{
		if (p != NULL)
		{
			free(p);
			p = NULL;
			len = 0;
		}

		cout << "析构函数" << endl;
	}
};


// 对象析构时 出现coredump现象
void objplay()
{
	Name obj1("abcd");

	// 使用的默认copy构造函数，为浅copy，没有申请内存空间(把变量指针的值进行复制，没有开辟新的内存空间来存放数据)，所以析构时，会出现coredump现象
	Name obj2 = obj1;

	Name obj3("obj3");
	obj3 = obj1;	// 等号操作 同样为浅拷贝，出现coredump现象  必须重载 ‘=’ 操作符 才能解决问题
}

int main()
{
	//Name obj1("abcd");

	//Name obj2 = obj1;

	objplay();

	return 0;
}