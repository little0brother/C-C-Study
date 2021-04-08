#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cfg.h"

#define  CFGNAME "mycfg.ini"

void menu()
{
	printf("===========================\n");
	printf("1���������ļ�\n");
	printf("2��д�����ļ�\n");
	printf("3������\n");
	printf("4���˳�\n");
	printf("===========================\n");
}

void MyRead()
{
	char key[256] = { 0 };
	char value[1024] = { 0 };
	int len = 0;
	int ret = 0;

	printf("������keyֵ��");
	scanf("%s", key);

	ret = ReadCfgFile(CFGNAME, key, value, &len);
	if (ret != 0)
	{
		printf("ReadCfgFile err:%d\n", ret);
		return;
	}

	printf("\n%s��Ӧ��value:%s, len = %d\n", key, value, len);

}

void MyWrite()
{
	char key[256] = { 0 };
	char value[1024] = { 0 };
	int ret = 0;

	printf("������keyֵ��");
	scanf("%s", key);

	printf("������valueֵ��");
	scanf("%s", value);

	ret = WriteCfgFile(CFGNAME, key, value, strlen(value));
	if (ret != 0)
	{
		printf("ReadCfgFile err:%d\n", ret);
		return;
	}

	printf("\nд��ɹ���������ǣ�%s��Ӧ��value:%s, len = %d\n", key, value, strlen(value) );

}


int main(void)
{
	int cmd;
	while (1)
	{
		menu();
		printf("cmd:");
		scanf("%d", &cmd);


		switch (cmd)
		{
		case 1:
			MyRead();
			break;
		case 2:
			MyWrite();
			break;
		case 3:
			system("cls");
			break;
		default:
			exit(0);
			break;
		}


	}

	printf("\n");
	system("pause");
	return 0;
}