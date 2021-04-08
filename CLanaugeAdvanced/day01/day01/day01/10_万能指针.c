#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	void* p;
	// 万能指针在指向其它类型的变量是，在使用时要进行类型转换

	char buf[100] = "abcdefghijkl";
	p = buf;
	printf("p = %s\n", (char*)p);

	int a[100] = { 1, 2, 3, 4 };
	p = a;
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", *((int*)p + i));
	}
	printf("\n");

	
	// 对于memcpy以及strcpy()函数的验证
	int b[3] = { 1, 2, 3 };
	int c[3];
	memcpy(c, b, sizeof(b));
	for (int i = 0; i < 3; i++)
	{
		printf("%d ", c[i]);
	}
	printf("\n");

	char str[] = "fdafaffa";
	char dst[100];
	memcpy(dst, str, sizeof(str));
	printf("dst = %s\n", dst);

	char* q = NULL;
	char str2[100] = { 0 };
	q = str2;
	strcpy(q, "1234");
	printf("q = %s\n", q);
	printf("str2 = %s\n", str2);


	printf("\n");
	return 0;
}
