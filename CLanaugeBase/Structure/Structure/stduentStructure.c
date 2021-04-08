/*****************/
/* 学生结构体嵌套 */
/*****************/

#include <stdio.h>

struct date
{
	int moth;
	int day;
	int year;
} birthday;

struct student
{
	int num;
	char name[20];
	char sex;
	struct date birthday;
	float score;
} boy1, boy2;

int main1()
{
	struct student boy3[2] = { {1, "wang", 'n', 1999, 3, 2, 90}, {2, "wang", 'n', 1999, 3, 2, 90} }; // 初始化方法

	printf("Please input birthday(YY:) ");
	scanf("%d", &boy1.birthday.year);
	printf("Pleasr input birthday(MM:) ");
	scanf("%d", &boy1.birthday.moth);
	printf("Pleasr input birthday(DD:) ");
	scanf("%d", &boy1.birthday.day);
	printf("\n");
	/**/
	/**/

	boy2 = boy1;

	printf("%d-%d-%d\n", boy1.birthday.year, boy1.birthday.moth, boy1.birthday.day);
	printf("%d-%d-%d\n", boy2.birthday.year, boy2.birthday.moth, boy2.birthday.day);

	return 0;
}