#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct STUDENT
{
	char    serial[12];
	char    name[8];
	float   score;
};

int main()
{
	struct STUDENT stu1, stu2;

	strcpy(stu1.serial, "17011101");
	strcpy([ͼƬ]stu1.name, "jack");
	stu1.score = 80.f;
	stu2 = stu1;//<==>strcpy(stu2.serial,stu1.serial);
				//strcpy([ͼƬ]stu2.name,[ͼƬ]stu1.name);
				//stu2.score=stu1.score;

	printf("%s,%s%.1f\n", stu2.serial, [ͼƬ]stu2.name, stu2.score);

	system("pause");
	return 0;
}