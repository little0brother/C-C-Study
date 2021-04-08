#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stu
{
	char name[50];
	int id;
	double score;
}Stu;

//�Ӽ�������ѧ����Ϣ
void initStu(Stu *s, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("�������%d��ѧ����Ϣ��\n", i+1);
		printf("������������");
		scanf("%s", s[i].name);
		
		printf("������ѧ�ţ�");
		scanf("%d", &s[i].id);

		printf("�����������");
		scanf("%lf", &s[i].score);
	}
}

//��ƽ����
double aveStu(Stu *s, int n)
{
	int i = 0;
	double allScore = 0.0;

	for (i = 0; i < n; i++)
	{
		allScore += s[i].score; //�����ۼ�
	}
	
	return allScore / (n*1.0);
}

//�������򣬽���
void sortStu(Stu *s, int n)
{
	int i = 0; 
	int j = 0;
	Stu tmp;
	
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (s[i].score < s[j].score) //����
			{
				tmp = s[i];
				s[i] = s[j];
				s[j] = tmp;
			}
		}
	}
}

//��ӡѧ����Ϣ
void showStu(Stu *s, int n)
{
	int i = 0;

	printf("\nѧ����Ϣ���£�\n");
	printf("����\tѧ��\t����\n");
	for (i = 0; i < n; i++)
	{
		printf("%s\t%d\t%lf\n", s[i].name, s[i].id, s[i].score);
	}

}

int main(void)
{
	Stu s[3];
	int n = 3;

	//�Ӽ�������ѧ����Ϣ
	initStu(s, n); 

	//aveStu(s, 3)��ƽ����
	printf("\nƽ����Ϊ�� %lf\n",  aveStu(s, n) );

	//�������򣬽���
	sortStu(s, n);

	//��ӡѧ����Ϣ
	showStu(s, n);
	
	printf("\n");
	system("pause");
	return 0;
}