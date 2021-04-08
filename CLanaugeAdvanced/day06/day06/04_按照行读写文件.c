#include <stdio.h>

#if(1)

void my_fputs(char* path)
{
	FILE* fp = NULL;

	// "w+", 写读方式打开，如果文件不存在，则创建。 如果文件存在，清空内容，再写入
	fp = fopen(path, "w+");
	if (fp == NULL)
	{
		perror("my_fputs fopen");
		return;
	}

	// 写文件
	char* buf[] = {"aaaaaaa\n", "bbbbb\n", "cccc\n"};
	int n = sizeof(buf)/sizeof(buf[0]);
	for (int i = 0; i < n; i++)
	{
		int len = fputs(buf[i], fp);		// 返回值为，成功失败，成功为0，失败为非0
		//printf("len = %d\n", len);
	}

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

void my_fgets(char* path)
{
	FILE* fp = NULL;

	// 读写方式打开，如果文件不存在，打开失败
	fp = fopen(path, "r+");
	if (fp == NULL)
	{
		perror("my_fgets fopen");
	}

	char buf[100];
	// 方法二
	while (!feof(fp))		// 判断文件是否结束
	{
		// sizeof(buf),为最大能读多少字符，放不下只能放sizeof(buf)，如果不超过最大读取，则按照实际大小存放
		// 返回值，成功读取文件内容
		// 把'\n' 会读取，以'\n'作为换行的标识
		// fgets()读取完毕后，自动加字符串结束符
		char *p = fgets(buf, sizeof(buf), fp);
		// 因为读到的 \r \n 但是buf没有结束，所以while循环没有结束会进行多余的一次读操作
		if (p != NULL)
		{
			printf("buf = %s\n", buf);
			//printf("%s\n", p);
		}
	}
	printf("\n");

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

int main()
{
	my_fputs("../04.txt");
	my_fgets("../04.txt");

	return 0;
}
#endif