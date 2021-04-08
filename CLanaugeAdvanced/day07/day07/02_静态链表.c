#include <stdio.h>

typedef struct Stu
{
	int id; // 数据域
	char name[100];

	struct Stu* next;	// 指针域
}Stu;

int main()
{
	// 初始化三个结构体
	Stu s1 = { 1, "fuc", NULL };
	Stu s2 = { 2, "bob", NULL };
	Stu s3 = { 3, "tom", NULL };

	s1.next = &s2;	 // s1的next指向s2
	s2.next = &s3;
	s3.next = NULL;	 // 尾节点

	Stu* p = &s1; 

	while (p != NULL)
	{
		printf("id = %d, name = %s\n", p->id, p->name);

		// 节点往后移动一位
		p = p->next;
	}

	return 0;
}