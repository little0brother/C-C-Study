#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Teacher
{
	char *name;
	int age;
}Teacher;

//�ṹ����Ƕ��ָ�룬���Ҷ�̬����ռ�
//ͬ���ͽṹ�������ֵ
//��ͬ�ṹ���Աָ�����ָ��ͬһ���ڴ�
int main(void)
{
	Teacher t1;
	t1.name = (char *)malloc(30);
	strcpy(t1.name, "lily");
	t1.age = 22;

	Teacher t2;
	t2 = t1;
	//�������Ϊ�������ݣ����¿���һ��
	t2.name = (char *)malloc(30);
	strcpy(t2.name, t1.name);


	printf("[t2]%s, %d\n", t2.name, t2.age);

	if (t1.name != NULL)
	{
		free(t1.name);
		t1.name = NULL;
	}

	if (t2.name != NULL)
	{
		free(t2.name);
		t2.name = NULL;
	}


	printf("\n");
	system("pause");
	return 0;
}