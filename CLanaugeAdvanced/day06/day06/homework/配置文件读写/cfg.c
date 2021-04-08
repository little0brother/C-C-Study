#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1024*8 

int trimSpace(char* inbuf, char* outbuf)
{
	if (inbuf == NULL || outbuf == NULL)
	{
		return -1;
	}

	char* p = inbuf;
	char* buf = outbuf;

	// �����ַ���vlaue������յ�
	int begin = 0;
	int end = strlen(inbuf) - 1;
	int n = 0;

	// ��Ϊ��ֵ���м���пո�����Ҫȥ���ո�
	while (isspace(inbuf[begin]) && (inbuf[begin] != NULL))
	{
		begin++;
	}

	while (isspace(inbuf[end]) && end > 0)
	{
		end--;
	}

	// ����ַ���Ϊ0 ��ô�ַ���������
	if (end == 0)
	{
		return -2;
	}


	// ��¼�ַ�������
	n = end - begin + 1;

	// ���ַ���������vbuf����ͨ���βη�����������
	strncpy(outbuf, inbuf + begin, n);
	outbuf[n] = 0;

	return 0;
}


int ReadCfgFile(char* file, char* key, char* value, int* len)
{
	if (file == NULL || key == NULL || value == NULL || len == NULL)
	{
		return -1;
	}

	FILE* fp = NULL;

	char lineBuf[1024] = { 0 };
	char* p = NULL;

	int flag = 0; // 0����û���ҵ�key
	int ret = 0;

	// ���ļ�
	fp = fopen(file, "r+");
	if (fp == NULL)
	{
		ret = -2;
		goto End;
	}

	while (1)
	{
		// ��ȡ1��
		if (fgets(lineBuf, sizeof(lineBuf), fp) == NULL)
		{
			break;
		}

		// lineBuf = "k1 = abc";
		p = strstr(lineBuf, key);
		if (p == NULL)
		{
			continue; // ��������ѭ��
		}

		// �����������
		// "k1 = abc" -> " = abc"
		p = p + strlen(key);

		// ���� = ������� = ������value
		p = strstr(p, "=");
		if (p == NULL)
		{
			continue;
		}

		// �����������
		// " = abc" -> " abc"
		p = p + strlen("=");

		// ��ȡ�ǿ��ַ���
		ret = trimSpace(p, value);
		if (ret == 0) // �ɹ�
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
		fp = NULL;
	}

	if (flag == 0)
	{
		ret = -3;
		printf("û��%s��Ӧ��value\n", key);
	}

	return ret;
}


int WriteCfgFile(char* file, char* key, char* value, int len)
{
	if (file == NULL || key == NULL || value == NULL)
	{
		return -1;
	}

	FILE* fp = NULL;

	char lineBuf[1024] = { 0 };	
	char buf[SIZE] = { 0 };
	char* p = NULL;

	int flag = 0; // 0����û���ҵ�key
	int ret = 0;

	// ��д ����+��
	fp = fopen(file, "r+");
	if (fp == NULL)		// ��ʧ�ܣ��п����������ļ�û�д���
	{
		// ���������ļ�
		fp = fopen(file, "w+");
		{
			if (fp == NULL)
			{
				ret = -2;
				goto End;
			}
		}
	}

	// ��ȡ�ļ���С
	// ����ƶ�����β
	fseek(fp, 0, SEEK_END);

	long size = ftell(fp);
	if (size >= SIZE)
	{
		ret = -3;
		printf("�ļ�����8k,��֧��");
		goto End;
	}

	// ���ص��ļ�ͷ
	rewind(fp);

	while (1)
	{
		// �����н��ļ����ж�ȡ���ַ����У����ַ������в���
		if (fgets(lineBuf, sizeof(lineBuf), fp) == NULL)
		{
			break;
		}

		// ÿһ���Ƿ����key���������key�����û���Ҫ�޸ĵ�keyֵд�뵽�ַ����У�ͨ���·����������ַ����е����ݸ��ǵ�֮ǰ�������ļ�
		if (strstr(lineBuf, key) != NULL)	// ����key
		{
			flag = 1;	// 1�����ļ����Ѿ���key
			sprintf(lineBuf, "%s = %s\n", key, value);

			strcat(buf, lineBuf);
		}
		else
		{
			strcat(buf, lineBuf);
		}
	}

	// �����⣬�������
	if (flag == 0)	// û��key
	{
		// �ļ���꣬�Ѿ��ƶ����ļ���β, ֱ�����ļ�β����׷�Ӳ���
		fprintf(fp, "%s = %s\n", key, value);
	}
	else    // ��key
	{
		// �ر��ļ�
		if (fp == NULL)
		{
			fclose(fp);
			fp = NULL;
		}

		// ����д���ݣ����ղ��޸ĺ��ļ���ȡ���ַ����У�����ȫ�������滻����
		fp = fopen(file, "w+");
		if (fp == NULL)
		{
			ret = -4;
			goto End;
		}

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