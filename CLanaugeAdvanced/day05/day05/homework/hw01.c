/*
* 	�Ӽ�������3��ѧ������Ϣ��������ѧ�š��ɼ���������һ���ṹ�������У�����ƽ���֣������ɼ�
	�ߵ��������
	typedef struct Stu
	{
		char name[50];
		int id;
		double score;
	}Stu;
	
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

		return 0;
	}
*/

#include <stdio.h>

typedef struct Stu
{
	char name[50];
	int id;
	double score;
}Stu;

void initStu(Stu* s, int n)
{
	if (s == NULL)
	{
		return;
	}

	for (int i = 0; i < n; i++)
	{
		printf("�����%d��ѧ����������ѧ�š��γ̳ɼ�:", i + 1);
		scanf("%s %d %lf", s[i].name, &s[i].id, &s[i].score);
	}
}

double aveStu(Stu* s, int n)
{
	double avg = 0;

	for (int i = 0; i < n; i++)
	{
		avg += s[i].score;
	}
	avg /= (n * 1.0);

	return avg;
}

void sortStu(Stu* s, int n)
{
	Stu tmp;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (s[i].score < s[j].score)
			{
				tmp = s[i];
				s[i] = s[j];
				s[j] = tmp;
			}
		}
	}
}

void showStu(Stu* s, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\n%s %d %lf\n", s[i].name, s[i].id, s[i].score);
	}
}

int main()
{
	Stu s[3];
	int n = 3;

	//�Ӽ�������ѧ����Ϣ
	initStu(s, n);

	//aveStu(s, 3);	// ƽ����
	printf("\nƽ����Ϊ�� %lf\n", aveStu(s, n));

	//�������򣬽���
	sortStu(s, n);

	//��ӡѧ����Ϣ
	showStu(s, n);

	return 0;
}