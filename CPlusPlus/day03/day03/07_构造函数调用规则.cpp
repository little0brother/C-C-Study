#include <iostream>
using namespace std;

// 在定义类时，只要自定义了构造函数，则系统将不会有任何构造函数

class Test
{
private:
	int a;
	int b;

public:
	//Test(const Test& obj)
	//{
	//	a = obj.a;
	//	b = obj.b;
	//}

	Test(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
};

// 当类中定义了拷贝构造函数式，系统不会提供无参狗赞函数
// 当类中定义了有参构造函数，系统不会提供无参构造函数

int main()
{
	//Test t1;  // 调用无参构造函数   err  因为自己定义了构造函数 所以系统将不会提供默认的构造函数

	//Test t2;  // err

	return 0;
}