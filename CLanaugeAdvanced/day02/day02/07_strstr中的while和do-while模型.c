#include <stdio.h>

#if(0)

// do-while ģ��
int main(void)
{
	char* str = "abcd123abcd543442abcdifa088abcdafdabcd1abcdabcdabcdabcd";
	int count = 0;

	do{
		str = strstr(str, "abcd");
		if (str != NULL)
		{
			count++;				// �ۼƸ���
			str = str + sizeof("abcd") - 1;	// �������ò��ҵ����
		}
		else	// ���û��ƥ����ַ���������ѭ��
		{
			break;
		}
	} while (*str != 0);	// �ж��Ƿ񵽴��ַ�����β

	printf("\"abcd\"������ %d ��", count);

	printf("\n");
	return 0;
}
#endif

#if(0)

// whileģ�� 
int main(void)
{
	char* str = "abcd123abcd543442abcdifa088abcdafdabcd1abcdabcdabcd";
	int count = 0;

	while ( (str = strstr(str, "abcd")) != NULL )
	{
		// �ܽ������϶���ƥ����Ӵ�

		// �������ò������
		str = str + strlen("abcd");
		count++;

		if (*str == 0)  // �����������
		{
			break;
		}
	}
	printf("\"abcd\"������ %d ��\n", count);

	printf("\n");
	return 0;
}

#endif

#if(1)

// ��װ����

int my_strstr(char* str, int* count)
{
	// ��������
	int i = 0;
	char* tmp = str;

	while (tmp = strstr(tmp, "abcd"))
	{
		// �ܽ������϶���ƥ����Ӵ�

		// �������ò������
		tmp = tmp + strlen("abcd");
		i++;

		if (*tmp == 0)  // �����������
		{
			break;
		}
	}
	*count = i;

	return 0;
}

int main(void)
{
	char* str = "abcd123abcd543442abcdifa088abcdafdabcd1abcdabcdabcdabcd";
	int count = 0;
	int ret = 0;

	ret = my_strstr(str, &count);
	if (ret != 0)
	{
		return ret;
	}
	printf("\"abcd\"������ %d ��\n", count);

	printf("\n");
	return 0;

}

#endif