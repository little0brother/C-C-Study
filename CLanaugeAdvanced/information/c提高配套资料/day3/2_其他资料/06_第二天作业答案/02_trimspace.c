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

	int begin = 0; //�ַ�����һ��Ԫ��λ��
	int end = strlen(inbuf) - 1;//�ַ������һ��Ԫ��λ��
	int n = 0;

	if (end < 0) //������
	{
		return -2;
	}

	//�������ң������ǰ�ַ�Ϊ�գ�����û�н���
	while (inbuf[begin] == ' ' && inbuf[begin] != 0)
	{
		begin++; //�����ƶ�
	}

	//�������������ǰ�ַ�Ϊ��
	while (inbuf[end] == ' ')
	{
		end--; //�����ƶ�
	}

	n = end - begin + 1; //�ǿ�Ԫ�ظ���

	strncpy(outbuf, inbuf + begin, n);
	outbuf[n] = 0; //��Ϊstrncpy()�����Զ����'\0'��������Ҫ��Ϊ���

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