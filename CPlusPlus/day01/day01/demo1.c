/**
* 传智播客推出了一款课程，并进行了一次促销活动。具体来说就是，
课程的初始定价为 vv 元；每报名 mm 个学员，课程的定价就要提升 aa 元。由于课程能够容纳的学生有限，因此报名到 nn 人的时候就停止报名。

现在老师想知道，当课程停止报名时，一共可以获得多少学费呢？
*/

#include <stdio.h>

int main()
{
	int n=0, v=0, m=0, a=0;
	int sum = 0;
	int count = 0;

	scanf("%d %d %d %d", n, v, m, a);

	printf("%d %d %d %d", n, v, m, a);

	while (count < n)
	{
		sum += v;
		printf("%d", sum);
		
		count++;
		v += a;
	}

	printf("%d", sum);

	return 0;
}