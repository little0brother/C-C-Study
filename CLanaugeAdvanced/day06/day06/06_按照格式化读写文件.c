#include <stdio.h>
#include <string.h>

void my_fprintf(char* path)
{
	FILE* fp = NULL;
	fp = fopen(path, "w+");
	if (fp == NULL)
	{
		perror("my_fprintf fopen:");
		return;
	}

	//printf("i am a student today:%d", 100);
	//fprintf(stdout, "i am a student today:%d", 100);
	//fprintf(fp, "i am a student today:%d\n", 100);
	fprintf(fp, "%d %d %d %d", 1, 2, 3, 4);

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

void my_fscanf(char* path)
{
	FILE* fp = NULL;
	fp = fopen(path, "r+");
	if (fp == NULL)
	{
		perror("my_fscanf fopen:");
		return;
	}

	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	//fscanf(fp, "i am a student today:%d\n", &a);
	fscanf(fp, "%d %d %d %d", &a, &b, &c, &d);
	printf("my_fscanf a=%d b=%d c=%d d=%d\n", a, b, c, d);

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

int main()
{
	my_fprintf("../06.txt");
	my_fscanf("../06.txt");

	return 0;
}