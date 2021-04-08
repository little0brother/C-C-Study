/**
* 6. ��һ���ַ�������������������abcdef, acccd, eeee, aaaa, e3eeee, ssss, ����
* 
�ڶ���API(�������ڴ�ģ�ͣ���̬���ɶ�ά�ڴ�)
1)�Զ��ŷָ��ַ������γ�һ������ָ��
2)��һ����ֶ������ַ�����������
int spitString2(const char* str, char c, char** myp, int* count);

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

#define MALLOCLEN 10
#define CSTRLEN	  128

int spitString2(const char* str, char* c, char** myp /*in*/, int* count)
{
	if (str == NULL || count == NULL || myp == NULL)
	{
		return -1;
	}

	char* str_bak = str;	// ��Ų���str�С�,��λ��
	char* str_bak1 = str;	// �����һ�β���λ�� 
	int cstrlen = 0;		// ������������������ �м� �Ӵ�����
	char tmp[30] = { 0 };
	int count_bak = 0;

	while (str_bak = strstr(str_bak, c))
	{
		// �·���ʵ�ִ˹���
		//// ���û�Ҳ��ҵ�Ŀ�꣬�������ַ������Ƶ�myp�в���ȥѭ��
		//if (str_bak == NULL)
		//{
		//	strncpy(myp[count_bak], str_bak1, strlen(str_bak1));
		//	myp[count_bak][strlen(str)] = '\0';
		//	break;
		//}

		// ����","λ�� ����","λ�÷���ֵstr_bak
		if (str_bak == NULL)
		{
			break;
		}

		// ���㶺��֮�����ַ����ĳ���
		cstrlen = (str_bak - str_bak1);

		// ���Ӵ�����
		strncpy(myp[count_bak], str_bak1, cstrlen);
		myp[count_bak][cstrlen] = '\0';		// ��ӽ�����

		// �����ڼ����ֵλ�õ�ָ�������λ��������һ��λ��
		str_bak1 += (cstrlen + strlen(c));
		str_bak += strlen(c);	// ��Ϊָ��ָ�򶺺ţ��޷�����������һλ
		count_bak++;	// ����������
	}

	// ���û�Ҳ��ҵ�Ŀ�꣬�������ַ������Ƶ�myp�в���ȥѭ��
	if (str_bak == NULL && str_bak1 != NULL)
	{
		cstrlen = strlen(str_bak1);
		strncpy(myp[count_bak], str_bak1, strlen(str_bak1));
		myp[count_bak][cstrlen] = '\0';
		count_bak++;
	}

	*count = count_bak;

	return 0;
}

// �����ڴ�ռ�
char** getMem_rec(int n)
{
	char** buf = (char**)malloc(n * sizeof(char*));
	if (buf == NULL)
	{
		return NULL;
	}

	for (int i = 0; i < n; i++)
	{
		buf[i] = (char*)malloc(CSTRLEN * sizeof(char));
	}

	return buf;
}

// �����ڴ�ռ䣬����Ҫ���ص�ַ,ֱ���ں���������ڴ�����
int getMem_rec2(char*** buf, int n)
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

void print_arr(char** buf, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%s\n", buf[i]);
	}
}

// �ͷ�������ڴ�ռ�
void free_rec(char** buf, int n)
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

int calLen(char *str, char *c)
{
	int count = 1;
	while (str = strstr(str, c))
	{
		count++;
		str += strlen(c);
	}

	return count + 1;
}

int main()
{
	char* str        = ",abcdef ,acccd ,eeee, aaaa ,e3eeee ,ssss ,aaa3";
	char* split_ch   = ",";
	char** rec_split = NULL;
	int split_count  = 0;
	int ret          = 0;
	int clen         = 0;
	
	// �����ڴ泤�ȿ���ͨ������','����,��ȷ��
	clen = calLen(str, split_ch);

#if(0)
	rec_split = getMem_rec(clen);
	if (rec_split == NULL)
	{
		printf("getMen_rec err:");
		return -1;
	}
#endif

#if(1)
	ret = getMem_rec2(&rec_split, clen);
	if (ret != 0)
	{
		printf("getMem_rec2 err:%d", ret);
		return -2;
	}
#endif

	printf("���֮ǰ��\n");
	printf("%s", str);

	ret = spitString2(str, split_ch, rec_split, &split_count);
	if (ret != 0)
	{
		printf("spitString2 err:%d", ret);
		return ret;
	}

	printf("\n���֮��\n");
	print_arr(rec_split, split_count);

	free_rec(rec_split, clen);
	rec_split = NULL;

	printf("\n");
	return 0;
}