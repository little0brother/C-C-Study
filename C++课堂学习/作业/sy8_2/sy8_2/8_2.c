#include <stdio.h>
#include <string.h>
#define NUM 4

struct student {
	int rank;
	char name[6];
	float socre;
} stu[] = { {3, "Tom", 89.3},
			{4, "Marry", 78.2},
			{1,"Jack", 95.1},
			{2, "Jim", 90.6}
          };

int main()
{
	char str[10];
	int i;

	do {
		printf("Enter name:");
		gets(str);
		
		for(i = 0; i < NUM; i++)
			if (strcmp(str, stu[i].name) == 0) {
				printf("name:%5s\n", stu[i].name);
				printf("rank:%d\n", stu[i].rank);
				printf("average:%5.lf\n", stu[i].socre);
				break;
			}
		if (i > NUM)
			printf("Not found\n");
	} while (strcmp(str,"0") != 0);

	system("pause");
	return 0;
}