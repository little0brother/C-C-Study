#include <stdio.h>
#include <stdlib.h>

#define SIZE 2*1024	// ÿ�ο���2k����

void meau()
{
	printf("=========================\n");
	printf("1.copy�ļ�\n");
	printf("2.����\n");
	printf("3.�˳�\n");
	printf("=========================\n");
}

void copyFile()
{
	char rpath[512] = { 0 };
	char wpath[512] = { 0 };

	printf("��������copy���ļ���:");
	scanf("%s", rpath);
	
	printf("������copy����ļ���:");
	scanf("%s", wpath);

	if (*rpath == *wpath)
	{
		printf("�ļ���������ͬ!\n");
		return;
	}

	FILE* rfp = NULL;
	FILE* wfp = NULL;

	rfp = fopen(rpath, "rb");
	if (rfp == NULL)
	{
		perror("rfp fopen");
		return;
	}

	wfp = fopen(wpath, "wb");
	if (wfp == NULL)
	{
		perror("wfp fopen");
		return;
	}

	int n = 0;
	char buf[SIZE] = { 0 };

	// ������д����
	// ÿ�ο���2k���ݣ�
	do
	{
		n = 0;

		// һ���ֽ�һ���ֽڶ���ÿ�ζ�2k
		// ������д����
		n = fread(buf, sizeof(char), SIZE, rfp);
		if (n > 0)
		{
			fwrite(buf, sizeof(char), n, wfp);
		}
		printf("����:%d\n", n);
	} while (n > 0);
	printf("�������");

	if (rfp != NULL)
	{
		fclose(rfp);
		rfp = NULL;
	}
	if (wfp != NULL)
	{
		fclose(wfp);
		wfp = NULL;
	}
}

int main()
{
	int cmd;

	while (1)
	{
		meau();
		printf("cmd:");
		scanf("%d", &cmd);

		switch (cmd)
		{
		case 1: copyFile(); break;
		case 2: system("cls"); break;
		case 3: exit(0);
		default:
			break;
		}
	}

	return 0;
}