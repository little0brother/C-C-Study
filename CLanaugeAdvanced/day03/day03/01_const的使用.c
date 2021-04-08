#include <stdio.h>


typedef struct MyStruct
{
	int a;
	int b;
}MyStruct;

void fun(MyStruct* p)
{
	// 指针能变
	p = NULL;  //ok
	// 指针指向内存也可改变
	p->a = 10; //ok
}

void fun1(MyStruct const* p)
{
	p = NULL; //ok
	//p->a = 10; //err
}

void fun2(MyStruct * const p)
{
	//p = NULL; //err
	p->a = 10;; //ok
}

// 只读
void fun3(MyStruct const* const p)
{
	//p = NULL; //err
	//p->a = 10; //err

	MyStruct tmp;
	tmp.a = p->a;
}




int main(void)
{
	// const修饰一个变量为只读
	const int a = 10;
	//a = 100;   // err

	// 指针变量，指针指向的内存，2个不同概念
	char buf[] = "fdafdaa";

	// 从左往右看，跳过类型，看修饰哪个字符
	// 如果是*，说明指针指向的内存不能修改 (不能通过指针修改指向内存的内容)
	// 如果是指针变量，说明指针的指向不能改变，指针的值不能修改
	const char* p = buf;
	// 等价于上面 char const *p1 = buf;

	// p[1] = '2';  //err 不能通过指针修改指向内存的内容
	p = "fuoiunblj";  //ok

	
	char* const p1 = buf;
	p1[1] = '3';   //ok
	//p1 = "uijrewlr";  //err


	// p2为只读，指向不能变，指向的内存不能变
	const char* const p2 = buf;


	// 如何引用另外 .c 中的 const 变量
	extern const int aa;  // 不能再赋值，只能声明
	printf("aa = %d\n", aa);

	// const修饰的变量，定义时初始化
	const int b;
	//b = 10; //err

	// 在c语言中，const是冒牌货，可以通过指针间接修改
	const int b1 = 10;
	//b = 100; // err
	int* q = &b;
	*q = 11; //ok
	printf("%d, %d\n", b1, *q);

	printf("\n");
	return 0;
}