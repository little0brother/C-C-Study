#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct teacher
{
	char **stu;
	int age;
}teacher;

int main(void)
{
	int n = 5;
	teacher *a = NULL;
	a = (teacher*)malloc(sizeof(teacher)*n);
	for (int i = 0; i < n; i++)
	{
		a[i].stu = (char**)malloc(n*sizeof(char*));
		a[i].age = 18 + i;
		for (int j = 0; j < n; j++)
		{
			a[i].stu[j] = (char*)malloc(30);
			char buf[30] = { 0 };
			sprintf(buf, "name%d%d", i, j);
			strcpy(a[i].stu[j], buf);
		}
	}
	teacher tem;
	for (int i = 0; i < n; i++)
	for (int j = i + 1; j < n; j++)
	{
		if (a[i].age < a[j].age)
		{
			tem = a[i];
			a[i] = a[j];
			a[j] = tem;

		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d %s\n", a[i].age, a[i].stu[j]);
		}
	}
	//teacher tem;
	/*for (int i = 0; i < n; i++)
	for (int j = i + 1; j < n; j++)
	{
	if (a[i].age < a[j].age)
	{
	tem = a[i];
	a[i] = a[j];
	a[j] = tem;

	}
	}*/
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			free(a[i].stu[j]);
		}
		free(a[i].stu);
	}
	free(a);
	printf("\n");
	system("pause");
	return 0;
}
