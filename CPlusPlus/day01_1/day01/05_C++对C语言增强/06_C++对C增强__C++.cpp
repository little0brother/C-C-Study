#include <iostream>
using namespace std;

// 1.全局变量的检测增强
// 重定义 err
//int a;
//int a = 10;

// 2.函数检测增强 （形参变量类型检测增强、函数声明的返回值增强、函数的返回值检测增强、调用时参数传入个数检测增强）
int getRectS(int w, int h)
{
	return w * h;
}

void test02()
{
	// 
	//getRectS(10, 10, 10);
}

// 3.类型转换检测增强
void test03()
{
	char* p = (char*)malloc(64);
}

// 4.struct增强
struct Person
{
	int age;
	void func() { age++; }; //C++语言下，结构体可以放函数
};

void test04()
{
	Person p1;   // c++语言下，声明结构体时 可以不加struct关键字
	p1.age = 17;
	p1.func();

	cout << "p的年龄" << p1.age << endl;
}

// 5.bool类型增强  C++语言下有bool类型
// bool 代表真假 真true--1 假false--0
bool flag = false;

void test05()
{
	cout << "sizeof bool = " << sizeof(bool) << endl;
	flag = 100;
	cout << flag << endl;
}

// 6.三目运算符增强
void test06()
{
	int a = 10;
	int b = 20;

	printf("ret = %d\n", a > b ? a : b);

	a > b ? a : b = 100;  // b = 100;   c++运算符返回值是变量

	printf("a = %d\n", a);
	printf("b = %d\n", b);
}

// 7.const增强
const int m_A = 100;  // 全局const修饰变量 受到常量区保护，即使语法通过，运行阶段会报错
void test07()
{
	// m_A = 200;
	//int* p = (int*)&m_A;
	//*p = 200;

	const int m_B = 100;	// 局部const存放在符号表中 在进行取地址操作时会生成临时变量，不会影响本身的值
	//m_B = 200;
	int* p2 = (int*)&m_B;
	*p2 = 200;
	cout << "m_B = " << m_B << endl;

	int arr[m_B];	// 可以用来初始化数组 常量
}

int main()
{
	return 0;
}