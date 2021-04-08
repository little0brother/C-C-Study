#include <stdio.h>
#include <stdbool.h>
#include "max.h"

int main()
{
	struct date today, tomorrow;

	printf("输入年月日：xxxx年xx月xx日。\n");
	scanf_s("%i %i %i", &today.year, &today.month, &today.day);

	if (today.day != numberofdays(today)) {
		tomorrow.year = today.year;
		tomorrow.month = today.month;
		tomorrow.day = today.day + 1;
	}
	else if (today.month == 12) {
		tomorrow.year = today.year + 1;
		tomorrow.month = 1;
		tomorrow.day = 1;
	}
	else {
		tomorrow.year = today.year;
		tomorrow.month = today.month + 1;
		tomorrow.day = 1;
	}

	printf("%i年%i月%i日\n", tomorrow.year, tomorrow.month, tomorrow.day);

	system("pause");
	return 0;
}

bool isleap(struct date d)
{
	bool leap = false;

	if (d.year % 4 == 0 && d.year % 100 != 0 || d.year % 400 == 0)
		leap = true;

	return leap;
}