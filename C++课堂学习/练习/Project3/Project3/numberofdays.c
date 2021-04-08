#include "max.h"

int numberofdays(struct date d) //�ں����ж�������Ϊ�ṹ����  ����ֵΪ�ṹ����������ֵ
{
	int days;
	const int monthlastdays[12] = { 31, 28, 31, 30, 31, 30, 31, 31 ,30, 31, 30, 31 };

	if (d.month == 2 && isleap(d))
		days = 29;
	else
		days = monthlastdays[d.month - 1]; //��Ϊ�����±��0��ʼ �������·�-1 Ϊ��ǰ�·�����

	return days;
}