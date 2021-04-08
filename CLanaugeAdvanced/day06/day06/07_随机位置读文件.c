#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stu
{
	char name[50];
	int id;
}Stu;

#if(0)
// 作用：将文件指针移动到指定位置
// 参数1：stream，文件指针
// 参数2：offset，相对于指针位置的偏移量 （正数指针向右移动，负数指针向左移动）
// 参数3：SEEK_SET 从文件开头移动offset个字节；SEEK_CUR从当前位置移动offset个字节；SEEK_END从文件末尾移动offset个字节
// 返回值:成功返回0,出错返回-1并设置errno 
int fseek(FILE* stream, long offset, int whence);

// 作用：计算文件头到文件指针的位置（可以计算长度，将文件指针通过fseek()函数将指针移动到文件尾）
// 返回值:成功返回当前读写位置,出错返回-1并设置errno 
long ftell(FILE* stream);

// 将文件指针移动至文件头
void rewind(FILE* stream);
#endif

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
		sprintf(buf, "stu%d%d%d", i, i, i);
		strcpy(s[i].name, buf);

		s[i].id = i + 1;
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
		return;
	}

	Stu s[3];
	Stu tmp;	// 读第三个结构体

	// 
	fseek(fp, 2 * sizeof(Stu), SEEK_SET);	
	//fseek(fp, (-1) * (int)(sizeof(Stu)), SEEK_END);

	int ret = fread(&tmp, sizeof(Stu), 1, fp);
	if (ret == 1)
	{
		printf("[tmp]%s, %d\n", tmp.name, tmp.id);
	}

	// 把指针光标移动到最开始的地方
	//fseek(fp, 0, SEEK_SET);
	rewind(fp);

	// 读文件, 按块方式写
	// 参数1：放文件内容的首地址
	// 参数2：读内容块数据的大小
	// 参数3：块数，读文件数据的大小 = 3 * sizeof(Stu)
	// 参数4：文件指针
	// 返回值：成功读取文件内容的块数目
	ret = fread(s, sizeof(Stu), 3, fp);
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
	my_fwrite("../07.txt");
	my_fread("../07.txt");

	return 0;
}