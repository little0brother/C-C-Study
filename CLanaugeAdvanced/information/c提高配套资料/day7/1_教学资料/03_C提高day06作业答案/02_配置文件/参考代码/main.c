#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//<>: 从系统目录找
//"": 从当前目录找，没有找到再从系统目录中寻找
#include "cfg.h" 

#define  CFGNAME "./mycfg.ini"

void MyMenu()
{
	printf("================================\n");
	printf("1 写配置文件\n");
	printf("2 读配置文件\n");
	printf("3 清屏\n");
	printf("4 退出\n");
	printf("================================\n");
}

void MyWrite()
{
	int ret = 0;
	char key[512] = { 0 };
	char value[512] = { 0 };
	
	printf("\n请输入key: ");
	scanf("%s", key);

	printf("\n请输入value: ");
	scanf("%s", value);

	ret = WriteCfgFile(CFGNAME, key, value, strlen(value));
	if (ret != 0) //失败
	{
		printf("WriteCfgFile err: %d\n", ret);
		return;
	}

	printf("\n写入的内容：%s = %s\n\n", key, value);

}

void MyRead()
{
	int ret = 0;
	char key[512] = { 0 };
	char value[512] = { 0 };
	int len = 0;

	printf("\n请输入key: ");
	scanf("%s", key);

	ret = ReadCfgFile(CFGNAME, key, value, &len);
	if (ret != 0) //失败
	{
		printf("ReadCfgFile err: %d\n", ret);
		return;
	}

	printf("\n %s对应的value为：%s, 长度为：%d\n\n", key, value, len);
}

int main()
{
	int cmd;

	while (1)
	{
		MyMenu();
		printf("cmd:");
		scanf("%d", &cmd);

		switch (cmd)
		{
		case 1:
			MyWrite();
			break;
		case 2:
			MyRead();
			break;
		case 3:
			system("cls");
			break;
		default:
			exit(0);
		}

	}

	printf("\n");
	system("pause");
	return 0;
}