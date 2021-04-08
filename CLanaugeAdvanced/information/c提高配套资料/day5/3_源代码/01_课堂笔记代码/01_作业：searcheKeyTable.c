#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM(a) (sizeof(a)/sizeof(*a))


/*
���ܣ��ҵ�������ָ���ַ�����λ��
������
table���ַ������飨ָ�����飩�׵�ַ
size������Ԫ�ظ���
key��ƥ���ַ�������"do"
pos: ƥ���ַ����������е�λ�ã����"do"��keywords[]��λ��Ϊ4
����ֵ��
�ɹ���0
ʧ�ܣ���0
*/
int searcheKeyTable(const char* table[], const int size,
	const char* key, int *pos)
{
	if (table == NULL || key == NULL || pos == NULL)
	{
		return -1;
	}

	int i = 0;
	int n = -1;

	for (i = 0; i < size; i++)
	{
		if (strcmp(table[i], key) == 0)
		{
			n = i;
			break;
		}
	}

	if (n == -1) //û��ƥ���ַ���
	{
		return -2;
	}

	*pos = n + 1;

	return 0;
}

int main(void)
{
	const char* keywords[] = {
		"while",
		"case",
		"static",
		"do"
	};

	int pos = 0;
	int ret = 0;

	ret = searcheKeyTable(keywords, NUM(keywords), "do", &pos);
	if (ret != 0)
	{
		printf("searcheKeyTable err: %d\n", ret);
		system("pause");
		return ret;
	}

	printf("%s��keywordsλ��Ϊ��%d\n", "do", pos);


	printf("\n");
	system("pause");
	return 0;
}