/* ���ַ������������пո�ʱ�������ǿո��ַ�����,���ұ���ǿ��ַ��� */

#include <stdio.h>
#include <ctype.h>

#if(0)
int main(void)
{
	char* p = "    abcdefg     ";
	int begin = 0;
	int end = strlen(p) - 1;
	int n = 0;

	// ����߿�ʼ�ƶ����ǿո�λ��
	// �����ǰ�ַ�Ϊ�գ�����û�н���
	while (isspace(p[begin]) && p[begin] != 0)
	{
		begin++;	// λ�������ƶ�һλ
	}

	// ���ұ߿�ʼ�ƶ����ǿո�λ��
	while (isspace(p[end]) && p[end] != 0)
	{
		end--;		// λ�������ƶ�һλ
	}

	n = end - begin + 1;

	printf("n = %d\n", n);

	printf("\n");
	return 0;
}
#endif

// ��װ
#if(1)

// ����ǿ��ַ�������
int fun(char* p, int* n)
{
	char* str = p;
	int begin = 0;
	int end = strlen(str) - 1;

	if (str == NULL || n == NULL)
	{
		return -1;
	}

	// ����߿�ʼ�ƶ����ǿո�λ��
	// �����ǰ�ַ�Ϊ�գ�����û�н���
	while (isspace(str[begin]) && str[begin] != 0)
	{
		begin++;	// λ�������ƶ�һλ
	}

	// ���ұ߿�ʼ�ƶ����ǿո�λ��
	while (isspace(str[end]) && str[end] != 0)
	{
		end--;		// λ�������ƶ�һλ
	}

	*n = end - begin + 1;

	return 0;
}

// ȡ���ǿ��ַ���
int fun2(char *p, char *buf)
{
	char* str = p;
	int begin = 0;
	int end = strlen(str) - 1;
	int n = 0;

	if (str == NULL || buf == NULL)
	{
		return -1;
	}

	// ����߿�ʼ�ƶ����ǿո�λ��
	// �����ǰ�ַ�Ϊ�գ�����û�н���
	while (isspace(str[begin]) && str[begin] != 0)
	{
		begin++;	// λ�������ƶ�һλ
	}

	// ���ұ߿�ʼ�ƶ����ǿո�λ��
	while (isspace(str[end]) && str[end] != 0)
	{
		end--;		// λ�������ƶ�һλ
	}

	n = end - begin + 1;	// �ǿ�Ԫ�ظ���

	strncpy(buf, str + begin, n);	// �ַ�����������������ָ��copy����
	buf[n] = 0;

	return 0;
}

int main(void)
{
	char* p = "    abcdefg     ";
	int n = 0;
	int ret1 = 0;
	int ret2 = 0;
	char buf[100] = { 0 };

	ret1 = fun(p, &n);
	if (ret1 != 0)
	{
		return ret1;
	}
	printf("n = %d\n", n);

	ret2 = fun2(p, buf);
	if (ret2 != 0)
	{
		return ret2;
	}
	printf("buf = %s", buf);

	return 0;
}

#endif