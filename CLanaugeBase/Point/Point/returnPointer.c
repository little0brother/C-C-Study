/*******************/
/* 返回指针值的函数 */
/*******************/

#include <stdio.h>

int stdunentNumber = 5;
int scoreNumber = 4;
int lessSixNumber;

int main5()
{
	// 函数声明，定义数组指针 *pointer为指向传入数组,4为二维数组长度
	double* search(double(*pointer)[4], int n);
	int* searchLessSix(double(*pointer)[4], int* mem);
	int searchLessSix2(double(*pointer)[4], int i);

	double score[][4] = { {30, 39, 40, 21}, {12, 11, 44, 65}, {77, 66, 65,76}, {90, 89, 89, 44}, {100, 89, 90, 80} };
	double* p;
	int* p2, mem[100];
	int i, member;

	printf("Please enter the number of student:");
	scanf("%d", &member);

	// 根据输入序号，检索学生成绩
	printf("The scores of No.%d are: ", member);
	p = search(score, member - 1);
	for (i = 0; i < scoreNumber; i++)
		printf("%3.1f\t", *(p + i));

	// 检索不及格学生序号
	printf("\nLess than 60 stduent number: ");
	p2 = searchLessSix(score, mem) - lessSixNumber;
	for (i = 0; i < lessSixNumber; i++)
		printf("%2d, ", *(p2 + i) + 1);

	// 检索不及格学生序号 省略全局变量方法
	int flag1;
	for (i = 0; i <= stdunentNumber; i++)
	{
		flag1 = searchLessSix2(score, i);
		if (flag1 == 1)
			printf("%d ", i);
	}

	return 0;
}

double* search(double(*pointer)[4], int n)
{
	return pointer += n;
}

int* searchLessSix(double(*pointer)[4], int* mem)
{
	int i, j;
	for (i = 0; i < stdunentNumber; i++)
	{
		for (j = 0; j < scoreNumber; j++)
		{
			if (pointer[i][j] < 60)
			{
				*mem++ = i;
				lessSixNumber += 1;
				break;
			}
		}
	}

	return mem;
}

int searchLessSix2(double(*pointer)[4], int i)
{
	int j;
		for (j = 0; j < scoreNumber; j++)
		{
			if (pointer[i][j] < 60)
				return 1;
			else
				return 0;
		}
}