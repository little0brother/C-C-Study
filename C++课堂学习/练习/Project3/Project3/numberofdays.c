#include "max.h"

int numberofdays(struct date d) //在函数中定义类型为结构类型  传入值为结构类型中所有值
{
	int days;
	const int monthlastdays[12] = { 31, 28, 31, 30, 31, 30, 31, 31 ,30, 31, 30, 31 };

	if (d.month == 2 && isleap(d))
		days = 29;
	else
		days = monthlastdays[d.month - 1]; //因为数组下标从0开始 所以用月份-1 为当前月份天数

	return days;
}