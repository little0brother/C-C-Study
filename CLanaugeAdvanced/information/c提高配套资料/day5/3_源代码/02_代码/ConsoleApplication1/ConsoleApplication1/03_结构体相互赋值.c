#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//����ṹ�������ǲ�Ҫֱ�Ӹ���Ա��ֵ
//�ṹ��ֻ��һ�����ͣ���û�з���ռ�
//ֻ�и��������Ͷ������ʱ���ŷ���ռ䣬�пռ����ܸ�ֵ
typedef struct Teacher
{
	char name[50];
	int age; 
}Teacher;

void copyTeacher(Teacher to, Teacher from)
{
	to = from;
	printf("[copyTeacher] %s, %d\n", to.name, to.age);
}

void copyTeacher2(Teacher *to, Teacher *from)
{
	*to = *from;
	//printf("[copyTeacher] %s, %d\n", to.name, to.age);
}


void fun(int to, int from)
{
	to = from;
}

int main(void)
{
	Teacher t1 = { "lily", 22 };

	//��ͬ���͵������ṹ������������໥��ֵ
	//��t1��Ա�����ڴ��ֵ������t2��Ա�������ڴ�
	//t1��t2û�й�ϵ
	Teacher t2 = t1;
	printf("%s, %d\n", t2.name, t2.age);

	int a = 10;
	int b = a; //a��ֵ����b, a, bû�й�ϵ


	Teacher t3;
	memset(&t3, 0, sizeof(t3));
	copyTeacher2(&t3, &t1); //t1������t3
	printf("[t3]%s, %d\n", t3.name, t3.age);

	int c = 10;
	int d = 0;
	fun(d, c); //c��ֵ��b
	printf("d = %d\n", d);


	printf("\n");
	system("pause");
	return 0;
}