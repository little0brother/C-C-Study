#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//<>: ��ϵͳĿ¼��
//"": �ӵ�ǰĿ¼�ң�û���ҵ��ٴ�ϵͳĿ¼��Ѱ��
#include "cfg.h" 

#define  CFGNAME "./mycfg.ini"

void MyMenu()
{
	printf("================================\n");
	printf("1 д�����ļ�\n");
	printf("2 �������ļ�\n");
	printf("3 ����\n");
	printf("4 �˳�\n");
	printf("================================\n");
}

void MyWrite()
{
	int ret = 0;
	char key[512] = { 0 };
	char value[512] = { 0 };
	
	printf("\n������key: ");
	scanf("%s", key);

	printf("\n������value: ");
	scanf("%s", value);

	ret = WriteCfgFile(CFGNAME, key, value, strlen(value));
	if (ret != 0) //ʧ��
	{
		printf("WriteCfgFile err: %d\n", ret);
		return;
	}

	printf("\nд������ݣ�%s = %s\n\n", key, value);

}

void MyRead()
{
	int ret = 0;
	char key[512] = { 0 };
	char value[512] = { 0 };
	int len = 0;

	printf("\n������key: ");
	scanf("%s", key);

	ret = ReadCfgFile(CFGNAME, key, value, &len);
	if (ret != 0) //ʧ��
	{
		printf("ReadCfgFile err: %d\n", ret);
		return;
	}

	printf("\n %s��Ӧ��valueΪ��%s, ����Ϊ��%d\n\n", key, value, len);
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