/**************************/
/* 结构指针变量做函数的参数 */
/**************************/

/* 结构体变量stu，含学生学号、姓名、3门课成绩。通过调用函数print将他们输出 */

#include <stdio.h>
#include <string.h>

struct student
{
	int num;
	char name[20];
	float score[3];
};

void print1(struct student);
void print2(struct student * );

int main4()
{
	struct student stu;

	stu.num = 8;
	strcpy(stu.name, "Hello World!");
	stu.score[0] = 98.5;
	stu.score[1] = 99.0;
	stu.score[2] = 99.5;

	print1(stu);
	print2(&stu);

	return 0;
}

// 1.用结构体变量作为函数参数
void print1(struct student stu)
{
	printf("\tnum     : %d\n", stu.num);
	printf("\tname    : %s\n", stu.name);
	printf("\tscore_1 : %5.2f\n", stu.score[0]);
	printf("\tscore_2 : %5.2f\n", stu.score[1]);
	printf("\tscore_3 : %5.2f\n", stu.score[2]);
	printf("\n\n");
}

// 2.指向结构体变量的指针做实参(效率高)
void print2(struct student *p)
{
	printf("\tnum     : %d\n", p->num);
	printf("\tname    : %s\n", p->name);
	printf("\tscore_1 : %5.2f\n", p->score[0]);
	printf("\tscore_2 : %5.2f\n", p->score[1]);
	printf("\tscore_3 : %5.2f\n", p->score[2]);
	printf("\n\n");
}

// 3.