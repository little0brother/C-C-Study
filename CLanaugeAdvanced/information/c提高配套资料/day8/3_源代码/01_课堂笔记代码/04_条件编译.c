#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  D1
#define  TEST 0

int main(void)
{
#ifndef D1
	printf("D1111111111111111111\n");
#else
	printf("others\n");
#endif

#if TEST
	printf("1111111111111\n");
#else
	printf("2222222222222222");
#endif

#if 1

#endif


	

	printf("\n");
	system("pause");
	return 0;
}