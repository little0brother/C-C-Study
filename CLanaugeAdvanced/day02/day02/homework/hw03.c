/*
* ��һ���ַ�����1a2b3d4z����
   Ҫ��дһ������ʵ�����¹��ܣ�
	����1����ż��λ�ַ���ѡ���������һ���ַ���1��
	����2��������λ�ַ���ѡ���������һ���ַ���2��
	����3�����ַ���1���ַ���2��ͨ���������������͸�main������ӡ��
	����4���������ܲ���ͨ����
	int getStr1Str2(char *source, char *buf1, char *buf2);
*/

/*
*	���ܣ���������λ��ż��λ�ַ������ֱ�����������Ӵ�
*	������
*		source: Ҫ�ּ���ַ���
*		buf1:   ������λ�ַ���
*		buf2:   ��ż��λ�ַ���
*	����ֵ:
*		�ɹ���0
*		ʧ�ܣ���0
* 
*/

#include <stdio.h>

int getStr1Str2(char* source, char* buf1, char* buf2)
{
	int i = 0;

	if (source == NULL || buf1 == NULL || buf2 == NULL)
	{
		return -1;
	}

#if(0)
	while (source[i] != 0)
	{
		// 0 �� 2 ȡ��Ϊ 0 
		// ����������ȡ�����㣬�ſɶ� i ������ �����ȱʧ��һλ
		if (i % 2 == 0)
		{
			*buf1++ = source[i];
		}
		else
		{
			*buf2++ = source[i];
		}

		i++;
	}
#endif

#if(1)
	int n = strlen(source); // �ַ�������
	for (i = 0; i < n; i++)
	{
		// �����ż��λ
		if ( (i % 2) == 0 )
		{
			*buf1++ = source[i];
		}
		// ���������λ
		else
		{
			*buf2++ = source[i];
		}
	}

	*buf1 = 0;
	*buf2 = 0;

#endif

	return 0;
}

int main(void)
{
	char* str = "1a2b3d4z";
	char buf1[100] = { 0 };
	char buf2[100] = { 0 };
	int ret = 0;

	ret = getStr1Str2(str, buf1, buf2);
	if (ret != 0)
	{
		printf("getStr1Str2 err:%d\n", ret);
		return ret;
	}

	printf("buf1 = %s\n", buf1);
	printf("buf2 = %s\n", buf2);

	printf("\n");
	return 0;
}