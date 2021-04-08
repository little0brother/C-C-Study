/************/
/* ָ������ */
/***********/

#include <stdio.h>
#include <string.h>

// ָ������

void short2long();

int main6()
{
	/***************************��������**************************************/
	int a[5] = { 1, 3, 4 ,5, 6 };
	int* name[5] = { &a[0], &a[1], &a[2], &a[3], &a[4] };

	for (int i = 0; i < 5; i++)
		printf("%d   ", *name[i]);
	printf("\n\n");
	/************************************************************************/

	short2long();

	return 0;
}

// eg�����ַ�����С�������
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

	// ����ð������ (have promble!)
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