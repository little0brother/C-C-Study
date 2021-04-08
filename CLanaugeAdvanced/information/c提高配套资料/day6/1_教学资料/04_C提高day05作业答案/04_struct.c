#define  _CRT_SECURE_NO_WARNINGS 
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

	//�����ṹ�壬Teacher t[3]
	Teacher *t = (Teacher *)malloc(sizeof(Teacher)* n1);
	if (t == NULL)
	{
		return -2;
	}

	int i = 0;
	int j = 0;
	for (i = 0; i < n1; i++) //ÿ����ʦ�ĵ�ʦ��n2��ѧ������ռ�
	{
		//��ʦ����
		t[i].tName = (char *)malloc(50 * sizeof(char) );

		//ÿ����ʦ��n2��ѧ��
		char **tmp = (char **)malloc(n2 * sizeof(char * ) ); //char *tmp[i]
		for (j = 0; j < n2; j++)
		{
			tmp[j] = (char *)malloc(50);
		}

		t[i].stu = tmp; //��Ҫ

	}

	//��Ӹ�ֵ��ָ������������
	*p = t;

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
	char buf[50] = { 0 };

	for (i = 0; i < n1; i++)
	{
		//��ʦ����
		sprintf(buf, "teacher%d%d%d", i, i, i);
		strcpy(p[i].tName, buf);
		
		//ÿ����ʦ��n2��ѧ��
		for (j = 0; j < n2; j++)
		{
			sprintf(buf, "stu%d%d%d%d", i, i, j, j);
			strcpy(p[i].stu[j], buf);
		}

		//����
		p[i].age = 20 + 2*i;
	}

}

//��ӡ�ṹ���Ա��Ϣ
void printTeacher(Teacher *p, int n1, int n2)
{
	if (p == NULL)
	{
		return;
	}

	//�ȴ�ӡ��ʦ���ٴ�ӡѧ��
	int i = 0;
	int j = 0;
	char buf[50] = { 0 };

	for (i = 0; i < n1; i++)
	{
		
		printf("%s[%d]\n", p[i].tName, p[i].age);

		//ÿ����ʦ��n2��ѧ��
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

	//ѡ������
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(p[i].tName, p[j].tName) < 0) //����
			{
				//������Ա������ֵ
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

	Teacher *t = *p;
	int i = 0;
	int j = 0;

	for (i = 0; i < n1; i++)
	{
		//���ͷŵ�ʦ
		if (t[i].tName != NULL)
		{
			free(t[i].tName);
			t[i].tName = NULL;
		}

		//���ͷŵ�ʦ���µ�ѧ��
		for (j = 0; j < n2; j++)
		{
			if (t[i].stu[j] != NULL)
			{
				free(t[i].stu[j]);
				t[i].stu[j] = NULL;
			}
		}

		if (t[i].stu != NULL)
		{
			free(t[i].stu);
			t[i].stu = NULL;
		}
	}

	if (t != NULL)
	{
		free(t);
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