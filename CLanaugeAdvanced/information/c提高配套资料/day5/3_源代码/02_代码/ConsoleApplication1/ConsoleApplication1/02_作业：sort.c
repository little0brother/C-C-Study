#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sort(char **array1, int num1,
	char(*array2)[30], int num2,
	char ***myp3 /*out*/, int *num3)
{
	if (array1 == NULL || array2 == NULL
		|| myp3 == NULL || num3 == NULL)
	{
		return -1;
	}

	//����һ��ָ������ char *tmp[num1 + num2]
	char **tmp = (char **)malloc(sizeof(char *)*(num1 + num2));
	if (tmp == NULL)
	{
		return -2;
	}

	int i = 0;
	int j = 0;

	//char *array1[] = { "aa", "ccccccc", "bbbbbb" };
	//char array2[][30] = { "111111", "3333333", "222222" }
	//��ÿ��ָ������ڴ棨ָ�������
	for (i = 0; i < num1; i++)
	{
		//tmp[i] = (char *)malloc(sizeof(char)* (strlen(array1[i]) + 1));
		tmp[i] = (char *)malloc(sizeof(char)* 30);
		strcpy(tmp[i], array1[i]);
	}

	//char array2[][30] = { "111111", "3333333", "222222" }
	//i�ĳ�ʼ������num1��ʼ����Ҫ,����һ������j
	for (i = num1, j = 0; i < num1 + num2; i++, j++)
	{
		//array2[j]��j����i
		//tmp[i] = (char *)malloc(sizeof(char)* (strlen(array2[j]) + 1));
		tmp[i] = (char *)malloc(sizeof(char)* 30);
		strcpy(tmp[i], array2[j]);
	}


#if 0
	//����
	int n = num1 + num2;
	char *p = NULL;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(tmp[i], tmp[j]) > 0)//����
			{//������ָ��ָ��
				p = tmp[i];
				tmp[i] = tmp[j];
				tmp[j] = p;
			}
		}
	}
#endif
	//����
	int n = num1 + num2;
	char p[50] = { 0 };
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			//if (strcmp(tmp[i], tmp[j]) > 0)//����
			if (strcmp(*(tmp + i), *(tmp+j)) > 0)
			{//�������ڴ��
				strcpy(p, tmp[i]);
				strcpy(tmp[i], tmp[j]);
				strcpy(tmp[j], p);
			}
		}
	}


	//��Ӹ�ֵ��ָ������������
	*myp3 = tmp;
	*num3 = num1 + num2;

	return 0;
}

void free_buf(char ***p3, int n)
{
	if (p3 == NULL)
	{
		return;
	}

	char **tmp = *p3;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (tmp[i] != NULL)
		{
			free(tmp[i]);
			tmp[i] = NULL;
		}
	}

	if (tmp != NULL)
	{
		free(tmp);
		*p3 = NULL;
	}


}

int main(void)
{
	int ret = 0;
	char *p1[] = { "aa", "ccccccc", "bbbbbb" };
	char buf2[][30] = { "111111", "3333333", "222222" };
	char **p3 = NULL;
	int len1, len2, len3, i = 0;

	len1 = sizeof(p1) / sizeof(*p1);
	len2 = sizeof(buf2) / sizeof(buf2[0]);

	for (i = 0; i < len1; i++)
	{
		printf("%s, ", p1[i]);
	}
	for (i = 0; i < len2; i++)
	{
		printf("%s, ", buf2[i]);
	}
	printf("\n\n");

	/*
	���ܣ�1����ָ������p1���ַ���ȡ������
	2���Ѷ�ά����buf2���ַ�ȡ������
	3��������ַ������� p3��p3 ���ڶ�������Ķ�ά�ڴ�
	4���� p3 ���ַ�����������ͨ�� strcmp() ��������
	������
	p1�� ָ�������׵�ַ��char *p1[] = {"aa", "ccccccc", "bbbbbb"};
	len1��p1Ԫ�ظ���
	buf2����ά������Ԫ�ص�ַ��char buf2[][30] = {"111111", "3333333", "222222"};
	len2��buf2�ַ���������
	p3������ָ��ĵ�ַ����Ҫ�ں����ڷ����ά�ڴ棬����p1��buf2���ַ���������Ҫ����
	len3������p3�е��ַ�������
	����ֵ��
	*/
	ret = sort(p1, len1, buf2, len2, &p3, &len3);
	if (ret != 0)
	{
		printf("sort err: %d\n", ret);
		system("pause");

		return ret;
	}

	for (i = 0; i < len3; i++)
	{
		printf("%s, ", p3[i]);
	}
	printf("\n");

	//�ͷ�p3��ָ���ڴ�
	//�ں����ڲ���p3��ֵ��ֵΪNULL
	free_buf(&p3, len3);

	printf("\n");
	system("pause");
	return 0;
}