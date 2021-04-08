#include <stdio.h>

// argc: 传参的个数（包括可执行程序）
// argv: 指针数组，指向输入的参数
int main(int argc, char *argv[])
{
	// 数组指针，指针数组

	// 指针数组，它是数组，每个元素都是指针
	// [] 比 * 优先级高
	char* a[] = { "aaaaaa", "bbbbbb", "cccccc" };

	printf("argc = %d\n", argc);
	for (int i = 0; i < argc; i++)
	{
		printf("argv = %s\n", argv[i]);
	}

	printf("\n");
	return 0;
}