#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main01(void)
{
	char *p = "11abcd111122abcd333abcd3322abcd3333322qqq";
	int n = 0;

	do 
	{
		p = strstr(p, "abcd");
		if (p != NULL)
		{
			n++; //�ۼƸ���

			//�������ò��ҵ����
			p = p + strlen("abcd");

		}
		else //���û��ƥ����ַ���������ѭ��
		{
			break;
		}


	} while (*p != 0); //���û�е���β

	printf("n = %d\n", n);

	printf("\n");
	system("pause");
	return 0;
}

int main02(void)
{
	char *p = "11abcd111122abcd333abcd3322abcd3333322qqq";
	int n = 0;

	while (  ( p = strstr(p, "abcd") ) != NULL )
	{
		//�ܽ������϶���ƥ����Ӵ�

		//�����������λ��
		p = p + strlen("abcd");
		n++;

		if (*p == 0) //�����������
		{
			break;
		}
		
	}

	printf("n = %d\n", n);

	printf("\n");
	system("pause");
	return 0;
}

int my_strstr(char *p, int *n)
{
	//��������
	int i = 0;
	char *tmp = p;

	while ((tmp = strstr(tmp, "abcd")) != NULL)
	{
		//�ܽ������϶���ƥ����Ӵ�

		//�����������λ��
		tmp = tmp + strlen("abcd");
		i++;

		if (*tmp == 0) //�����������
		{
			break;
		}

	}

	//��Ӹ�ֵ
	*n = i;

	return 0;
}

int main(void)
{
	
	char *p = "11abcd111122abcd333abcd3322abcd3333322qqq";
	int n = 0;
	int ret = 0;

	ret = my_strstr(p, &n);
	if (ret != 0)
	{
		return ret;
	}
	printf("n = %d\n", n);



	printf("\n");
	system("pause");
	return 0;
}