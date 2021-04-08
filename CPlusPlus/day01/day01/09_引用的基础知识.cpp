#include <iostream>
using namespace std;

// 本质：是一个指针常量，int& aRef = a; // int* const aRef = &a;

// 1. 引用的基本概念
// 对已存在变量起的别名
int main1()
{
	int a = 10;

	// 引用的语法： Type& name = var;
	
	int& b = a;
	
	b = 100; // 相当于把a修改成100

	printf("b: %d\n", b);
	printf("a: %d\n", a);

	a = 200;

	printf("b: %d\n", b);
	printf("a: %d\n", a);

	return 0;
}

// 2.基础类型的引用
// 无法完成值的交换，交换值必须要对地址操作
void myswap(int a, int b)
{
	int c = a;
	a = b;
	b = c;
}

void myswap2(int* a, int* b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

// 利用引用进行值的交换
// a是x的别名  b是y的别名
void myswap3(int& a, int& b)
{
	int c;
	c = a;
	a = b;
	b = c;
}

int main2()
{
	int a = 10;
	int& b = a;
	//int& c;   // err 普通引用 必须要初始化

	int x = 10;
	int y = 20;

	myswap(x, y);
	printf("x: %d, y: %d\n", x, y);

	myswap2(&x, &y);
	printf("x: %d, y: %d\n", x, y);

	myswap3(x, y);
	printf("x: %d, y: %d\n", x, y);

	return 0;
}

// 复杂数据类型做函数引用
struct Teacher
{
	char name[64];
	int age;
};

void printfT(Teacher *pT)
{
	cout << pT->age << endl;
}

// pT是形参，t1拷贝一份数据给pT， // ----> pT = t1;
void printfT2(Teacher pT)
{
	cout << pT.age << endl;

	pT.age = 21; // 不会影响本来的值
}

// pT是t1的别名
void printfT3(Teacher& pT)
{
	cout << pT.age << endl;
	pT.age = 21;  // 会修改t1值
}

int main()
{
	Teacher t1;
	t1.age = 43;

	printfT(&t1);

	printfT2(t1);

	printfT3(t1);
	printf("t1->age: %d\n", t1.age);

	return 0;
}