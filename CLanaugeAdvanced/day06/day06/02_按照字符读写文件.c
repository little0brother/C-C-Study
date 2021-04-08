#include <stdio.h>

#if(0)
int main()
{
	fputc('a', stdout);		// stdout -> 屏幕(打印普通信息）

	char ch;
	ch = fgetc(stdin);		// stdin -> 键盘
	printf("ch = %c\n", ch);

	//fprintf(stderr, "%c", ch);		// stderr -> 屏幕（打印错误信息）
	fputc(ch, stdout);

	return 0;
}
#endif

#if(1)

void my_fputc(char* path)
{
	FILE* fp = NULL;

	// "w+", 写读方式打开，如果文件不存在，则创建。 如果文件存在，清空内容，再写入
	fp = fopen(path, "w+");
	if (fp == NULL)
	{
		perror("my_fputc fopen");
		return;
	}

	// 写文件
	char buf[] = "this is a test for fputc";
	int n = strlen(buf);
	for (int i = 0; i < n; i++)
	{
		fputc(buf[i], fp);		// 返回值为，成功写入的字符
	}

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

void my_fgetc(char* path)
{
	FILE* fp = NULL;

	// 读写方式打开，如果文件不存在，打开失败
	fp = fopen(path, "r+");
	if (fp == NULL)
	{
		perror("my_fgetc fopen");
	}

	char ch;
#if 0
	// 方法一
	while ((ch = fgetc(fp)) != EOF)		// fgetc的返回值为 获取到的字符
	{
		printf("%c", ch);
	}
	printf("\n");
#endif
#if 1
	// 方法二
	while ( !feof(fp) )		// 判断文件是否结束
	{
		ch = fgetc(fp);
		printf("%c", ch);
	}
	printf("\n");
#endif

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

int main()
{
	//my_fputc("../03.txt");
	my_fgetc("../03.txt");

	return 0;
}
#endif