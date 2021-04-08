/*
* 	从键盘输入3个学生的信息（姓名、学号、成绩），存入一个结构体数组中，计算平均分，并按成绩
	高低排序并输出
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

		//从键盘输入学生信息
		initStu(s, n); 

		//aveStu(s, 3)：平均分
		printf("\n平均分为： %lf\n",  aveStu(s, n) );

		//分数排序，降序
		sortStu(s, n);

		//打印学生信息
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
		printf("输入第%d个学生的姓名、学号、课程成绩:", i + 1);
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

	//从键盘输入学生信息
	initStu(s, n);

	//aveStu(s, 3);	// 平均分
	printf("\n平均分为： %lf\n", aveStu(s, n));

	//分数排序，降序
	sortStu(s, n);

	//打印学生信息
	showStu(s, n);

	return 0;
}