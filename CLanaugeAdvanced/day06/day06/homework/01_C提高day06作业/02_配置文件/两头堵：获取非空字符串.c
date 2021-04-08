#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
2. ��һ���ַ�����ͷ���β����n���ո� ��"   abcdefgdddd    "������ȥ��ǰ��ո񣬷���һ�����ַ�����
	Ҫ��1�����Լ�����һ���ӿڣ�����������ʵ�ֹ��ܣ�
	Ҫ��2����д����������
	int trimSpace(char *inbuf, char *outbuf);
*/


/* 
���ܣ���ȡ�ǿ��ַ���
������
	inbuf�� ԭʼ�ַ���buf�׵�ַ
	outbuf���ǿ��ַ���buf�׵�ַ
����ֵ��
	�ɹ���0
	ʧ�ܣ���0
*/
int trimSpace(char *inbuf, char *outbuf)
{
	if (inbuf == NULL || outbuf == NULL)
	{
		return -1;
	}

	char *p = inbuf;
	int begin = 0;
	int end = strlen(p) - 1;
	int n = 0;

	if (end < 0){
		return -2;
	}

	//���������ƶ��������ǰ�ַ�Ϊ�գ�����û�н���
	while (isspace(p[begin]) && p[begin] != 0)
	{
		begin++; //λ�ô����ƶ�һλ
	}

	//���������ƶ��������ǰ�ַ�Ϊ��
	while (isspace(p[end]) && end > 0)
	{
		end--; //�����ƶ�
	}

	if (end == 0)
	{
		return -2;
	}

	n = end - begin + 1; //�ǿ�Ԫ�ظ���

	strncpy(outbuf, p + begin, n);
	outbuf[n] = 0;

	return 0;
}

int main(void)
{
	char *p = "   abcdefgdddd    ";
	char buf[128] = { 0 };
	int ret = 0;

	ret = trimSpace(p, buf);
	if (ret != 0)
	{
		printf("trimSpace err: %d\n", ret);
	}

	printf("buf:%s\n", buf);
	
	printf("\n");
	system("pause");
	return 0;
}