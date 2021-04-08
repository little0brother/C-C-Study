#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
3. ��һ���ַ�����1a2b3d4z����
Ҫ��дһ������ʵ�����¹��ܣ�
	����1����ż��λ�ַ���ѡ���������һ���ַ���1��
	����2��������λ�ַ���ѡ���������һ���ַ���2��
	����3�����ַ���1���ַ���2��ͨ���������������͸�main������ӡ��
	����4���������ܲ���ͨ����
int getStr1Str2(char *source, char *buf1, char *buf2);
*/

int getStr1Str2(char *source, char *buf1, char *buf2)
{
	if (source == NULL || buf1 == NULL || buf2 == NULL)
	{
		return -1;
	}

	int i = 0;
	int n = strlen(source); //�ַ�������

	//��ò�Ҫֱ�Ӳ����βΣ����������������βνӹ���
	char *p1 = buf1;
	char *p2 = buf2;

	for (i = 0; i < n; i++)
	{
		if ((i + 1) % 2 == 0)//ż��λ
		{
			*p1 = *(source + i); //�ȼ��� *p1 = source[i]
			p1++;
		}
		else //����λ
		{
			*p2 = *(source + i);//�ȼ��� *p2 = source[i]
			p2++;
		}
	}

	//�ַ���������
	*p1 = 0; //'\0'
	*p2 = 0; //'\0'

	return 0;
}

int main(void)
{
	char str[] = "1a2b3d4z";
	char buf1[50] = { 0 };
	char buf2[50] = { 0 };

	int ret = getStr1Str2(str, buf1, buf2);
	if (ret != 0)
	{
		printf("getStr1Str2 error: %d\n", ret);
		return ret;
	}
	printf("buf1 = %s\nbuf2 = %s\n", buf1, buf2);
	
	printf("\n");
	system("pause");
	return 0;
}