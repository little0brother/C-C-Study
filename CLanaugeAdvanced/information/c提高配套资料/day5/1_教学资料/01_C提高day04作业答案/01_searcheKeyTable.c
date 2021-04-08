#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM(a) (sizeof(a)/sizeof(*a))

int searcheKeyTable(const char* table[], const int size,
	const char* key, int *pos)
{
	if (table == NULL || key == NULL || pos == NULL)
	{
		return -1;
	}

	int i = 0;
	int tmp = -1;
	for (i = 0; i < size; i++)
	{
		if (strcmp(table[i], key) == 0)
		{
			tmp = i;
			break;
		}
	}

	if (tmp != -1)
	{
		*pos = tmp + 1;
	}
	else
	{
		return -2;
	}

	return 0;
}

int main()
{
	//ָ������
	//�������飬ÿ��Ԫ�ض���ָ��
	char* keywords[] = {
		"while",
		"case",
		"static",
		"do"
	};

	//��Ԫ�ظ���
	//#define NUM(a) (sizeof(a)/sizeof(*a))
	//int n = sizeof(keywords) / sizeof(*keywords);
	//n = NUM(keywords)
	//n = sizeof(keywords) / sizeof(*keywords)
	int pos = 0;
	int ret = searcheKeyTable(keywords, NUM(keywords), "while", &pos);
	if (ret != 0)
	{
		return ret;
	}

	printf("pos == %d\n", pos);


	printf("\n");
	system("pause");
	return 0;
}