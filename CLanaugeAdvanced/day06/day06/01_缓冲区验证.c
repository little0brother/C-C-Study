#include <stdio.h>

/*
* 创建文件在编译完成后 
* 如果没有对文件进行 fclose()操作则不会正常生成，或者在关闭进程后会正常出现
*/

int main()
{
	char buf[] = "this is a test\n";

	FILE* fp = fopen("./test.txt", "w+");

	fputs(buf, fp);
	fflush(fp);		// 刷新缓冲区
	fclose(fp);

	printf("\n");
	return 0;
}