#include <stdio.h>
#include <string.h>

// 一个导师有N个学生
typedef struct Teacher
{
	int age;
	char** stu;	// 二维内存
}Teacher;

// 实现的基本方法
#if(0)
int main()
{
/********************************************************************/
#if(0)
	// 二级指针申请内存空间
	char** name = NULL;
	// char *name[3]
	int n = 3;
	name = (char**)malloc(n * sizeof(char*));
	// char buf[30]
	for (int i = 0; i < n; i++)
	{
		name[i] = (char*)malloc(30);
		strcpy(name[i], "lily");
	}

	for (int i = 0; i < n; i++)
	{
		printf("%s ", name[i]);
	}

	for (int i = 0; i < n; i++)
	{
		if (name[i] != NULL)
		{
			free(name[i]);
			name[i] = NULL;
		}
	}

	if (name != NULL)
	{
		free(name);
		name = NULL;
	}
#endif
/********************************************************************/
	int n = 3;
	char tmp[30];

	// 1.
	Teacher t;
	// t.stu[3]

	// 与二级指针申请内存方法相同
	t.stu = (char**)malloc(3 * sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		t.stu[i] = (char*)malloc(30 * sizeof(char));

		sprintf(tmp, "Alice%d", i + 1);
		strcpy(t.stu[i], tmp);
	}

	for (int i = 0; i < n; i++)
	{
		printf("%s \n", t.stu[i]);
	}

	// 释放内存空间
	for (int i = 0; i < n; i++)
	{
		if (t.stu[i] != NULL)
		{
			free(t.stu[i]);
			t.stu[i] = NULL;
		}
	}
	if (t.stu != NULL)
	{
		free(t.stu);
		t.stu = NULL;
	}

	printf("\n");
/********************************************************************/
	// 2.
	Teacher* p = NULL;
	// p->stu[3]

	// 1）先对指针p 申请内存空间
	p = (Teacher*)malloc(1 * sizeof(Teacher));
	// 2）再对结构体中的 二级指针申请内存空间
	p->stu = (char**)malloc(n * sizeof(char*));
	// 3）最后为字符串申请内存空间
	for (int i = 0; i < n; i++)
	{
		p->stu[i] = (char*)malloc(30 * sizeof(char));

		sprintf(tmp, "Alice%d", i + 10);
		strcpy(p->stu[i], tmp);
	}

	for (int i = 0; i < n; i++)
	{
		printf("%s \n", p->stu[i]);
	}

	// 释放内存空间
	for (int i = 0; i < n; i++)
	{
		if (p->stu[i] != NULL)
		{
			free(p->stu[i]);
			p->stu[i] = NULL;
		}
	}
	if (p->stu != NULL)
	{
		free(p->stu);
		p->stu = NULL;
	}
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}

	printf("\n");
/********************************************************************/
	// 3.
	Teacher* q = NULL;
	//Teacher q[3]		q[i].stu[3]

	// 1）先对Teacher*q 申请3个大小为Teachar结构体变量的空间
	q = (Teacher*)malloc(n * sizeof(Teacher));	//  = Teacher q[3]
	if (q == NULL)
	{
		return -1;
	}

	// 2）对q[i].stu中的二级指针，申请存储字符串的内存空间
	for (int i = 0; i < n; i++)
	{
		q[i].stu = (char**)malloc(n * sizeof(char*));
		// char* stu[3]
		if (q[i].stu == NULL)
		{
			return -2;
		}

		// 3）对q[i].stu[j]申请字符串的长度，存放数据
		for (int j = 0; j < n; j++)
		{
			// char buf[30]
			q[i].stu[j] = (char*)malloc(30 * sizeof(char));
			if (q[i].stu[j] == NULL)
			{
				return -3;
			}

			sprintf(tmp, "Alice%d", i + j + 20);
			strcpy(q[i].stu[j], tmp);
		}
	}

	// 3）对q[i].stu[j]申请字符串的长度，存放数据
	// 方法二
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		// char buf[30]
	//		q[i].stu[j] = (char*)malloc(30 * sizeof(char));
	//		if (q[i].stu[j] == NULL)
	//		{
	//			return -3;
	//		}
	//
	//		sprintf(tmp, "Alice%d", i + 20);
	//		strcpy(q[i].stu[j], tmp);
	//	}
	//}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%s ", q[i].stu[j]);
		}
		printf("\n");
	}

	// 释放内存空间
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (q[i].stu[j] != NULL)
			{
				free(q[i].stu[j]);
				q[i].stu[j] = NULL;
			}
		}

		if (q[i].stu != NULL)
		{
			free(q[i].stu);
			q[i].stu = NULL;
		}
	}
	
	//for (int i = 0; i < n; i++)
	//{
	//	if (q[i].stu != NULL)
	//	{
	//		free(q[i].stu);
	//		q[i].stu = NULL;
	//	}
	//}
	
	if (q != NULL)
	{
		free(q);
		q = NULL;
	}

	return 0;
}
#endif

// 封装
#if(1)

int getMem(Teacher** p, int n1, int n2)
{
	if (p == NULL)
	{
		return -1;
	}
	
	char tmp[30];

	// 1）先对Teacher*q 申请3个大小为Teachar结构体变量的空间
	Teacher* q = (Teacher*)malloc(n1 * sizeof(Teacher));	//  = Teacher q[3]
	if (q == NULL)
	{
		return -1;
	}

	// 2）对q[i].stu中的二级指针，申请存储字符串的内存空间
	for (int i = 0; i < n1; i++)
	{
		q[i].stu = (char**)malloc(n2 * sizeof(char*));
		// char* stu[3]
		if (q[i].stu == NULL)
		{
			return -2;
		}

		// 3）对q[i].stu[j]申请字符串的长度，存放数据
		for (int j = 0; j < n2; j++)
		{
			// char buf[30]
			q[i].stu[j] = (char*)malloc(30 * sizeof(char));
			if (q[i].stu[j] == NULL)
			{
				return -3;
			}

			sprintf(tmp, "Alice%d", i + j + 20);
			strcpy(q[i].stu[j], tmp);

			q[i].age = i + 10;
		}
	}

	*p = q;

	return 0;
}

int freeMem(Teacher** p, int n1, int n2)
{
	if (p == NULL)
	{
		return -1;
	}

	Teacher* q = *p;

	// 释放内存空间
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			if (q[i].stu[j] != NULL)
			{
				free(q[i].stu[j]);
				q[i].stu[j] = NULL;
			}
		}

		if (q[i].stu != NULL)
		{
			free(q[i].stu);
			q[i].stu = NULL;
		}
	}

	if (q != NULL)
	{
		free(q);
		q = NULL;
	}

	return 0;
}

void showTeacher(Teacher* q, int n1, int n2)
{
	for (int i = 0; i < n1; i++)
	{
		printf("[TeacherAge:%d]   ", q[i].age);
		for (int j = 0; j < n2; j++)
		{
			printf("%s ", q[i].stu[j]);
		}
		printf("\n");
	}
}

// 根据年龄排序
int sortByAge(Teacher* swit, int n)
{
	if (swit == NULL)
	{
		return -1;
	}

	//Teacher* swit = *p;
	Teacher tmp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			// 降序
			if (swit[i].age < swit[j].age)
			{
				tmp = swit[i];
				swit[i] = swit[j];
				swit[j] = tmp;
			}
		}
	}

	return 0;
}

int main()
{	
	Teacher* q = NULL;
	//Teacher q[3]		q[i].stu[3]
	int n1 = 3;	// 老师人数
	int n2 = 3;	// 学生人数
	int ret = 0;

	ret = getMem(&q, n1, n2);
	if (ret != 0)
	{
		printf("getMem err : %d\n", ret);
		return ret;
	}

	printf("排序前：\n");
	showTeacher(q, n1, n2);

	ret = sortByAge(q, n1);
	if (ret != 0)
	{
		printf("sortByAge err : %d \n", ret);
		return ret;
	}

	printf("\n排序后：\n");
	showTeacher(q, n1, n2);
	
	ret = freeMem(&q, n1, n2);
	if (ret != 0)
	{
		printf("freeMem err : %d\n", ret);
		return ret;
	}

	return 0;
}
#endif