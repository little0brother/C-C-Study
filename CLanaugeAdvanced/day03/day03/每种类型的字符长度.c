#include <stdio.h>

int main()
{
	char* p1[] = { "1111", "2222", "3333" };
	printf("sizeof(p1):%d, sizeof(p1[0]:%d\n", sizeof(p1), sizeof(p1[0]));
	printf("%d\n", sizeof(p1) / sizeof(p1[0]));	// 1

	char* p2[10] = { "1111", "2222", "3333" };
	printf("sizeof(p2):%d, sizeof(p2[0]:%d\n", sizeof(p2), sizeof(p2[0]));
	printf("%d\n", sizeof(p2) / sizeof(p2[0]));	// 2

	char p3[][30] = { "1111", "2222", "3333" };
	printf("sizeof(p3):%d, sizeof(p3[0]:%d\n", sizeof(p3), sizeof(p3[0]));
	printf("%d\n", sizeof(p3) / sizeof(p3[0]));	// 3

	char p4[10][30] = { "1111", "2222", "3333" };
	printf("sizeof(p4):%d, sizeof(p4[0]:%d\n", sizeof(p4), sizeof(p4[0]));
	printf("%d\n", sizeof(p4) / sizeof(p4[0]));	// 0

	printf("\n");
	return 0;
}