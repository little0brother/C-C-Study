#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  SIZE 1024 * 2 //每次读写2k数据

void menu()
{
	printf("================================\n");
	printf("1 拷贝文件\n");
	printf("2 清屏\n");
	printf("3 退出\n");
	printf("================================\n");
}

void myCopy()
{
	char rPath[256]; //源文件
	char wPath[256]; //目的文件
	FILE *rFp = NULL;
	FILE *wFp = NULL;
	char buf[SIZE] = { 0 }; 
	int n = 0;

	printf("请输入源文件：");
	scanf("%s", rPath);

	printf("请输入目的文件：");
	scanf("%s", wPath);

	if (strcmp(rPath, wPath) == 0)
	{
		printf("源文件和目的文件不能相同\n");
		return;
	}

	//只读方式打开源文件
	rFp = fopen(rPath, "rb");
	if (rFp == NULL)
	{
		perror("fopen rPath");
		return;
	}

	//只写方式打开目的文件
	wFp = fopen(wPath, "wb");
	if (wFp == NULL)
	{
		fclose(rFp);
		perror("fopen wFp");
		return;
	}

	do 
	{
		n = 0;
		//读多少，写多少
		n = fread(buf, sizeof(char), SIZE, rFp);
		printf("拷贝：%d\n", n);
		fwrite(buf, sizeof(char), n, wFp);

	} while (n > 0);
	printf("拷贝完成\n\n");

	fclose(rFp);
	fclose(wFp);
}

int main()
{
	

	int cmd;

	while (1)
	{
		menu();
		printf("cmd: ");
		scanf("%d", &cmd);

		switch (cmd)
		{
		case 1:
			myCopy();
			break;
		case 2:
			system("cls");
			break;
		default:
			exit(0);
		}
	}

	printf("\n");
	system("pause");
	return 0;
}