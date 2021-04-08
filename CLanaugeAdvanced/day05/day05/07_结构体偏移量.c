#include <stdio.h>

// 结构体类型定义下来，内部的成员变量的内存布局已经确定
typedef struct Teacher
{
	char name[64];	// 4
	int age;		// 4
	int id;			// 4
}Teacher;

int main()
{
	Teacher t1;
	Teacher* p = NULL;
	p = &t1;

	int n1 = (int)(&p->age) - (int)p;	// age相对与结构体首地址偏移量
	printf("n1 = %d\n", n1);

	int n2 = (int)&((Teacher*)0)->age;	// 绝对0地址的偏移量
	printf("n2 = %d\n", n2);

	return 0;
}