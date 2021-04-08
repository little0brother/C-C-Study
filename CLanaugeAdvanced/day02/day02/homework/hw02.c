/*
* ��һ���ַ�����ͷ���β����n���ո� ����   abcdefgdddd    ��������ȥ��ǰ��ո񣬷���һ�����ַ�����
	Ҫ��1�����Լ�����һ���ӿڣ�����������ʵ�ֹ��ܣ�
	Ҫ��2����д����������
	int trimSpace(char *inbuf, char *outbuf);
*/

/*
	���ܻ�ȡ�ǿ��ַ���
	������
		inbuf:  ԭʼ�ַ���buf�׵�ַ
		outbuf: �ǿ��ַ���buf�׵�ַ
	����֮��
		�ɹ���0
		ʧ�ܣ���0
*/

#include <stdio.h>
#include <ctype.h>

int trimSpace(char* inbuf, char* outbuf)
{
	char* p = inbuf;
	char* buf = outbuf;
	int begin = 0;
	int end = strlen(p) - 1;
	int n = 0;

	if (p == NULL || buf == NULL)
	{
		return -1;
	}

	while (isspace(p[begin]) && p[begin] != NULL)
	{
		begin++;
	}

	while (isspace(p[end]) && p[end] != NULL)
	{
		end--;
	}

	n = end - begin + 1;
	printf("n = %d\n", n);

	strncpy(buf, p + begin, n);

	return 0;
}

int main(void)
{
	char* str = "   abcdefgdddd    ";
	char buf[100] = { 0 };
	int ret = 0;

	ret = trimSpace(str, buf);
	if (ret != 0)
	{
		return ret;
	}
	printf("ȡ�����ַ���Ϊ: %s\n", buf);

	printf("\n");
	return 0;
}