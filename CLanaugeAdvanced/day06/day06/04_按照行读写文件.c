#include <stdio.h>

#if(1)

void my_fputs(char* path)
{
	FILE* fp = NULL;

	// "w+", д����ʽ�򿪣�����ļ������ڣ��򴴽��� ����ļ����ڣ�������ݣ���д��
	fp = fopen(path, "w+");
	if (fp == NULL)
	{
		perror("my_fputs fopen");
		return;
	}

	// д�ļ�
	char* buf[] = {"aaaaaaa\n", "bbbbb\n", "cccc\n"};
	int n = sizeof(buf)/sizeof(buf[0]);
	for (int i = 0; i < n; i++)
	{
		int len = fputs(buf[i], fp);		// ����ֵΪ���ɹ�ʧ�ܣ��ɹ�Ϊ0��ʧ��Ϊ��0
		//printf("len = %d\n", len);
	}

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

void my_fgets(char* path)
{
	FILE* fp = NULL;

	// ��д��ʽ�򿪣�����ļ������ڣ���ʧ��
	fp = fopen(path, "r+");
	if (fp == NULL)
	{
		perror("my_fgets fopen");
	}

	char buf[100];
	// ������
	while (!feof(fp))		// �ж��ļ��Ƿ����
	{
		// sizeof(buf),Ϊ����ܶ������ַ����Ų���ֻ�ܷ�sizeof(buf)���������������ȡ������ʵ�ʴ�С���
		// ����ֵ���ɹ���ȡ�ļ�����
		// ��'\n' ���ȡ����'\n'��Ϊ���еı�ʶ
		// fgets()��ȡ��Ϻ��Զ����ַ���������
		char *p = fgets(buf, sizeof(buf), fp);
		// ��Ϊ������ \r \n ����bufû�н���������whileѭ��û�н�������ж����һ�ζ�����
		if (p != NULL)
		{
			printf("buf = %s\n", buf);
			//printf("%s\n", p);
		}
	}
	printf("\n");

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

int main()
{
	my_fputs("../04.txt");
	my_fgets("../04.txt");

	return 0;
}
#endif