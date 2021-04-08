#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//�ļ�����С
#define MAXSIZE 8*1024 //8K

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

//�������ļ�
int ReadCfgFile(char *fileName, char *pKey, char *pVal, int *pLen)
{

	if (fileName == NULL || pKey == NULL || pVal == NULL || pLen == NULL)
	{
		return -1;
	}

	FILE *fp = NULL;
	char buf[1024] = { 0 };
	char *tmp = NULL;
	int flag = 0; //���û��key����Ӧ��value��flag��Ϊ0

	//����ʽ���ļ�
	fp = fopen(fileName, "r");
	if (fp == NULL)
	{
		perror("ReadCfgFile[fopen]");
		return -2;
	}

	//����ļ�û�н���
	while (!feof(fp))
	{
		memset(buf, 0, sizeof(buf));
		tmp = fgets(buf, sizeof(buf), fp);
		if (tmp == NULL)
		{
			break;
		}

		//�ж�ÿ�����Ƿ����key
		tmp = strstr(buf, pKey);
		if (NULL == tmp)//���û�а���key
		{
			continue; //��������ѭ��
		}

		//�������������ַ�����λ�ã�����key��
		// "k1 = 1111" -> " = 1111"
		tmp = tmp + strlen(pKey);

		//�ж��Ƿ����=
		tmp = strchr(tmp, '=');
		if (NULL == tmp)
		{
			continue; //��������ѭ��
		}
		//�������������ַ�����λ��(����=)
		//"= 1111" -> "   1111  "
		tmp = tmp + 1;

		//��ȡ�ǿ��ַ�����ͷ��ģ��
		if (0 == trimSpace(tmp, pVal))
		{
			//���⣬�Ѿ��ҵ�����Ҫ���value
			*pLen = strlen(pVal); 
			flag = 1;
		}
		
		break; //����Ҫ
	}

	if (0 == flag)
	{
		printf("û��%s����Ӧ��ֵ\n", pKey);
		return -6;
	}

	//�ر��ļ�
	if (fp != NULL)
	{
		fclose(fp);
	}

	return 0;
}

//д���޸������ļ�
//ʵ������
//ѭ����ÿһ��
//���а���key�����key��value�޸�
//��������ж�������key�������ļ���β׷�ӣ� "key = value"
//�ѵ㣺����޸�
int WriteCfgFile(char *fileName, char *pKey, char *pVal, int len)
{
	if (fileName == NULL || pKey == NULL || pVal == NULL)
	{
		return -1;
	}

	FILE *fp = NULL;
	char tmpBuf[MAXSIZE] = { 0 };
	char lineBuf[1024] = { 0 };
	int flag = 0; //0: ������key

	//���ļ�����д��ʽ�򿪣��ļ������ڣ���ʧ��
	fp = fopen(fileName, "r+");
	if (fp == NULL) //�ļ�������ʱ���½��ļ�
	{
		//perror("WriteCfgFile ")
		//return -2;

		//д����ʽ���ļ����ļ��������򴴽�
		fp = fopen(fileName, "w+");
		if (fp == NULL)
		{
			perror("WriteCfgFile fopen");
			return -2;
		}
	}

	//�����ļ�����
	//��ȡ�ļ����ݴ�С�����Ƿ񳬳���Χ

	//���ļ�����ƶ�����β��
	fseek(fp, 0, SEEK_END);

	//��ȡ�ļ����ݴ�С
	long size = ftell(fp);

	//����ļ���С����8k���жϳ���
	if (size >= MAXSIZE)
	{
		printf("�ļ���С����8k����֧��\n");
		fclose(fp);
		return -3;
	}

	//���ļ�����ƶ����ʼλ��
	//fseek(fp, 0, SEEK_SET);
	rewind(fp);

	//ѭ����ÿһ��
	//���а���key�����key��value�޸�
	//��������ж�������key�������ļ���β׷�ӣ� "key = value"
	while (!feof(fp))
	{
		if (NULL == fgets(lineBuf, sizeof(lineBuf), fp))
		{
			break;
		}

		//�����Ƿ����key
		if (strstr(lineBuf, pKey) != NULL) //����
		{
			//��д��lineBuf��ʽ��
			sprintf(lineBuf, "%s = %s\n", pKey, pVal);
			strcat(tmpBuf, lineBuf);
			flag = 1;
		}
		else
		{
			strcat(tmpBuf, lineBuf);
		}
	}

	
	if (0 == flag) //�ļ���û��keyֵ
	{//��������ж�������key�������ļ���β׷�ӣ� "key = value"
		//sprintf(lineBuf, "%s = %s", pKey, pVal);	

		//����һ�����ļ�����Ѿ��ƶ�����β��
		//�����ʱ���ļ���д���ݣ��϶���׷�ӵ���β��
		//��ʽ����ʽд�ļ�
		fprintf(fp, "%s = %s\n", pKey, pVal);
	}
	else
	{	//�ر��ļ�
		//��д��д��ʽ���ļ�����д���ļ�д����
		if (fp != NULL)
		{
			fclose(fp);
			fp = NULL;
		}

		//д����ʽ���ļ����ļ��������򴴽�
		fp = fopen(fileName, "w+");
		if (fp == NULL)
		{
			perror("WriteCfgFile fopen");
			return -4;
		}

		//���ļ�д����
		fputs(tmpBuf, fp);
	}


	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}

	return  0;
}