#include <stdio.h>

int main()
{
	FILE* fp = NULL;

	// 下面两个等级
	// F:\\ProgramLanguage\\CLanguage\\CLanaugeAdvanced\\day06\\day06\\03.txt  (只针对与windows)
	// F:/ProgramLanguage/CLanguage/CLanaugeAdvanced/day06/day06/03.txt  (针对与windows和linux)

	// "F:\\ProgramLanguage" windows的写法
	// "F:/ProgramLanguage"  linux,windows都支持，建议写法

	// 绝对路径：F:\\ProgramLanguage\\CLanguage\\CLanaugeAdvanced\\day06\\day06\\03.txt
	// 相对路径：'/' 45度， ./, ../（建议使用）
	// vs:编译代码时，相对与项目工程(当前代码)
	// 直接运行可执行程序，相对于程序(可执行程序所在的文件夹中如果没有所需文件就会出现错误)
	fp = fopen("./03.txt", "r+");
	if (fp == NULL)
	{
		perror("fopen");
		system("pause");
		return -1;
	}

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}

	return 0;
}