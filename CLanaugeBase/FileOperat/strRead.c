/*************/
/* ×Ö·û´®¶Á³ö */
/*************/

#include <stdio.h>

#define LEN 11

int main5()
{
	FILE* fp;
	char buf[LEN];

	if (!(fp = fopen("test.txt", "rt")))
	{
		printf("can not open file !");
		exit(0);
	}

	fgets(buf, LEN, fp);
	printf("%s\n", buf);

	fclose(fp);

	return 0;
}