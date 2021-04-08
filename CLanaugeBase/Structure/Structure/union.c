/**********/
/* 共用体 */
/**********/

#include <stdio.h>

struct
{
	int num;//成员编号
	char name[20];//成员姓名
	char sex;//成员性别
	char job;//成员职业
	union    //声明无名的共用体类型
	{
		int clas;//成员班级
		char position[10];//成员职务
	}category;
}person[2]; // 一个老师一个学生

int main6()
{
	int i = 0;
	for (i = 0; i < 2; i++)
	{
		printf("请输入第 %d 个成员的各项信息（编号、姓名、性别和职业）：\n", i + 1);
		scanf("%d %s %c %c", &person[i].num, person[i].name, &person[i].sex, &person[i].job);
		if ((person[i].job) == 's')
		{
			printf("输入班级号：\n");
			scanf("%d", &person[i].category.clas);
		}
		else if ((person[i].job) == 't')
		{
			printf("输入职务：\n");
			scanf("%s", &person[i].category.position);
		}
		else
			printf("输入信息有误！\n");
	}
	printf("输出以上信息：\n");
	printf("NO.   name    sex    job  class/position\n");
	for (i = 0; i < 2; i++)
	{
		if ((person[i].job) == 's')
			printf("%-6d%-10s%-7c%-7c%-10d\n", person[i].num, person[i].name, person[i].sex, person[i].job, person[i].category.clas);
		else
			printf("%-6d%-10s%-7c%-7c%-10s\n", person[i].num, person[i].name, person[i].sex, person[i].job, person[i].category.position);
	}
	return 0;
}