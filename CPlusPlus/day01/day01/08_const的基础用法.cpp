#include <iostream>
using namespace std;

// 1. 
// c++中的const不可以通过任何手段修改值， c语言中的const可以通过间接赋值的方式修改值

// 2.原因分析
// c++编译器在识别到const之后，就会将该变量用键值对的方式存储到符号表中
// 如果对通过*p去引用该地址，会自动申请一块新的内存空间，不会影响到符号表中的内容

// 3.const 分配内存的时机，编译器编译期间

struct Teacher
{
	char name[64];
	int age;
};

// 指针指向的内存空间不能被修改
int operatorTeacher01(const Teacher* pT) 
{
	//pT->age = 10;  // err
	return 0;
}

// 指针变量本身不能被修改
int operatorTeacher02(Teacher* const pT)
{
	pT->age = 10;
	//pT = NULL; // err
	return 0;
}

int operatorTeacher03(const Teacher * const pT)
{
	//pT->age = 10;	// err
	//pT = NULL; // err
	printf("age:%d\n", pT->age);
	return 0;
}

int main1()
{
	//const int a = 1;
	//int const b = 1;	// 功能相同

	//const int* c = &a;	// const 修饰的是指针所指向的内存空间，不能被修改
	//int* const d = &a;	// const 修饰的是变量，所以指针的指向不能被修改
	//const int* const e = &a; // const 修饰变量和指针，所以指向与所指向的内存地址都不能修改

	cout << "hello" << endl;

	//Teacher t1;
	//t1.age = 33;
	//operatorTeacher03(&t1);

	// 1. 
	// c++中的const不可以通过任何手段修改值， c语言中的const可以通过如下方式修改值
	const int a = 10;
	int* p = NULL;
	p = (int*)&a;
	*p = 20;
	cout << "a = " << a << endl;

	return 0;
}

// 3.const 分配内存的时机，编译器编译期间
void main2()
{
	int a;
	const int b = 10;
	int c;

	printf("&a: %d, &b: %d, &c: %d\n", &a, &b, &c);

}

// 4. const 和 #define相同之处

// 在编译预处理阶段进行处理
// const 常量是由编译器处理的，提供类型检查和作用域检查
#define d 20
void main3()
{
	int a = 10;
	int b = 20;
	//int array[a + b];	// err   liunx内核中可以使用，因为linux内核的编译器支持
						// c和c++编译器，都不支持这种语法

	const int c = 10;
	//const int d = 20;
	int array1[c + d]; // 可以编译通过
}

// 5 const定义的常量，由编译器处理，提供类型检查和作用域检查
void fun1()
{
#define a 10
	const int b = 20;	// 只能在作用域中生效
//#undef a 卸载宏定义，不在下方生效
}

void fun2()
{
	printf("a = %d\n", a);
	//printf("b = %d\n", b);
}

int main()
{
	fun1();
	fun2();

	return 0;
}