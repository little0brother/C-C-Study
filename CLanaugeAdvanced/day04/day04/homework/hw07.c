/**
* 7. �ҵ�������ָ���ַ�����λ��
	#define NUM(a) (sizeof(a)/sizeof(*a))

	char* keywords[] = {
		"while", 
		"case",
		"static",
		"do"
	};

	int searcheKeyTable(const char* table[], const int size, 
				  const char* key, int *pos);
*/

/**
* ���ܣ��ҵ�������ָ���ַ�����λ��
*	table : �ַ������飨ָ�����飩�׵�ַ����Ҫ�����в��ҵ��ַ���
*	size  :	table�Ӵ�����
*	key   : ƥ���ַ������� "do"
*	pos   :	ƥ���ַ����������е�λ�ã����"do"��keywords[]��λ��Ϊ4
* 
*	return:
*		0 : �ɹ�
*	  ��0 :	ʧ��
*/

#include <stdio.h>
#include <string.h>

#define NUM(a) (sizeof(a)/sizeof(*a))

int searcheKeyTable(const char* table[] /*ָ������*/, const int size, const char* key, int* pos)
{
	if (table == NULL || key == NULL)
	{
		return -1;
	}

	char** str = table;
	int count = -1;
	int i = 0;
	
	// ѭ�����Ҷ�Ӧ�ַ���
	for (i = 0; i < size; i++)
	{
		// �Ա�Ŀǰ�Ӵ���Ŀ���Ӵ�������ͬ����������ͬ������ѭ��
		if (str[i] == key)
		{
			count = i;
			break;
		}
	}

	// û�в��ҵ�ƥ���Ӵ�
	if (count == -1)
	{
		return -2;
	}

	*pos = count + 1;

	return 0;
}

int main()
{
	int ret = 0;
	int posiston;
	char* key = "static";
	char* keywords[] = {
		"while",
		"case",
		"static",
		"do"
	};
	
	ret = searcheKeyTable(keywords, NUM(keywords), key, &posiston);
	if (ret != 0)
	{
		printf("searcheKeyTable err : %d\n", ret);
		return ret;
	}

	if (ret == -2)
	{
		printf("%s �����ڣ�\n", key);
	}
	else
	{
		printf("%s���ַ���keywords�е�%dλ\n", key, posiston);
	}
	
	return 0;
}