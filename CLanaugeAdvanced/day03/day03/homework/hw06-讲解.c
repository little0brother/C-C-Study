/**
	6. ��һ���ַ�������������������abcdef, acccd, eeee, aaaa, e3eeee, ssss, ����

	д��������(API)��������½��
	��һ��API(�ڶ����ڴ�ģ�ͣ� ��ά����)
	1)�Զ��ŷָ��ַ������γɶ�ά���飬���ѽ������
	2)�Ѷ�ά��������������Ҳ����
	int spitString(const char* str, char c, char buf[10][30], int* count);

	�ڶ���API(�������ڴ�ģ�ͣ���̬���ɶ�ά�ڴ�)
	1)�Զ��ŷָ��ַ������γ�һ������ָ�롣
	2)��һ����ֶ������ַ�����������
	int spitString2(const char* str, char c, char** myp, int* count);

	Ҫ��
	1, ����ȷ��﹦�ܵ�Ҫ�󣬶�����ӿڡ�
	2, ��ȷʵ�ֽӿں͹���.
	3, ��д��ȷ�Ĳ�������.
*/

// ��ĿҪ��һ
#if(0)
#include <stdio.h>
#include <string.h>

int spitString(const char* str, char c, char buf[10][30], int* count)
{
	if (str == NULL || count == NULL)
	{
		return -1;
	}

	// str = "abcdef, acccd, eeee, aaaa, e3eeee, ssss, ";
	const char* start = str;
	char* p = NULL;
	int i = 0;


	do
	{
		p = strchr(start, c);
		if (p != NULL)
		{
			int len = p - start;
			strncpy(buf[i], start, len);
			// ������
			buf[i][len] = '\0';

			i++;
			// �����������λ��
			start = p + 1;
		}
		else
		{
			strcpy(buf[i], start);
			i++;
			break;
		}
	} while (*start != 0);

	// ���i=0 ˵��û���ҵ�','
	if (i == 0)
	{
		return -2;
	}

	*count = i;

	return 0;
}

int main()
{
	const char* str = "abcdef, acccd, eeee, aaaa, e3eeee, ssss, ";
	char buf[10][30] = { 0 };
	int n = 0;
	int ret = 0;

	ret = spitString(str, ',', buf, &n);
	if (ret != 0)
	{
		printf("splitString err: %d\n", ret);
		return ret;
	}

	for (int i = 0; i < n; i++)
	{
		printf("%s\n", buf[i]);
	}

	printf("\n");
	return 0;
}
#endif

// ��ĿҪ���
#if(1)

#include <stdio.h>
#include <string.h>

int spitString(const char* str, char c, char** buf, int* count)
{

	if (str == NULL || count == NULL)
	{
		return -1;
	}

	// str = "abcdef, acccd, eeee, aaaa, e3eeee, ssss, ";
	const char* start = str;
	char* p = NULL;
	int i = 0;


	do
	{
		p = strchr(start, c);
		if (p != NULL)
		{
			int len = p - start;
			strncpy(buf[i], start, len);
			// ������
			buf[i][len] = '\0';

			i++;
			// �����������λ��
			start = p + 1;
		}
		else
		{
			strcpy(buf[i], start);
			i++;
			break;
		}
	} while (*start != 0);

	// ���i=0 ˵��û���ҵ�','
	if (i == 0)
	{
		return -2;
	}

	*count = i;

	return 0;
}

char** getMem(int n)
{
	//char** buf = NULL;	// char *buf[n]
	char** buf = (char**)malloc(n * sizeof(char*));
	if (buf == NULL)
	{
		return NULL;
	}

	for (int i = 0; i < n; i++)
	{
		buf[i] = (char*)malloc(128 * sizeof(char));
	}

	return buf;
}

// �༶ָ���ʹ��
int getMem2(char*** buf, int n)
{
	char** tmp = NULL;
	tmp = (char**)malloc(n * sizeof(char*));
	if (tmp == NULL)
	{
		return -1;
	}

	for (int i = 0; i < n; i++)
	{
		tmp[i] = (char*)malloc(128 * sizeof(char));
	}

	// ��Ӹ�ֵ��ָ������������
	*buf = tmp;

	return 0;
}

void freeMem(char** buf, int n)
{
	for (int i = 0; i < n; i++)
	{
		free(buf[i]);
		buf[i] = NULL;
	}

	if (buf != NULL)
	{
		free(buf);
		buf = NULL;
	}
}

void freeMem2(char ***tmp , int n)
{
	char** buf = *tmp;		// *tmpΪָ����ڴ�����


	for (int i = 0; i < n; i++)
	{
		free(buf[i]);
		buf[i] = NULL;
	}

	if (buf != NULL)
	{
		free(buf);
		buf = NULL;
	}

	*tmp = NULL;
}

int main()
{
	const char* str = "abcdef, acccd, eeee, aaaa, e3eeee, ssss, ";
	char** buf = NULL;
	int n = 0;
	int ret = 0;

#if(0)
	buf = getMem(32);
	if (buf == NULL)
	{
		printf("getMem err: \n");
		return -1;
	}
#endif

	ret = getMem2(&buf, 32);
	if (ret != 0)
	{
		printf("getMem2 err: %d", ret);
		return ret;
	}

	ret = spitString(str, ',', buf, &n);
	if (ret != 0)
	{
		printf("splitString2 err: %d\n", ret);
		return ret;
	}

	for (int i = 0; i < n; i++)
	{
		printf("%s\n", buf[i]);
	}

#if(0)
	// �ͷ��ڴ�
	for (int i = 0; i < n; i++)
	{
		free(buf[i]);
		buf[i] = NULL;
	}
	if (buf != NULL)
	{
		free(buf);
		buf = NULL;
	}
#endif
	
	//freeMem(buf, n);
	//buf = NULL;

	freeMem2(&buf, n);
	if (buf != NULL)
	{
		free(buf);
		buf = NULL;
	}

	printf("\n");
	return 0;
}
#endif