/************/
/*  文件写入 */
/************/

#include <stdio.h>
#include <stdlib.h>

int main2()
{
	FILE* fp;
	char ch, filename[20];

	printf("Please input the filename you want to write: ");
	scanf("%s", filename);

	if (!(fp = fopen("filename", "wt+")))
	{
		printf("Can not open file\n");
		exit(0);
	}

	printf("Please input the sentences you want to write: ");
	ch = getchar(); // 单字符输入scanf会读取空白字符,'\r\n' 等字符 不会跳过，所以对输入1个数再回车实际就是读入到流中是2个字符getchar()一次是一个字符 也就要读2次才能匹配
	ch = getchar();
	while (ch != EOF) // EOF = ctrl+z
	{
		fputc(ch, fp);

		ch = getchar();
	}
	fclose(fp);

	return 0;
}