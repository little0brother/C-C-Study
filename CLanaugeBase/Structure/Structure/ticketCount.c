/**************************************************************/
/*                     对候选人得票的统计程序                  */
/* 设有三个候选人，每次输入一个得票候选人的姓名，最后输出得票结果 */
/************************************************************/

#include <stdio.h>
#include <string.h>

struct tickcount
{
	char name1[20];
	int ticksum;
};

int main2()
{
	struct tickcount people[5] = { {"周杰伦", 0}, {"杨宗纬", 0}, {"华晨宇", 0}, {"龚美倩", 0}, {"陈奕迅", 0} };
	char vote[20], minname[20], maxname[20];
	int count = 1, max, min;

	printf("/**************************************************/\n");
	printf("/**候选人名单：周杰伦 杨宗纬 华晨宇 龚美倩 陈奕迅**/\n");
	printf("/*****************输入quit结束投票*****************/ \n\n");
	printf("开始第%d次投票：", count);
	
	// 循环投票、记票
	while (strcmp(gets(vote), "quit"))
	{		
		// 与结构体中姓名逐一做比较
		for(int i = 0; i < 5; i++)
			if (strcmp(vote, people[i].name1) == 0)
			{
				people[i].ticksum += 1;
				break;
			}

		count += 1;
		printf("开始第%d次投票：", count);
	}

	// 给记录票数最多者最少者赋初值
	max = min = people[0].ticksum;
	strcpy(maxname, people[0].name1);

	// 打印统计情况，并输出票数最高者
	for (int i = 0; i < 5; i++)
	{
		printf("\n%s: %d票\n", people[i].name1, people[i].ticksum);
		
		// 筛选票数最多与最少者
		if (people[i].ticksum <= min)
		{
			min = people[i].ticksum;
			strcpy(minname, people[i].name1);
		}
		else if (people[i].ticksum >= max)
		{
			max = people[i].ticksum;
			strcpy(maxname, people[i].name1);
		}
	}

	printf("\n票数最多者为:%s\n", maxname);

	return 0;
}