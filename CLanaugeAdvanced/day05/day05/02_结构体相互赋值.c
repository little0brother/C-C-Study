#include <stdio.h>

// 定义结构体类型时不要直接给成员赋值
// 结构体只是一个类型，还没有分配空间
// 只有根据其类型定义变量时，才分配空间，有空间后才能赋值
typedef struct Teacher
{
	char name[50];
	int age;
}Teacher;

// 值传递不会影响地址内容
void copyTeacher(Teacher to, Teacher from)
{
	to = from;
	printf("[copyTeacher] %s %d\n", to.name, to.age);
}

// 地址传递才会引起变化
void copyTeacher1(Teacher* to, Teacher* from)
{
	*to = *from;
	//printf("[copyTeacher] %s %d\n", to.name, to.age);
}

void fun(int to, int from)
{
	to = from;
}

int main()
{
	Teacher t1 = { "Alice", 22 };
	// 相同类型的两个结构体变量，可以相互赋值
	// 把t1成员变量内存的值拷贝给t2成员变量的内存
	// t1和t2没有联系
	Teacher t2 = t1;
	printf("%s %d\n", t2.name, t2.age);

	int a = 10;
	int b = a;	// a的值给了b, a, b之间没有关系

	Teacher t3;
	memset(&t3, 0, sizeof(t3));	// 将内存块内地址赋为0
	// 通过函数进行拷贝
	//copyTeacher(t3, t1);	// t1拷贝给t3
	copyTeacher1(&t3, &t1);	// t1拷贝给t3
	printf("[t3] %s %d\n", t3.name, t3.age);

	// 值传递不会影响内容
	int c = 10;
	int d = 0;
	fun(d, c); // 把c的值给b
	printf("d = %d\n", d);

	return 0;
}