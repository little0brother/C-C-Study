#include <stdio.h>

// ����ṹ������ʱ��Ҫֱ�Ӹ���Ա��ֵ
// �ṹ��ֻ��һ�����ͣ���û�з���ռ�
// ֻ�и��������Ͷ������ʱ���ŷ���ռ䣬�пռ����ܸ�ֵ
typedef struct Teacher
{
	char name[50];
	int age;
}Teacher;

// ֵ���ݲ���Ӱ���ַ����
void copyTeacher(Teacher to, Teacher from)
{
	to = from;
	printf("[copyTeacher] %s %d\n", to.name, to.age);
}

// ��ַ���ݲŻ�����仯
void copyTeacher1(Teacher* to, Teacher* from)
{
	*to = *from;
	//printf("[copyTeacher] %s %d\n", to.name, to.age);
}

void fun(int to, int from)
{
	to = from;
}

int main()
{
	Teacher t1 = { "Alice", 22 };
	// ��ͬ���͵������ṹ������������໥��ֵ
	// ��t1��Ա�����ڴ��ֵ������t2��Ա�������ڴ�
	// t1��t2û����ϵ
	Teacher t2 = t1;
	printf("%s %d\n", t2.name, t2.age);

	int a = 10;
	int b = a;	// a��ֵ����b, a, b֮��û�й�ϵ

	Teacher t3;
	memset(&t3, 0, sizeof(t3));	// ���ڴ���ڵ�ַ��Ϊ0
	// ͨ���������п���
	//copyTeacher(t3, t1);	// t1������t3
	copyTeacher1(&t3, &t1);	// t1������t3
	printf("[t3] %s %d\n", t3.name, t3.age);

	// ֵ���ݲ���Ӱ������
	int c = 10;
	int d = 0;
	fun(d, c); // ��c��ֵ��b
	printf("d = %d\n", d);

	return 0;
}