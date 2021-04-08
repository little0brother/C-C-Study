#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itcastlog.h"

int main(void)
{
	printf("file = %s\nline = %d\n", __FILE__, __LINE__);

	int a = 10;
	ITCAST_LOG(__FILE__, __LINE__, 4, -2, "a = %d\n", a);



	printf("\n");
	system("pause");
	return 0;
}