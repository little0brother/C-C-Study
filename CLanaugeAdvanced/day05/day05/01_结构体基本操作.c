#include <stdio.h>
#include <string.h>

/*
	1���ṹ�����Ͷ���
	2���ṹ���������
	3���ṹ������ĳ�ʼ��
	4��typedef��������
	5�����������ָ�뷨�����ṹ��
	6���ṹ��Ҳ��һ���������ͣ��������ͣ��Զ�������
*/

// 1.�ṹ�����Ͷ���
// struct �ؼ���
// struct Teacher ��һ���������
// {} �����ַֺ�
struct Teacher
{
	char name[50];
	int age;
};

// 2.�ṹ���������
// 1).�ȶ������ͣ��ڶ�����������ã�
struct Teacher t1; // ȫ�ֱ���

// 2).��������ͬʱ�������
struct Teacher2
{
	char name[50];
	int age;
}t3 = {"tmo", 12};

struct
{
	char name[50];
	int age;
}t5, t6;


// 3.�ṹ������ĳ�ʼ��
// �������ͬʱֱ�ӳ�ʼ����ͨ��{}
struct Teacher t7 = { "da", 18};

// 4.typedef��������
typedef struct Teacher3
{
	char name[50];
	int age;
}Teacher3;

struct Teacher3 t8;
Teacher3 t9;


int main()
{
	// 1).�ȶ������ͣ��ڶ�����������ã�
	struct Teacher t2; // �ֲ�����

	printf("%s, %d", t7.name, t7.age);

	// 5.���������ָ�뷨�����ṹ��
	/*
		struct Teacher
		{
			char name[50];
			int age;
		};
	*/
	strcpy(t2.name, "xiaoming");
	t2.age = 22;
	printf("\n%s, %d", t2.name, t2.age);

	// �ṹ��ָ�������û��ָ���ڴ�ռ䣬���ܸ���Ա��ֵ
	struct Teacher* p = NULL;
	p = &t2;
	strcpy(p->name, "xiaosssing");
	p->age = 22;
	printf("\n%s, %d", p->name, p->age);

	return 0;
}