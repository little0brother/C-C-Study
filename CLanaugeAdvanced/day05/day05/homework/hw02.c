/* 重写结构体嵌套一级指针老师和二级指针学生的代码*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

// 结构体类型，每个导师有三个学生
typedef struct Teacher
{
	char* tName; //导师
	char** stu;  //三个学生
	int age;
}Teacher;

// 在createTeacher中分配空间
int createTeacher(Teacher** p/*out*/, int n1, int n2)
{
	// 申请结构体数组的存储空间
	Teacher* tmp = (Teacher*)malloc(n1 * sizeof(Teacher));
	if (tmp == NULL)
	{
		return -1;
	}

	// 对结构体中的stu变量申请内存空间
	for (int i = 0; i < n1; i++)
	{
		// 导师
		tmp[i].tName = (char*)malloc(30 * sizeof(char));
		if (tmp[i].stu == NULL)
		{
			return -2;
		}

		// 学生
		//tmp[i].stu = (char**)malloc(n2 * sizeof(char*));
		char** s = (char**)malloc(n2 * sizeof(char*));
		for (int j = 0; j < n2; j++)
		{
			s[j] = (char*)malloc(30 * sizeof(char));
			if (s[j] == NULL)
			{
				return -3;
			}
		}
		tmp[i].stu = s;
	}

	*p = tmp;

	return 0;
}

// 给成员赋值
void initTeacher(Teacher* p, int n1, int n2)
{
	if (p == NULL)
	{
		return;
	}

	char tmp[30];
	
	for (int i = 0; i < n1; i++)
	{	
		// 导师
		//srand((unsigned)time(NULL));
		p[i].age = rand();
		sprintf(tmp, "IntordTeacher%d", i + 1);
		strcpy(p[i].tName, tmp);

		// 学生
		for (int j = 0; j < n2; j++)
		{
			sprintf(tmp, "Alice%d", i + j + 1);
			strcpy(p[i].stu[j], tmp);
		}
	}
}

// 打印结构体成员信息
void printTeacher(Teacher* p, int n1, int n2)
{
	if (p == NULL)
	{
		return;
	}

	for (int i = 0; i < n1; i++)
	{
		printf("TeacherName:%s [age]:%d ", p[i].tName, p[i].age);
		for (int j = 0; j < n2; j++)
		{
			printf(" stu:%s", p[i].stu[j]);
		}
		printf("\n");
	}
}

// 根据导师名字排序, 降序
void sortTeacher(Teacher* p, int n)
{
	if (p == NULL)
	{
		return;
	}

	Teacher tmp;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(p[i].tName, p[j].tName) < 0)
			{
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}
}


// 释放空间，在函数内部把p赋值为NULL
void freeTeacher(Teacher** p, int n1, int n2)
{
	if (p == NULL)
	{
		return;
	}

	Teacher* tmp = *p;
	for (int i = 0; i < n1; i++)
	{
		// 释放教师姓名节点
		if (tmp[i].tName != NULL)
		{
			free(tmp[i].tName);
			tmp[i].tName = NULL;
		}

		// 先释放学生中名字指针
		for (int j = 0; j < n2; j++)
		{
			if (tmp[i].stu[j] != NULL)
			{
				free(tmp[i].stu[j]);
				tmp[i].stu[j] = NULL;
			}
		}

		// 释放学生
		if (tmp[i].stu != NULL)
		{
			free(tmp[i].stu);
			tmp[i].stu = NULL;
		}
	}

	if (tmp != NULL)
	{
		free(tmp);
		tmp = NULL;
	}
}

int main(void)
{
	int ret = 0;
	int n1 = 3; //导师个数
	int n2 = 3; //学生
	Teacher* p = NULL;

	ret = createTeacher(&p, n1, n2);
	if (ret != 0)
	{
		printf("createTeacher err:%d\n", ret);
		return ret;
	}

	initTeacher(p, n1, n2); //给成员赋值

	//打印成员，排序前
	printf("排序前：\n");
	printTeacher(p, n1, n2);


	//根据导师名字排序, 降序
	sortTeacher(p, n1);

	//打印成员，排序后
	printf("\n排序后：\n");
	printTeacher(p, n1, n2);

	//释放空间，在函数内部把p赋值为NULL
	freeTeacher(&p, n1, n2);

	return 0;
}