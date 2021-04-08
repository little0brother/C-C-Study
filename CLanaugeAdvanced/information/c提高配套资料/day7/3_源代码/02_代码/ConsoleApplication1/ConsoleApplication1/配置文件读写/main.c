#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cfg.h"

#define  CFGNAME "mycfg.ini"

void menu()
{
	printf("===========================\n");
	printf("1、读配置文件\n");
	printf("2、写配置文件\n");
	printf("3、清屏\n");
	printf("4、退出\n");
	printf("===========================\n");
}

void MyRead()
{
	char key[256] = { 0 };
	char value[1024] = { 0 };
	int len = 0;
	int ret = 0;

	printf("请输入key值：");
	scanf("%s", key);

	ret = ReadCfgFile(CFGNAME, key, value, &len);
	if (ret != 0)
	{
		printf("ReadCfgFile err:%d\n", ret);
		return;
	}

	printf("\n%s对应的value:%s, len = %d\n", key, value, len);

}

void MyWrite()
{
	char key[256] = { 0 };
	char value[1024] = { 0 };
	int ret = 0;

	printf("请输入key值：");
	scanf("%s", key);

	printf("请输入value值：");
	scanf("%s", value);

	ret = WriteCfgFile(CFGNAME, key, value, strlen(value));
	if (ret != 0)
	{
		printf("ReadCfgFile err:%d\n", ret);
		return;
	}

	printf("\n写入成功，输入的是：%s对应的value:%s, len = %d\n", key, value, strlen(value) );

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