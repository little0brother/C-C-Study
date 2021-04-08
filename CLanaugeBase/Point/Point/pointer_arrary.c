/************/
/* 指针数组 */
/***********/

#include <stdio.h>
#include <string.h>

// 指针数组

void short2long();

int main6()
{
	/***************************基本概念**************************************/
	int a[5] = { 1, 3, 4 ,5, 6 };
	int* name[5] = { &a[0], &a[1], &a[2], &a[3], &a[4] };

	for (int i = 0; i < 5; i++)
		printf("%d   ", *name[i]);
	printf("\n\n");
	/************************************************************************/

	short2long();

	return 0;
}

// eg：将字符串由小到大输出
void short2long()
{
	void sort(char* name[], int n);
	void print(char* name[], int n);

	char* str[] = {"www.HelloWorld.com", "Hello", "www.Hello.com", "www..com", "HelloWorld"};
	int n = 5;

	sort(str, n);
	print(str, n);
}

void sort(char* name[], int n)
{
	char* temp;
	int i, j, k;

	// 采用冒泡排序 (have promble!)
	for (i = 0; i < n; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(name[k], name[j]) > 0)
			{
				k = j;
			}
			if (k != i)
			{
				temp = name[i];
				name[i] = name[k];
				name[k] = temp;
			}
		}
	}
}

void print(char* name[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%s\n", name[i]);
}