/***************/
/* 文件随机读写 */
/***************/

/* 读出test.txt文件中的第二个学生数据 */

#include <stdio.h>

#define SIZE 4

struct stduent
{
	char name[10];
	int number;
	int age;
	char sex;
	char address[20];
} stu;

int main8()
{
	FILE* fp;
	int i = 1;	// 用于定位第 i 个结构
	if (!(fp = fopen("test.txt", "rb")))
	{
		printf("Can not open file!");
		exit(0);
	}

	rewind(fp);
	fseek(fp, i * sizeof(stu), 0);
	fread(&stu, sizeof(stu), 1, fp);

	printf("%s %d %d %c %s\n", stu.name, stu.number, stu.age, stu.sex, stu.address);
}
