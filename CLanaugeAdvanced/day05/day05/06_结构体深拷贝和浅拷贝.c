#include <stdio.h>

typedef struct Teacher
{
	char* name;
	int age;
}Teacher;

// ǳ��������������
// 1.�ṹ����Ƕ��ָ�룬���Ҷ�̬����ռ�
// 2.ͬ���ͽṹ�������ֵ
// 3.��ͬ�ṹ���Աָ�����ָ��ͬһ���ڴ�
int main()
{
	Teacher t1;
	t1.name = (char*)malloc(30);
	strcpy(t1.name, "Alice");
	t1.age = 22;

	Teacher t2;

#if(0)
/*******************ǳ����*****************************/
	// ǳ����
	t2 = t1;
	printf("[t2] %s, %d\n", t2.name, t2.age);

	if (t1.name != NULL)
	{
		free(t1.name);
		t1.name = NULL;
	}

	// err ��Ϊͬһ�ڴ���ͷ������Σ������ڴ����
	//if (t2.name != NULL)
	//{
	//	free(t2.name);
	//	t2.name = NULL;
	//}
/***************************************************/
#endif

#if(1)
	/*******************���*****************************/

	t2 = t1;
	// ���, ��Ϊ�����ڴ棬���¿���һ��
	t2.name = (char*)malloc(30);
	strcpy(t2.name, t1.name);

	printf("[t2] %s, %d\n", t2.name, t2.age);

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
#endif

	return 0;
}