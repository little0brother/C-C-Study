//2. ʵ�������ļ���д��д���ܣ�key = value��ʽ����ִ�г���ο���02_�����ļ���
//��ʾ��
//a) ѭ����ÿһ��, ������а���key�����key��value�޸�
//b) ��������ж�������key�������ļ���β׷�ӣ� "key = value"
//c) �ļ���С���ܳ���8k
//c) �ο���fgets(), strstr(), sprintf(), strcat(), fprintf(), fputs(), fseek(), ftell(), rewind()


/******************************** д����δ��� *******************************/

#include <stdio.h>
#include <string.h>

#define INIPATH "./homework/02_cfg/mycfg.ini"

static int flag = -1;	// ��־�Ƿ��ҵ���key

void menu()
{
	printf("===============================\n");
	printf("1.д�����ļ�\n");
	printf("2.�������ļ�\n");
	printf("3.����\n");
	printf("4.�˳�\n");
	printf("===============================\n");
}

int trimSpace(char* pval, char* val)
{
	if (pval == NULL || val == NULL)
	{
		return -1;
	}

	int begin = 0;
	int end = strlen(pval) - 1;
	int valLen = 0;

	// ��ͷ��ģ�ͣ�ȥ��value���ߵĿո�
	while (isspace(pval[begin]) && pval[begin] != 0)
	{
		begin++;
	}

	while (isspace(pval[end]) && pval[end] != 0)
	{
		end--;
	}

	if (end < 0)
	{
		return -2;
	}

	// ����� value �ĳ��ȣ������Ƶ�ָ���ռ���
	valLen = end - begin + 1;
	strncpy(val, pval + begin, valLen);

	return 0;
}

int AlterCfgFile(char* key, char* alval)
{


	return 0;
}

// �����Ƿ��м�ֵ
int SearchKey(char* path, char* key, char** val)
{
	flag = -1;

	if (path == NULL || key == NULL)
	{
		return -1;
	}

	FILE* fp = fopen(path, "r");
	if (fp == NULL)
	{
		perror("[SearchKey] fopen:");
		return -2;
	}

	char fileBuf[512] = { 0 };
	char* tmp = NULL;
	char* pval = NULL;

	// ���û�������ļ���β��һֱ����
	while (!feof(fp))
	{
		// ���ж�ȡ�ļ�
		tmp = fgets(fileBuf, sizeof(fileBuf), fp);

		// ����key
		pval = strstr(fileBuf, key);
		if (pval != NULL)
		{
			pval = strchr(tmp, '=');

			// ����ҵ� = ������ж�Ӧvalue����valueͨ������ָ�봫��
			if (pval != NULL)
			{
				pval++;
				*val = (char*)malloc(strlen(pval) * sizeof(char) + 1);
				strcpy(*val, pval);

				flag = 1;
				break;
			}
			else 
			{
				continue;
			}
		}
		else
		{
			flag = 0;
		}
	}

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

void wirteIni()
{
	char key[512]  = { 0 };
	char val[512]  = { 0 };
	char pval[256] = { 0 };
	int  vallen    = 0;

	printf("������key:");
	scanf("%s", key);
	printf("������value:");
	scanf("%s", val);

	vallen = (int)strlen(val);

	// ����key
	int ret = SearchKey(INIPATH, key, pval/* ��ʵ������ */);
	if (ret != 0)
	{
		printf("[wirteIni] searchKey err:%d\n", ret);
	}

	if (flag == 1)
	{
		//printf("flag = %d\n", flag);
		AlterCfgFile(key, pval);
	}
}

// ԭ���ʵ��
#if(0)
int ReadCfgFile(char* path, char* key, char* val, int* len)
{
	if (path == NULL || key == NULL || val == NULL || len == NULL)
	{
		return -1;
	}

	FILE* fp = NULL;
	fp = fopen(path, "r");
	if (fp == NULL)
	{
		perror("ReadCfgFile fopen");
		return -2;
	}

	char buf[1024] = { 0 };
	char* tmp = NULL;
	char* pval = NULL;

	while (!feof(fp))
	{
		// �����ж�ȡ�����ļ����ݶ�ȡ�� tmp�У� ͨ��strstr�ж��ļ� key�Ƿ����
		// fgets()��ȡһ��֮�󣬻Ὣָ���ƶ�����һ��
		tmp = fgets(buf, sizeof(buf), fp);

		pval = strstr(tmp, key);
		if (pval != NULL)
		{
			// Ѱ��key����Ӧ��valueֵ
			pval = strchr(pval, '=');
			if (pval == NULL)
			{
				continue;
			}
			pval++;

			flag = 1;
			// Ϊд�����Ĳ��Ҽ�ֵ���ж� lenΪwriteIni����ļ����ȣ������Ϊ�������writeIni���õĺ�������ֻ���в��ң�������vlaue�ĸı�
			if (flag == 1 && *len != 0)
			{
				break;
			}

			int ret = trimSpace(pval, val);
			if (ret != 0)
			{
				printf("trimSpace err: %d\n", ret);
				return -3;
			}

			*len = strlen(val);
			
			break;
		}
		// ��־�Ƿ��ҵ�key ���δ�ҵ� key �򲻻� ͨ��break ����ѭ��
		flag = 0;
	}

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}

	return 0;
}
#endif

void readIni()
{
	char key[512] = { 0 };
	char val[512] = { 0 };
	char* pval = NULL;

	printf("������key:");
	scanf("%s", key);

	// ����keyֵ���ҡ�����ҵ���־λΪ1�����δ�ҵ���־λΪ0���������Ϊ-1
	int ret = SearchKey(INIPATH, key, &pval);
	if (ret != 0)
	{
		printf("[redIni] SearchKey err: %d\n", ret);
	}

	if (flag == 1 && pval != NULL)
	{
		trimSpace(pval, val);
		if (val != NULL)
		{
			printf("\n %s��Ӧ��valueΪ:%s, ����Ϊ��%d\n", key, val, strlen(val));
		}
	}
	else if (flag == 0 || pval == NULL)
	{
		printf("δ���ҵ�%s\n", key);
	}
}

int main()
{
	int choose = 0;

	while (1)
	{
		menu();
		printf("cmd:");
		scanf("%d", &choose);

		switch (choose)
		{
		case 1:	wirteIni(); break;
		case 2: readIni();  break;
		case 3: system("cls"); break;
		case 4:
		default: exit(0);
		}
	}

	return 0;
}