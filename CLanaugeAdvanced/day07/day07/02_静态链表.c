#include <stdio.h>

typedef struct Stu
{
	int id; // ������
	char name[100];

	struct Stu* next;	// ָ����
}Stu;

int main()
{
	// ��ʼ�������ṹ��
	Stu s1 = { 1, "fuc", NULL };
	Stu s2 = { 2, "bob", NULL };
	Stu s3 = { 3, "tom", NULL };

	s1.next = &s2;	 // s1��nextָ��s2
	s2.next = &s3;
	s3.next = NULL;	 // β�ڵ�

	Stu* p = &s1; 

	while (p != NULL)
	{
		printf("id = %d, name = %s\n", p->id, p->name);

		// �ڵ������ƶ�һλ
		p = p->next;
	}

	return 0;
}