#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memwatch.h"

int main(void)
{
	char *p = malloc(100);

	free(p);

	printf("\n");
	system("pause");
	return 0;
}