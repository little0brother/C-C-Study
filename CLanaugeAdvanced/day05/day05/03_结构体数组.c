#include <stdio.h>
#include <string.h>

typedef struct Teacher
{
	char name[50];
	//char* name;
	int age;
}Teacher;

int main()
{
	Teacher a[3] = { {"a", 12}, {"b", 13}, {"c", 14} };
	// ��̬
	Teacher a2[3] = { "af", 123, "ba", 113, "ch", 14 };

	for (int i = 0; i < 3; i++)
	{
		printf("%s, %d\n", a2[i].name, a2[i].age);
	}

	// int a[3]
	// int* , sprintf()

	int b[3] = { 0 };
	int* pB = (int*)malloc(3 * sizeof(int));
	free(pB);

	// ��̬����ṹ�����, int p[3]
	Teacher* p = (Teacher*)malloc(3 * sizeof(Teacher));
	if (p == NULL)
	{
		return -1;
	}

	// ���ڴ���дֵ
	char buf[50];
	for (int i = 0; i < 3; i++)
	{
		sprintf(buf, "name%d%d%d", i, i, i);
		strcpy(p[i].name, buf);
		p[i].age = 20 + i;
	}

	// ���
	for (int i = 0; i < 3; i++)
	{
		printf("��%d����%s, %d\n", i + 1, p[i].name, p[i].age);
	}
	printf("\n");

	// �ͷ��ڴ�ռ�
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}

	return 0;
}