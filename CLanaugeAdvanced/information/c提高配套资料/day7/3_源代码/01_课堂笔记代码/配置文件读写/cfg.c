#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define  SIZE 1024*8

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


int ReadCfgFile(char *file, char *key, char *value, int *len)
{

	if (file == NULL || key == NULL || value == NULL || len == NULL)
	{
		return -1;
	}

	FILE *fp = NULL;
	int ret = 0;
	char lineBuf[1024] = { 0 };
	char *p = NULL;
	int flag = 0; //0����û���ҵ��� 1�����ҵ�

	//���ļ�
	fp = fopen(file, "r+");
	if (fp == NULL)
	{
		ret = -2;
		goto End;
	}

	while (1)
	{
		//��ȡ1��
		if (fgets(lineBuf, sizeof(lineBuf), fp) == NULL)
		{
			break;
		}

		//lineBuf = "k1 = abc"
		//��key
		p = strstr(lineBuf, key);
		if (p == NULL)//û��
		{
			continue; //��������ѭ��
		}

		//�����������
		//"k1 = abc" -> " = abc"
		p = p + strlen(key);

		//�ҡ�=��
		p = strstr(p, "=");
		if (p == NULL)//û��
		{
			continue; //��������ѭ��
		}

		//�����������
		//" = abc" -> " abc"
		p = p + strlen("=");

		//��ȡ�ǿ��ַ�
		ret = trimSpace(p, value);
		if (ret == 0) //�ɹ�
		{
			*len = strlen(value);
			flag = 1;
			goto End;
		}
		else
		{
			goto End;
		}

	}




End:
	if (fp != NULL)
	{
		fclose(fp);
	}

	if (0 == flag)
	{
		ret = -3;
		printf("û��%s��Ӧ��value\n", key);
	}


	return ret;
}

int WriteCfgFile(char *file, char *key, char *value, int len)
{
	if (file == NULL || key == NULL || value == NULL)
	{
		return -1;
	}

	FILE *fp = NULL;
	int ret = 0;
	char lineBuf[1024] = { 0 };
	char buf[SIZE] = { 0 };
	char *p = NULL;
	int flag = 0; //0����û���ҵ��� 1�����ҵ�

	//��д����+������
	fp = fopen(file, "r+");
	if (fp == NULL)//��ʧ�ܣ��п����������ļ�û�д���
	{
		//���������ļ�
		fp = fopen(file, "w+");
		{
			if (fp == NULL)
			{
				ret = -2;
				goto End;
			}
		}
	}

	//��ȡ�ļ���С
	//����ƶ�����β
	fseek(fp, 0, SEEK_END);

	long size = ftell(fp);
	if (size >= SIZE)
	{
		ret = -3;
		printf("�ļ���С����8k����֧��");
		goto End;
	}

	//���ص��ļ���ͷ
	rewind(fp);

	while (1)
	{
		if (fgets(lineBuf, sizeof(lineBuf), fp) == NULL)
		{
			break;
		}

		//ÿһ���Ƿ����key
		if (strstr(lineBuf, key) != NULL)
		{//����key
			flag = 1; //1�����ļ����Ѿ���key
			sprintf(lineBuf, "%s = %s\n", key, value);
			strcat(buf, lineBuf);

		}
		else
		{
			strcat(buf, lineBuf);
		}

	}

	//�����⣬2�����
	if (0 == flag)//û��key
	{
		//�ļ�����Ѿ��ƶ����ļ���β
		fprintf(fp, "%s = %s\n", key, value);

	}
	else//��key
	{
		//�ر��ļ�
		if (fp != NULL)
		{
			fclose(fp);
			fp = NULL;
		}

		fp = fopen(file, "w+"); 
		if (fp == NULL)
		{
			ret = -4;
			goto End;
		}

		//��дд����
		fputs(buf, fp);
	}

End:
	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}

	return ret;
}