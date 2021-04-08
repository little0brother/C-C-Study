#include <stdio.h>
#include <string.h>

/*
	1、结构体类型定义
	2、结构体变量定义
	3、结构体变量的初始化
	4、typedef改类型名
	5、点运算符和指针法操作结构体
	6、结构体也是一种数据类型，复合类型，自定义类型
*/

// 1.结构体类型定义
// struct 关键字
// struct Teacher 合一起才是类型
// {} 后面又分号
struct Teacher
{
	char name[50];
	int age;
};

// 2.结构体变量定义
// 1).先定义类型，在定义变量（常用）
struct Teacher t1; // 全局变量

// 2).定义类型同时定义变量
struct Teacher2
{
	char name[50];
	int age;
}t3 = {"tmo", 12};

struct
{
	char name[50];
	int age;
}t5, t6;


// 3.结构体变量的初始化
// 定义变量同时直接初始化，通过{}
struct Teacher t7 = { "da", 18};

// 4.typedef改类型名
typedef struct Teacher3
{
	char name[50];
	int age;
}Teacher3;

struct Teacher3 t8;
Teacher3 t9;


int main()
{
	// 1).先定义类型，在定义变量（常用）
	struct Teacher t2; // 局部变量

	printf("%s, %d", t7.name, t7.age);

	// 5.点运算符和指针法操作结构体
	/*
		struct Teacher
		{
			char name[50];
			int age;
		};
	*/
	strcpy(t2.name, "xiaoming");
	t2.age = 22;
	printf("\n%s, %d", t2.name, t2.age);

	// 结构体指针变量，没有指向内存空间，不能给成员赋值
	struct Teacher* p = NULL;
	p = &t2;
	strcpy(p->name, "xiaosssing");
	p->age = 22;
	printf("\n%s, %d", p->name, p->age);

	return 0;
}