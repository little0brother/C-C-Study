#include <stdio.h>
#include <string.h>

typedef struct Stu
{
	char name[50];
	int id;
}Stu;

void my_fwrite(char* path)
{
	FILE* fp = NULL;

	// 文件打开操作，如果文件不存在则创建
	fp = fopen(path, "w+");
	if (fp == NULL)
	{
		perror("my_fwrite fopen");
		return;
	}

	Stu s[3];
	char buf[50];
	for (int i = 0; i < 3; i++)
	{
		sprintf(buf, "stu%d%d", i, i);
		strcpy(s[i].name, buf);

		s[i].id = i + 10;
	}

	// 写文件, 按块方式写
	// 参数1：写入文件内容的内存首地址
	// 参数2：写入内容块数据的大小
	// 参数3：块数，写文件数据的大小 = 3 * sizeof(Stu)
	// 参数4：文件指针
	// 返回值：成功写入文件的块数目
	int ret = fwrite(s, sizeof(Stu), 3, fp);
	printf("[my_fread] ret = %d\n", ret);

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

void my_fread(char* path)
{
	FILE* fp = NULL;

	// 以读的方式打开文件，如果文件不存在则打靠失败
	fp = fopen(path, "r+");
	if (fp == NULL)
	{
		perror("my_fread fopen:");
	}

	Stu s[3];

	// 读文件, 按块方式写
	// 参数1：放文件内容的首地址
	// 参数2：读内容块数据的大小
	// 参数3：块数，读文件数据的大小 = 3 * sizeof(Stu)
	// 参数4：文件指针
	// 返回值：成功读取文件内容的块数目
	int ret = fread(s, sizeof(Stu), 3, fp);
	printf("[my_fread] ret = %d\n", ret);

	for (int i = 0; i < 3; i++)
	{
		printf("id=%d, name=%s\n", s[i].id, s[i].name);
	}

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

int main()
{
	my_fwrite("../05.txt");
	my_fread("../05.txt");

	return 0;
}