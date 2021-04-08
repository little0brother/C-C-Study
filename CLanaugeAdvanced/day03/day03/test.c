#include <stdio.h>

#define INLIMITPRICE 3.7
#define INLIMIT 3.5 

int main(void)
{
	int peoplenum = 0;
	float usewater = 0;
	float waterlimit = 3.5;
	float outdolimit;
	float waterprice = 0;

	printf("输入家庭总人数：");
	scanf("%d", &peoplenum);
	printf("输入总用水量：");
	scanf("%f", &usewater);

	if ((usewater / peoplenum) > waterlimit)
	{
		outdolimit = ((usewater / peoplenum) - waterlimit) / waterlimit;

		if (outdolimit <= 0.2)
		{
			waterprice = waterlimit * peoplenum * INLIMITPRICE + outdolimit * waterlimit * peoplenum * (INLIMITPRICE * 2);
		}
		else if (outdolimit > 0.2 && outdolimit <= 0.4)
		{
			waterprice = waterlimit * peoplenum * INLIMITPRICE + outdolimit * waterlimit * peoplenum * (INLIMITPRICE * 3);
		}
		else
		{
			waterprice = waterlimit * peoplenum * INLIMITPRICE + outdolimit * waterlimit * peoplenum * (INLIMITPRICE * 4);
		}
	}
	else
	{
		waterprice = usewater * INLIMITPRICE;
	}

	printf("需缴纳水费：%f", waterprice);

	return 0;
}