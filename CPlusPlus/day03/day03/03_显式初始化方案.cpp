#include <iostream>
using namespace std;

class Test
{
private:
	int a;
	int b;

public:
	void init(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
};

int main()
{
	// 类中没有定义构造函数  编译器会自动调用默认构造函数
	// 类中没有定义copy构造函数，编译器会自动调用默认copy构造函数
	Test t1;
	t1.init(1, 2);  // 调用显式初始化函数

	// 这种场景之下 显式初始 不适合
	Test tArr[3]; // 无法调用显式初始化函数 比较麻烦
	tArr[0].init(1, 2);

	return 0;
}