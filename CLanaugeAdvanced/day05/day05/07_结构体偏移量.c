#include <stdio.h>

// �ṹ�����Ͷ����������ڲ��ĳ�Ա�������ڴ沼���Ѿ�ȷ��
typedef struct Teacher
{
	char name[64];	// 4
	int age;		// 4
	int id;			// 4
}Teacher;

int main()
{
	Teacher t1;
	Teacher* p = NULL;
	p = &t1;

	int n1 = (int)(&p->age) - (int)p;	// age�����ṹ���׵�ַƫ����
	printf("n1 = %d\n", n1);

	int n2 = (int)&((Teacher*)0)->age;	// ����0��ַ��ƫ����
	printf("n2 = %d\n", n2);

	return 0;
}