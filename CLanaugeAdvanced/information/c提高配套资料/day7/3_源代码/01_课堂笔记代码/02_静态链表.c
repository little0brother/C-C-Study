#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Stu
{
	int id;	//������
	char name[100];

	struct Stu *next; //ָ����
}Stu;

int main(void)
{
	//��ʼ�������ṹ�����
	Stu s1 = { 1, "mike", NULL };
	Stu s2 = { 2, "lily", NULL };
	Stu s3 = { 3, "lilei", NULL };

	
	s1.next = &s2; //s1��nextָ��ָ��s2
	s2.next = &s3;
	s3.next = NULL; //β���


	Stu *p = &s1; 

	while (p != NULL)
	{
		printf("id = %d, name = %s\n", p->id, p->name);

		//��������ƶ�һλ
		p = p->next; //&s2
	}


	printf("\n");
	system("pause");
	return 0;
}