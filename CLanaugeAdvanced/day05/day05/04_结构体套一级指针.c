#include <stdio.h>
#include <string.h>

typedef struct Teacher
{
	char* name;
	int age;
}Teacher;

#if(0)

int getMem(Teacher** tmp, int n)
{
	if (tmp == NULL)
	{
		return -1;
	}

	char buf[30];
	Teacher* q = NULL;
	q = (Teacher*)malloc(3 * sizeof(Teacher));

	for (int i = 0; i < 3; i++)
	{
		q[i].name = (char*)malloc(30);
		sprintf(buf, "lily%d", i + 1);
		strcpy(q[i].name, buf);

		q[i].age = i + 10;
	}
	for (int i = 0; i < 3; i++)
	{
		printf("%s %d\n", q[i].name, q[i].age);
	}

	*tmp = q;

	return 0;
}

int main()
{
	char* name = NULL;
	//strcpy(name, "lily");		// err 没有对name分配内存空间

	name = (char*)malloc(30);
	strcpy(name, "lily");
	printf("name = %s\n", name);

	if (name != NULL)
	{
		free(name);
		name = NULL;
	}
/**********************************************************/

	// 1
	printf("\n1.\n");
	Teacher t;
	t.name = (char*)malloc(30);
	strcpy(t.name, "lily");
	t.age = 22;
	printf("%s %d\n", t.name, t.age);

	if (t.name != NULL)
	{
		free(t.name);
		t.name = NULL;
	}

/**********************************************************/

	// 2
	printf("\n2.\n");
	Teacher* p = NULL;
	p = (Teacher*)malloc(sizeof(Teacher));
	p->name = (char*)malloc(30);
	p->age = 23;
	strcpy(p->name, "lily1");
	printf("%s %d\n", p->name, p->age);

	if (p->name != NULL)
	{
		free(p->name);
		p->name = NULL;
	}
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}

/**********************************************************/

	// 3
	printf("\n3.\n");
	Teacher* q = NULL;
	
	int ret = 0;
	ret = getMem(&q, 3);
	if (ret != 0)
	{
		printf("getMem err : %d");
		return ret;
	}
	/**
	//Teacher q[3];
	q = (Teacher*)malloc(3 * sizeof(Teacher));

	char buf[30];
	// 动态为每一个数组中的name申请内存并赋值
	for (int i = 0; i < 3; i++)
	{
		q[i].name = (char*)malloc(30);
		sprintf(buf, "lily%d", i + 1);
		strcpy(q[i].name, buf);

		q[i].age = i + 10;
	}
	for (int i = 0; i < 3; i++)
	{
		printf("%s %d\n", q[i].name, q[i].age);
	}
	*/

	// 释放空间
	for (int i = 0; i < 3; i++)
	{
		if (q[i].name != NULL)
		{
			free(q[i].name);
			q[i].name = NULL;
		}
	}
	if (q != NULL)
	{
		free(q);
		q = NULL;
	}

	return 0;
}

#endif

// 封装
#if(0)

void showTeacher(Teacher* q, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%s %d\n", q[i].name, q[i].age);
	}
}

void freeTeacher(Teacher* q, int n)
{
	// 释放空间
	for (int i = 0; i < n; i++)
	{
		if (q[i].name != NULL)
		{
			free(q[i].name);
			q[i].name = NULL;
		}
	}
	if (q != NULL)
	{
		free(q);
		q = NULL;
	}
}

int main()
{
	Teacher* q = NULL;
	//Teacher q[3];
	q = (Teacher*)malloc(3 * sizeof(Teacher));

	char buf[30];
	// 动态为每一个数组中的name申请内存并赋值
	for (int i = 0; i < 3; i++)
	{
		q[i].name = (char*)malloc(30);
		sprintf(buf, "lily%d", i + 1);
		strcpy(q[i].name, buf);

		q[i].age = i + 10;
	}
	
	showTeacher(q, 3);

	freeTeacher(q, 3);
	q = NULL;



	return 0;
}
#endif