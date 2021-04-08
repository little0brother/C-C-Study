#include <iostream>
using namespace std;

#if 0 
//C语言中的变量都必须在作用域开始的位置定义！！
//C++中更强调语言的“实用性”，所有的变量都可以在需要使用时再定义

int main()
{
	int i;
	printf("hell\n");

	int k;
	
	i = 10;
	k = 11;

	return 0;
}
#endif

#if 0
// register 的增强
int main()
{
	register int a = 0;
	printf("&a: %d\n", &a);	// C语言不能再寄存器变量上取地址

	for (int i = 0; i < 1000; i++)	// 会自动在 i 放在寄存器中，加快程序执行速度
	{
		printf("i:%d\n", i);
	}

	return 0;
}
#endif

#if 0
// c++拒绝二义性的做法
//int g_a;
int g_a = 100;

int mian()
{
	printf("hello g_a:%d\n", g_a);

	return 0;
}
#endif

#if 1

// struct关键字 class关键字 完成的功能相同
class c1
{
public:
private:
};

struct Teacher
{
public:
	char name[32];
	int age;
};

int main()
{
	// C++中不用typedef也可以直接定义结构体变量
	Teacher t1;
	t1.age = 10;

	return 0;
}

#endif

// 