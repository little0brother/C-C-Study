/* ��д�ṹ��Ƕ��һ��ָ����ʦ�Ͷ���ָ��ѧ���Ĵ���*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

// �ṹ�����ͣ�ÿ����ʦ������ѧ��
typedef struct Teacher
{
	char* tName; //��ʦ
	char** stu;  //����ѧ��
	int age;
}Teacher;

// ��createTeacher�з���ռ�
int createTeacher(Teacher** p/*out*/, int n1, int n2)
{
	// ����ṹ������Ĵ洢�ռ�
	Teacher* tmp = (Teacher*)malloc(n1 * sizeof(Teacher));
	if (tmp == NULL)
	{
		return -1;
	}

	// �Խṹ���е�stu���������ڴ�ռ�
	for (int i = 0; i < n1; i++)
	{
		// ��ʦ
		tmp[i].tName = (char*)malloc(30 * sizeof(char));
		if (tmp[i].stu == NULL)
		{
			return -2;
		}

		// ѧ��
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

// ����Ա��ֵ
void initTeacher(Teacher* p, int n1, int n2)
{
	if (p == NULL)
	{
		return;
	}

	char tmp[30];
	
	for (int i = 0; i < n1; i++)
	{	
		// ��ʦ
		//srand((unsigned)time(NULL));
		p[i].age = rand();
		sprintf(tmp, "IntordTeacher%d", i + 1);
		strcpy(p[i].tName, tmp);

		// ѧ��
		for (int j = 0; j < n2; j++)
		{
			sprintf(tmp, "Alice%d", i + j + 1);
			strcpy(p[i].stu[j], tmp);
		}
	}
}

// ��ӡ�ṹ���Ա��Ϣ
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

// ���ݵ�ʦ��������, ����
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


// �ͷſռ䣬�ں����ڲ���p��ֵΪNULL
void freeTeacher(Teacher** p, int n1, int n2)
{
	if (p == NULL)
	{
		return;
	}

	Teacher* tmp = *p;
	for (int i = 0; i < n1; i++)
	{
		// �ͷŽ�ʦ�����ڵ�
		if (tmp[i].tName != NULL)
		{
			free(tmp[i].tName);
			tmp[i].tName = NULL;
		}

		// ���ͷ�ѧ��������ָ��
		for (int j = 0; j < n2; j++)
		{
			if (tmp[i].stu[j] != NULL)
			{
				free(tmp[i].stu[j]);
				tmp[i].stu[j] = NULL;
			}
		}

		// �ͷ�ѧ��
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
	int n1 = 3; //��ʦ����
	int n2 = 3; //ѧ��
	Teacher* p = NULL;

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

	return 0;
}