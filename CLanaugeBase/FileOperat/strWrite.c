/*************/
/* 字符串写入 */
/*************/

#include <stdio.h>

#define LEN 10

int main6()
{
	FILE* fp;
	char buf[LEN], ch;

	if (!(fp = fopen("test.txt", "at+")))
	{
		printf("can not open file !");
		exit(0);
	}

	printf("Please input string to file: ");
	fgets(buf, LEN, stdin);			// 不用scanf是因为 %s读入字符串时 遇到空格、换行回车会停止读入
									// stdin 为键盘输入缓冲区
	fputs(buf, fp);

	rewind(fp);  // 将文件指针重新指回至文件开头处

	ch = fgetc(fp);
	while (ch != EOF)
	{
		putchar(ch);
		ch = fgetc(fp);
	}

	fclose(fp);

	return 0;
}