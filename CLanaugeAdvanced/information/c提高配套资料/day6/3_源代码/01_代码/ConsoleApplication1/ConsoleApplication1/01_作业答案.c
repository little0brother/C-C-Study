#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�ṹ�����ͣ�ÿ����ʦ������ѧ��
typedef struct Teacher
{
	char *tName; //��ʦ
	char **stu;  //����ѧ��
	int age;
}Teacher;

//��createTeacher�з���ռ�
int createTeacher(Teacher **p/*out*/, int n1, int n2)
{
	if (p == NULL)
	{
		return -1;
	}

	Teacher *tmp = NULL; //Teacher tmp[3]
	int i = 0;
	int j = 0;
	tmp = (Teacher *)malloc(n1 * sizeof(Teacher));
	if (tmp == NULL)
	{
		return -2;
	}

	for (i = 0; i < n1; i++)
	{
		//��ʦ
		tmp[i].tName = (char *)malloc(30);

		//ѧ��
		char **s = (char **)malloc(n2 * sizeof(char *));
		for (j = 0; j < n2; j++)
		{
			s[j] = (char *)malloc(30);
		}

		//ֱ�Ӹ�ֵ
		tmp[i].stu = s;

	}
	
	//��Ӹ�ֵ��ָ������������
	*p = tmp;

	return 0;
}

//����Ա��ֵ
void initTeacher(Teacher *p, int n1, int n2)
{
	if (p == NULL)
	{
		return;
	}

	int i = 0;
	int j = 0;
	char buf[30];
	for (i = 0; i < n1; i++)
	{
		//��ʦ����
		sprintf(buf, "teacher%d%d%d", i, i, i);
		strcpy(p[i].tName, buf);

		//����
		p[i].age = 30 + 2 * i;


		//n2ѧ��
		for (j = 0; j < n2; j++)
		{
			sprintf(buf, "stu%d%d%d%d", i, i, j, j);
			strcpy(p[i].stu[j], buf);
		}
	}
}

//��ӡ�ṹ���Ա��Ϣ
void printTeacher(Teacher *p, int n1, int n2)
{
	if (p == NULL)
	{
		return;
	}

	int i;
	int j;
	for (i = 0; i < n1; i++)
	{
		//��ʦ����
		//����
		printf("%s[%d]\n", p[i].tName, p[i].age);


		//ѧ��
		for (j = 0; j < n2; j++)
		{
			printf("\t%s", p[i].stu[j]);
		}
		printf("\n");

	}

}


//���ݵ�ʦ��������, ����
void sortTeacher(Teacher *p, int n)
{
	if (p == NULL)
	{
		return;
	}

	int i = 0;
	int j = 0;

	Teacher tmp;

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
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


//�ͷſռ䣬�ں����ڲ���p��ֵΪNULL
void freeTeacher(Teacher **p, int n1, int n2)
{
	if (p == NULL)
	{
		return;
	}

	Teacher *tmp = *p;

	int i = 0;
	int j = 0;
	for (i = 0; i < n1; i++)
	{
		//�����ͷŵ�ʦ
		if (tmp[i].tName != NULL)
		{
			free(tmp[i].tName);
			tmp[i].tName = NULL;
		}


		//ѧ��
		for (j = 0; j < n2; j++)
		{
			if (tmp[i].stu[j] != NULL)
			{
				free(tmp[i].stu[j]);
				tmp[i].stu[j] = NULL;
			}
			
		}

		if (tmp[i].stu != NULL)
		{
			free(tmp[i].stu);
			tmp[i].stu = NULL;
		}
	}

	if (tmp != NULL)
	{
		free(tmp);
		*p = NULL;
	}

}

int main(void)
{
	int ret = 0;
	int n1 = 3; //��ʦ����
	int n2 = 3; //ѧ��
	Teacher *p = NULL;

	ret = createTeacher(&p, n1, n2);
	if (ret != 0)
	{
		printf("createTeacher err:%d\n", ret);
		return ret;
	}

	initTeacher(p, n1, n2); //����Ա��ֵ

	//��ӡ��Ա������ǰ
	printf("����ǰ��\n");
	printTeacher(p, n1, n2);


	//���ݵ�ʦ��������, ����
	sortTeacher(p, n1);

	//��ӡ��Ա�������
	printf("\n�����\n");
	printTeacher(p, n1, n2);

	//�ͷſռ䣬�ں����ڲ���p��ֵΪNULL
	freeTeacher(&p, n1, n2);

	printf("\n");
	system("pause");
	return 0;
}