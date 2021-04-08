#include <iostream>
using namespace std;

// 1. a 和 b 指向同一块内存空间 
int main1()
{
	const int c1 = 10;

	int a = 10;
	int& b = a;   // b 很像一个常量 因为必须要赋初值

	printf("&a = %d\n", &a);
	printf("&b = %d\n", &b);	// a 和 b 均是同一块内存空间的门牌号
 
	return 0;
}

// 2. 引用占不占内存空间
// 占用空间 与指针类似

struct Teacher
{
	char name[64]; // 64
	int age;	   // 4
	
	int& a;		   // 4		// 很像指针 所占的内存空间大小
	int& b;		   // 4
};

int main2()
{
	printf("sizeof(Teacher): %d", sizeof(Teacher));

	return 0;
}

// 3. 引用的本质
// modifyA() = modifyA2()
void modifyA(int &a1)
{
	a1 = 10;
}

void modifyA2(int * const a1)
{
	*a1 = 20;	// *实参的地址，去间接修改实参的值
}

int main3()
{
	// 1. 引用在c++中的内部是一个常量指针
	int a = 10;

	int& b = a; // =====> int* const b = &a;

	int c = 10;

	modifyA(c);
	printf("c: %d\n", c);

	modifyA2(&c);
	printf("c: %d\n", c);

	return 0;
}

// 4.间接赋值
//   1).两个变量  2).建立关系  3).通过*赋值
// 引用的间接赋值  相当于将条件 2) 3) 和起来

void modifyA3(int* p)
{
	*p = 200;
}

int main()
{
	int a = 10;
	int* p = NULL;  // 定义两个变量

	p = &a;
	*p = 100;

	{
		*p = 200;
	}
	modifyA3(&a); // 建立关联

	return 0;
}