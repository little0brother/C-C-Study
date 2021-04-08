#include <stdio.h>

#define D1
#define TEST 0

int main()
{

#ifndef D1
	printf("D1111111\n");
#else
	printf("others\n");
#endif


#if TEST
	printf("1111111\n");
#else
	printf("2222222\n");
#endif


#if 0

#endif // 0


	return 0;
}