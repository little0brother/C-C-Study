#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
1���ṹ�����Ͷ���
2���ṹ���������
3���ṹ������ĳ�ʼ��
4��typedef��������
5�����������ָ�뷨�����ṹ��
6���ṹ��Ҳ��һ���������ͣ��������ͣ��Զ�������
*/

//1���ṹ�����Ͷ���
//struct�ؼ���
//struct Teacher��һ���������
//{}�����зֺ�
struct Teacher
{
	char name[50];
	int age;
};

//2���ṹ���������
//1.�ȶ������ͣ��ٶ�����������ã�
struct Teacher t1; //ȫ�ֱ���


//2. ��������ͬʱ�������
struct Teacher2
{
	char name[50];
	int age;
}t3 = {"tom", 66};

struct
{
	char name[50];
	int age;
}t5;

//3���ṹ������ĳ�ʼ��
//�������ʱֱ�ӳ�ʼ����ͨ��{}
struct Teacher t7 = { "lily", 18 };

//4��typedef��������
typedef struct Teacher3
{
	char name[50];
	int age;
}Teacher3;

struct Teacher3 t8;
Teacher3 t9;

int main(void)
{
	//1.�ȶ������ͣ��ٶ�����������ã�
	struct Teacher t2; //�ֲ�����

	printf("%s, %d\n", t7.name, t7.age);

	//5�����������ָ�뷨�����ṹ��

	/*
	struct Teacher
	{
		char name[50];
		int age;
	};
	*/
	strcpy(t2.name, "xiaoming");
	t2.age = 22;
	printf("%s, %d\n", t2.name, t2.age);

	//�ṹ��ָ�������û��ָ��ռ䣬���ܸ����Ա��ֵ
	struct Teacher *p = NULL;
	p = &t2;
	strcpy(p->name, "xiaojiang");
	p->age = 22;
	printf("%s, %d\n", p->name, p->age);


	printf("\n");
	system("pause");
	return 0;
}