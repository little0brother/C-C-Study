/**
* 6. ��һ���ַ�������������������abcdef, acccd, eeee, aaaa, e3eeee, ssss, ����
*
�ڶ���API(�������ڴ�ģ�ͣ���̬���ɶ�ά�ڴ�)
1)�Զ��ŷָ��ַ������γ�һ������ָ��
2)��һ����ֶ������ַ�����������
int spitString(const char* str, char c, char** myp, int* count);

Ҫ��
1, ����ȷ��﹦�ܵ�Ҫ�󣬶�����ӿڡ�
2, ��ȷʵ�ֽӿں͹���.
3, ��д��ȷ�Ĳ�������.

* /

/**
*	str    : ��Ҫ�ָ����ַ���
*	c      : �ָ��ַ����ı�־
*	myp    : ���շָ��ַ���
*	count  : ��������¼һ���ж����Ӵ�
*
*	return :  0    �ɹ�
*			  ��0  ʧ��
*/

#include <stdio.h>
#include <string.h>

#define MALLOCLEN 512

int spitString(const char* str, char* c, char** myp, int* count)
{
	if (str == NULL || c == NULL || myp == NULL)
	{
		return -1;
	}

	char* start = str;
	char* p = NULL;
	int len = 0;

	do 
	{
		p = strchr(start, *c);
		// ����������ҵ��ַ�
		if (p != NULL)
		{
			len = 0;
			len = p - start;

			if (len > 0)
			{
				strncpy(myp[*count], start, len);
				myp[*count][len] = '\0';
			}
			
			// �ƶ���ʼλ��
			start += (len + strlen(c));
			(*count)++;
		}
		// ���û�в��ҵ��ַ�
		else
		{
			strcpy(myp[*count], str);
			myp[*count][strlen(start)] = '\0';
			(*count)++;
			break;
		}
	} while (*start != 0);

	return 0;
}

char** getMemRec(int n)
{
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

int freeMem(char** buf, int n)
{
	if (buf == NULL)
	{
		return -1;
	}

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

int main()
{
	char* str        = ",abcdef, acccd ,eeee ,aaa e3e eee, ssss ";
	char* c          = ",";
	char** split_str = NULL;
	int count        = 0;
	int ret          = 0;

	split_str = getMemRec(MALLOCLEN);
	if (split_str == NULL)
	{
		printf("getMemRec err !");
		return -1;
	}

	ret = spitString(str, c, split_str, &count);
	if (ret != 0)
	{
		printf("spitString err : %d\n", ret);
		return ret;
	}

	for (int i = 0; i < count; i++)
	{
		printf("%s\n", split_str[i]);
	}

	ret = freeMem(split_str, MALLOCLEN);
	if (ret != 0)
	{
		printf("freeMem err : %d\n");
		return ret;
	}

	return 0;
}