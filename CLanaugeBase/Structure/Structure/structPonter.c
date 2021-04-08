/***********/
/* 数组指针 */
/***********/

#include <stdio.h>

struct stu
{
	int num;
	char* name;
	char sex;
	float score;
} boy1 = {102, "hello", 'M', 78.5};

// 三种调用形式
int main3()
{
	struct stu* pstu;
	pstu = &boy1;

	printf("Number = %d\nName = %s\n", boy1.num, boy1.name);
	printf("Sex = %c\nScore = %f\n\n", boy1.sex, boy1.score);

	printf("Number = %d\nName = %s\n", pstu->num, pstu->name);
	printf("Sex = %c\nScore = %f\n\n", pstu->sex, pstu->score);

	printf("Number = %d\nName = %s\n", (*pstu).num, (*pstu).name);
	printf("Sex = %c\nScore = %f\n\n", (*pstu).sex, (*pstu).score);

	return 0;
}