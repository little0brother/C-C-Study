#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  SIZE 1024 * 2 //ÿ�ζ�д2k����

void menu()
{
	printf("================================\n");
	printf("1 �����ļ�\n");
	printf("2 ����\n");
	printf("3 �˳�\n");
	printf("================================\n");
}

void myCopy()
{
	char rPath[256]; //Դ�ļ�
	char wPath[256]; //Ŀ���ļ�
	FILE *rFp = NULL;
	FILE *wFp = NULL;
	char buf[SIZE] = { 0 }; 
	int n = 0;

	printf("������Դ�ļ���");
	scanf("%s", rPath);

	printf("������Ŀ���ļ���");
	scanf("%s", wPath);

	if (strcmp(rPath, wPath) == 0)
	{
		printf("Դ�ļ���Ŀ���ļ�������ͬ\n");
		return;
	}

	//ֻ����ʽ��Դ�ļ�
	rFp = fopen(rPath, "rb");
	if (rFp == NULL)
	{
		perror("fopen rPath");
		return;
	}

	//ֻд��ʽ��Ŀ���ļ�
	wFp = fopen(wPath, "wb");
	if (wFp == NULL)
	{
		fclose(rFp);
		perror("fopen wFp");
		return;
	}

	do 
	{
		n = 0;
		//�����٣�д����
		n = fread(buf, sizeof(char), SIZE, rFp);
		printf("������%d\n", n);
		fwrite(buf, sizeof(char), n, wFp);

	} while (n > 0);
	printf("�������\n\n");

	fclose(rFp);
	fclose(wFp);
}

int main()
{
	

	int cmd;

	while (1)
	{
		menu();
		printf("cmd: ");
		scanf("%d", &cmd);

		switch (cmd)
		{
		case 1:
			myCopy();
			break;
		case 2:
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