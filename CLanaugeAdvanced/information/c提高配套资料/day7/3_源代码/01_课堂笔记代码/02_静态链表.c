#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Stu
{
	int id;	//数据域
	char name[100];

	struct Stu *next; //指针域
}Stu;

int main(void)
{
	//初始化三个结构体变量
	Stu s1 = { 1, "mike", NULL };
	Stu s2 = { 2, "lily", NULL };
	Stu s3 = { 3, "lilei", NULL };

	
	s1.next = &s2; //s1的next指针指向s2
	s2.next = &s3;
	s3.next = NULL; //尾结点


	Stu *p = &s1; 

	while (p != NULL)
	{
		printf("id = %d, name = %s\n", p->id, p->name);

		//结点往后移动一位
		p = p->next; //&s2
	}


	printf("\n");
	system("pause");
	return 0;
}