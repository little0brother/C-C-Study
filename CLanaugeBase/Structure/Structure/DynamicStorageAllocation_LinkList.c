/**********************/
/* ��̬�洢����AND���� */
/**********************/

/* problem: ��δʵ�ֶ�β�����ɾ�����Ŵ��ܵȵ� ��ʱ���� */

#include <stdio.h>

#define LEN sizeof(struct student)	 // student�ṹ�Ĵ�С

int n; // ��¼����˶�������

struct student
{
	int num;
	float score;
	struct student* next;   // ָ����һ���ṹ
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

// ��̬����
/* ��������ѧ��(ѧ�ţ��ɼ�)���ݵĵ���̬����ѧ��Ϊ���ʾ����������� */
void dynamicLinkList()
{
	struct student* stu, stu_1;

	// ������̬����
	stu = creatList();
	// ��ӡ����
	print(stu);

	// ɾ���ڵ�
	int numm;
	printf("\n��������ɾ�����ݵ�ѧ��: ");
	scanf("%d", &numm);

	print(deleteNode(stu, numm));

	// ������
	printf("����������ݵ�ѧ��: ");
	scanf("%d", &stu_1.num);
	printf("����������ݵĳɼ�: ");
	scanf("%f", &stu_1.score);

	print(insertNode(stu, &stu_1));
}

// ��������
struct student* creatList()
{
	struct student* stu1;
	struct student* head;
	struct student* p1, * p2;

	// �����ڴ�ռ�
	p1 = p2 = (struct student*)malloc(LEN);

	printf("����ѧ��ѧ��: ");
	scanf("%d", &p1->num);
	printf("����ѧ���ɼ�: ");
	scanf("%f", &p1->score);
	printf("\n");

	// ��ʼ������
	head = NULL;
	n = 0;

	// ��̬�ֲ��ڴ潨������
	while (p1->num)
	{
		n++;
		if (1 == n)
		{
			head = p1;		// ����ͷָ��
		}
		else
		{
			p2->next = p1;
		}

		p2 = p1;
		p1 = (struct student*)malloc(LEN);

		printf("����ѧ��ѧ��: ");
		scanf("%d", &p1->num);
		printf("����ѧ���ɼ�: ");
		scanf("%f", &p1->score);
		printf("\n");
	}

	p2->next = NULL;

	return head;
}

// ��ӡ����
void print(struct student* head)
{
	struct student* p;
	// �������� �������
	printf("\n����%d������\n", n);
	p = head;
	if (head)
	{
		do
		{
			printf(" %d �ĳɼ��� %f\n", p->num, p->score);
			p = p->next;
		} while (p);
	}
}

// ɾ�����
struct student* deleteNode(struct student* head, int numm)
{
	struct student* p1, *p2;

	if (head == NULL) 
	{
		printf("\n����һ��������");
		goto END;
	}

	p1 = p2 = head;
	// ����Ҫɾ���Ľڵ�λ�ã�δ�ҵ��ڵ���p1ָ������ƶ���ֱ���ҵ�ɾ��λ�ã�λ��Ϊp1
	while (p1->num != numm && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (numm == p1->num)
	{
		if (p1 == head)   // ����Ҫɾ���Ľ��λ��ͷ���ʱ
		{
			head = p1->next;
		}
		else  // һ�������p2ԭ��ָ��p1->next, p1ָ����һ��next�����Ը��ƺ�p2ֱ��ֱ��ɾ����һ����next
		{
			p2->next = p1->next;
		}
		printf("ɾ���ɹ���");
		n = n - 1;   // nΪȫ�ֱ�����Ϊ��¼������
	}
	else
	{
		printf("ɾ��ʧ�ܣ�δ�ҵ����� %d\n", numm);
	}

END:
	return head;
}

// ������
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
		// ��λ��
		while ((p1->num < p3->num) && (p1->next != NULL)) // ��������ҵ�Ŀ��
		{
			p2 = p1;
			p1 = p1->next;
		}
		if (p3->num <= p1->num)
		{
			if (head == p1)  // p1��ͷ�ڵ㣬����ͷ��
			{
				head = p3;
				p3->next = p1;
			}
			else             // ��ͨ���
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
// �̶�����
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