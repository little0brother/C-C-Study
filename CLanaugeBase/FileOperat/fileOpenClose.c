/*******************/
/* 文件打开关闭函数 */
/******************/

#include <stdio.h>
#include <stdlib.h>

int main1()
{
	FILE* fp;
	if (!(fp = fopen("F:\\ProgramLanguage\\CLanguage\\CLanaugeBase\\FileOperat\\test.txt", "rb"))) 
	// 如果文件打开失败，则返回NULL
	{
		printf("Can not open FILE!\n");
		system("pause");
	}
	else 
	{
		printf("Open success!\n");
	}

	fclose(fp); // 关闭文件

	return 0;
}