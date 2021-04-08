/**********************/
/* 动态存储分配AND链表 */
/**********************/

/* problem: 还未实现多次插入多次删除，排错功能等等 抽时间做 */

#include <stdio.h>

#define LEN sizeof(struct student)	 // student结构的大小

int n; // 记录存放了多少数据

struct student
{
	int num;
	float score;
	struct student* next;   // 指向下一个结构
};

void linkList();
void dynamicLinkList();
struct student* creatList();
void print(struct student* head);
struct student* deleteNode(struct student* head, int numm);
struct student* insertNode(struct student* head, struct student* stu);

int main5()
{
	//linkList();
	dynamicLinkList();

	return 0;
}

// 动态链表
/* 建立含有学生(学号，成绩)数据的单向动态链表，学号为零表示建立链表完成 */
void dynamicLinkList()
{
	struct student* stu, stu_1;

	// 建立动态链表
	stu = creatList();
	// 打印链表
	print(stu);

	// 删除节点
	int numm;
	printf("\n输入所想删除数据的学号: ");
	scanf("%d", &numm);

	print(deleteNode(stu, numm));

	// 插入结点
	printf("输入插入数据的学号: ");
	scanf("%d", &stu_1.num);
	printf("输入插入数据的成绩: ");
	scanf("%f", &stu_1.score);

	print(insertNode(stu, &stu_1));
}

// 建立链表
struct student* creatList()
{
	struct student* stu1;
	struct student* head;
	struct student* p1, * p2;

	// 申请内存空间
	p1 = p2 = (struct student*)malloc(LEN);

	printf("输入学生学号: ");
	scanf("%d", &p1->num);
	printf("输入学生成绩: ");
	scanf("%f", &p1->score);
	printf("\n");

	// 初始化操作
	head = NULL;
	n = 0;

	// 动态分布内存建立链表
	while (p1->num)
	{
		n++;
		if (1 == n)
		{
			head = p1;		// 建立头指针
		}
		else
		{
			p2->next = p1;
		}

		p2 = p1;
		p1 = (struct student*)malloc(LEN);

		printf("输入学生学号: ");
		scanf("%d", &p1->num);
		printf("输入学生成绩: ");
		scanf("%f", &p1->score);
		printf("\n");
	}

	p2->next = NULL;

	return head;
}

// 打印链表
void print(struct student* head)
{
	struct student* p;
	// 遍历链表 输出数据
	printf("\n共有%d条数据\n", n);
	p = head;
	if (head)
	{
		do
		{
			printf(" %d 的成绩是 %f\n", p->num, p->score);
			p = p->next;
		} while (p);
	}
}

// 删除结点
struct student* deleteNode(struct student* head, int numm)
{
	struct student* p1, *p2;

	if (head == NULL) 
	{
		printf("\n这是一个空链表");
		goto END;
	}

	p1 = p2 = head;
	// 检索要删除的节点位置，未找到节点是p1指向向后移动，直到找到删除位置，位置为p1
	while (p1->num != numm && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (numm == p1->num)
	{
		if (p1 == head)   // 当将要删除的结点位于头结点时
		{
			head = p1->next;
		}
		else  // 一般情况，p2原本指向p1->next, p1指向下一个next，所以复制后p2直接直线删除下一个的next
		{
			p2->next = p1->next;
		}
		printf("删除成功！");
		n = n - 1;   // n为全局变量，为记录数据数
	}
	else
	{
		printf("删除失败，未找到数据 %d\n", numm);
	}

END:
	return head;
}

// 插入结点
struct student* insertNode(struct student* head, struct student* stu)
{
	struct student* p1, * p2, *p3;

	p1 = p2 = head;
	p3 = stu;
	if(head == NULL)
	{
		head = p3;
		p3->next = NULL;
	}
	else
	{
		// 找位置
		while ((p1->num < p3->num) && (p1->next != NULL)) // 两种情况找到目标
		{
			p2 = p1;
			p1 = p1->next;
		}
		if (p3->num <= p1->num)
		{
			if (head == p1)  // p1是头节点，插入头部
			{
				head = p3;
				p3->next = p1;
			}
			else             // 普通情况
			{
				p2->next = p3;
				p3->next = p1;
			}
		}
		else
		{
			p1->next = p3;
			p3->next = NULL;
		}
	}

	n = n + 1;

	return head;
}



/*********************************************************************************************************/
/*********************************************************************************************************/
// 固定链表
void linkList()
{
	struct student a, b, c, * head;

	a.num = 10101;
	a.score = 89.5;
	b.num = 10103;
	b.score = 90;
	c.num = 10107;
	c.score = 85;

	head = &a;
	a.next = &b;
	b.next = &c;
	c.next = NULL;

	do
	{
		printf("%1d %5.1f\n", head->num, head->score);
		head = head->next;
	} while (head);
}