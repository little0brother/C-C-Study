#include <stdio.h>
#include <stdlib.h>

#define SIZE 2*1024	// 每次拷贝2k数据

void meau()
{
	printf("=========================\n");
	printf("1.copy文件\n");
	printf("2.清屏\n");
	printf("3.退出\n");
	printf("=========================\n");
}

void copyFile()
{
	char rpath[512] = { 0 };
	char wpath[512] = { 0 };

	printf("请输入需copy的文件名:");
	scanf("%s", rpath);
	
	printf("请输入copy后的文件名:");
	scanf("%s", wpath);

	if (*rpath == *wpath)
	{
		printf("文件名不能相同!\n");
		return;
	}

	FILE* rfp = NULL;
	FILE* wfp = NULL;

	rfp = fopen(rpath, "rb");
	if (rfp == NULL)
	{
		perror("rfp fopen");
		return;
	}

	wfp = fopen(wpath, "wb");
	if (wfp == NULL)
	{
		perror("wfp fopen");
		return;
	}

	int n = 0;
	char buf[SIZE] = { 0 };

	// 读多少写多少
	// 每次拷贝2k数据，
	do
	{
		n = 0;

		// 一个字节一个字节读，每次读2k
		// 读多少写多少
		n = fread(buf, sizeof(char), SIZE, rfp);
		if (n > 0)
		{
			fwrite(buf, sizeof(char), n, wfp);
		}
		printf("拷贝:%d\n", n);
	} while (n > 0);
	printf("拷贝完成");

	if (rfp != NULL)
	{
		fclose(rfp);
		rfp = NULL;
	}
	if (wfp != NULL)
	{
		fclose(wfp);
		wfp = NULL;
	}
}

int main()
{
	int cmd;

	while (1)
	{
		meau();
		printf("cmd:");
		scanf("%d", &cmd);

		switch (cmd)
		{
		case 1: copyFile(); break;
		case 2: system("cls"); break;
		case 3: exit(0);
		default:
			break;
		}
	}

	return 0;
}