/**************************************************************/
/*                     �Ժ�ѡ�˵�Ʊ��ͳ�Ƴ���                  */
/* ����������ѡ�ˣ�ÿ������һ����Ʊ��ѡ�˵���������������Ʊ��� */
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
	struct tickcount people[5] = { {"�ܽ���", 0}, {"����γ", 0}, {"������", 0}, {"����ٻ", 0}, {"����Ѹ", 0} };
	char vote[20], minname[20], maxname[20];
	int count = 1, max, min;

	printf("/**************************************************/\n");
	printf("/**��ѡ���������ܽ��� ����γ ������ ����ٻ ����Ѹ**/\n");
	printf("/*****************����quit����ͶƱ*****************/ \n\n");
	printf("��ʼ��%d��ͶƱ��", count);
	
	// ѭ��ͶƱ����Ʊ
	while (strcmp(gets(vote), "quit"))
	{		
		// ��ṹ����������һ���Ƚ�
		for(int i = 0; i < 5; i++)
			if (strcmp(vote, people[i].name1) == 0)
			{
				people[i].ticksum += 1;
				break;
			}

		count += 1;
		printf("��ʼ��%d��ͶƱ��", count);
	}

	// ����¼Ʊ������������߸���ֵ
	max = min = people[0].ticksum;
	strcpy(maxname, people[0].name1);

	// ��ӡͳ������������Ʊ�������
	for (int i = 0; i < 5; i++)
	{
		printf("\n%s: %dƱ\n", people[i].name1, people[i].ticksum);
		
		// ɸѡƱ�������������
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

	printf("\nƱ�������Ϊ:%s\n", maxname);

	return 0;
}