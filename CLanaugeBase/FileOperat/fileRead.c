/************/
/* ÎÄ¼þ¶Á³ö */
/************/

#include <stdio.h>

int main3()
{
	FILE* fp;
	char ch, filename[20];

	printf("Please input the filename you want to write: ");
	scanf("%s", filename);

	if (!(fp = fopen("filename", "r")))
	{
		printf("Can not open file\n");
		exit(0);
	}

	ch = '\0';
	while (ch != EOF)
	{
		ch = fgetc(fp);
		putchar(ch);
	}

	fclose(fp);

	return 0;
}