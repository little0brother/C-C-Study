/**
6. ��һ���ַ�������������������abcdef, acccd, eeee, aaaa, e3eeee, ssss, ����

д��������(API)��������½��
��һ��API(�ڶ����ڴ�ģ�ͣ� ��ά����)
1)�Զ��ŷָ��ַ������γɶ�ά���飬���ѽ������
2)�Ѷ�ά��������������Ҳ����
 int spitString(const char* str, char c, char buf[10][30], int* count);

Ҫ��
1, ����ȷ��﹦�ܵ�Ҫ�󣬶�����ӿڡ�
2, ��ȷʵ�ֽӿں͹���.
3, ��д��ȷ�Ĳ�������.

*/

/**
*	str    : ��Ҫ�ָ����ַ���
*	c      : �ָ��ַ����ı�־
*	buf    : ���շָ��ַ���
*	count  : ��������¼һ���ж����Ӵ�
* 
*	return :  0    �ɹ�
*			  ��0  ʧ��
*/

#include <stdio.h>
#include <string.h>

// ����
int spitString(const char* str, char *c, char buf[10][30]/*in*/, int* count);

int spitString(const char* str, char *c, char buf[10][30]/*in*/, int* count)
{
	if (str == NULL || count == NULL || buf == NULL)
	{
		return -1;
	}

	char* str_bak = str;	// ��Ų���str�� , λ��
	char* str_bak1 = str;	// �����һ�β���λ�� 
	int cstrlen = 0;		// ������������������ �м� �Ӵ�����
	char tmp[30] = { 0 };
	int count_bak = 0;

	while (str_bak = strchr(str_bak, *c))
	{
		// ����","λ�� ����","λ�÷���ֵstr_bak
		if (str_bak == NULL)
		{
			break;
		}

		// ���㶺��֮�����ַ����ĳ���
		cstrlen = (str_bak - str_bak1);

		// ���Ӵ�����
		strncpy(buf[count_bak++], str_bak1, cstrlen);

		// �����ڼ����ֵλ�õ� ָ�������λ��������һ��λ��
		str_bak1 += (cstrlen + strlen(c));
		str_bak += strlen(c);	// ��Ϊָ��ָ�򶺺ţ��޷�����������һλ
	}

	if (str_bak == NULL && str_bak1 != NULL)
	{
		cstrlen = strlen(str_bak1);
		strncpy(buf[count_bak++], str_bak1, cstrlen);
	}
	
	*count = count_bak;

	return 0;
}

void print_arr(char* title, char buf[][30], int count)
{
	printf("%s:\n", title);
	for (int i = 0; i < count; i++)
	{
		printf("%s\n", buf[i]);
	}
}

int main()
{
	char *str			   =  "abcdef, acccd, eeee, aaaa, e3eeee, ssss, aaa3";
	char *split_ch	  	   = ","; 
	char rec_split[10][30] = { 0 };
	int split_count		   = 0;
	int ret				   = 0;

	printf("�ָ�ǰ��\n");
	printf("%s\n", str);

	ret = spitString(str, split_ch, rec_split, &split_count);
	if (ret != 0)
	{
		printf("spitString err:%d", ret);
		return ret;
	}

	printf("\n�ָ���\n");
	print_arr("spitString2", rec_split, split_count);

	printf("\n");
	return 0;
}