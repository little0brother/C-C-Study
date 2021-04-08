/***************/
/* 数据块的读出 */
/***************/

/* 从键盘中输入数据，并将他们以二进制的形式存到磁盘中,并将文本中内容通过load函数显示出来 */

#include <stdio.h>

#define SIZE 4

struct stduent
{
	char name[10];
	int number;
	int age;
	char sex;
	char address[20];
} stu[SIZE], stu1[SIZE];

void save()
{
	FILE* fp;
	if (!(fp = fopen("test.txt", "wb+")))
	{
		printf("Can not open file!");
		exit(0);
	}

	for (int i = 0; i < SIZE; i++)
	{
		if (fwrite(&stu[i], sizeof(stu), 1, fp) != 1)
		{
			printf("file write error!");
			fclose(fp);
		}
	}
}

void load()
{
	FILE* fp;

	if (!(fp = fopen("test.txt", "r")))
	{
		printf("Can not open file!");
		exit(0);
	}

	for (int i = 0; i < SIZE; i++)
	{
//		if(!feof(fp))
//		{
			fread(&stu1[i], sizeof(stu1), 1, fp);
			printf("\n");
//		}
	}
	fclose(fp);
}

int main7()
{
	int i = 0;

	printf("Please input %d student name,number,age,sex,address: ", i+1);
	for (i = 0; i < SIZE; i++)
	{
		scanf("%s %d %d %c %s", stu[i].name, &stu[i].number, &stu[i].age, &stu[i].sex, stu[i].address);

		if (i < 3)
			printf("\nPlease input %d student name,number,age,sex,address: ", i + 1);
	}
	save();

	load();
	for (i = 0; i < SIZE; i++)
	{
		printf("%s %d %d %c %s\n", stu[i].name, stu[i].number, stu[i].age, stu[i].sex, stu[i].address);
	}
	
	return 0;
}