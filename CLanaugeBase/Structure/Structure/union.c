/**********/
/* ������ */
/**********/

#include <stdio.h>

struct
{
	int num;//��Ա���
	char name[20];//��Ա����
	char sex;//��Ա�Ա�
	char job;//��Աְҵ
	union    //���������Ĺ���������
	{
		int clas;//��Ա�༶
		char position[10];//��Աְ��
	}category;
}person[2]; // һ����ʦһ��ѧ��

int main6()
{
	int i = 0;
	for (i = 0; i < 2; i++)
	{
		printf("������� %d ����Ա�ĸ�����Ϣ����š��������Ա��ְҵ����\n", i + 1);
		scanf("%d %s %c %c", &person[i].num, person[i].name, &person[i].sex, &person[i].job);
		if ((person[i].job) == 's')
		{
			printf("����༶�ţ�\n");
			scanf("%d", &person[i].category.clas);
		}
		else if ((person[i].job) == 't')
		{
			printf("����ְ��\n");
			scanf("%s", &person[i].category.position);
		}
		else
			printf("������Ϣ����\n");
	}
	printf("���������Ϣ��\n");
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