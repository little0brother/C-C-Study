/************/
/*  �ļ�д�� */
/************/

#include <stdio.h>
#include <stdlib.h>

int main2()
{
	FILE* fp;
	char ch, filename[20];

	printf("Please input the filename you want to write: ");
	scanf("%s", filename);

	if (!(fp = fopen("filename", "wt+")))
	{
		printf("Can not open file\n");
		exit(0);
	}

	printf("Please input the sentences you want to write: ");
	ch = getchar(); // ���ַ�����scanf���ȡ�հ��ַ�,'\r\n' ���ַ� �������������Զ�����1�����ٻس�ʵ�ʾ��Ƕ��뵽������2���ַ�getchar()һ����һ���ַ� Ҳ��Ҫ��2�β���ƥ��
	ch = getchar();
	while (ch != EOF) // EOF = ctrl+z
	{
		fputc(ch, fp);

		ch = getchar();
	}
	fclose(fp);

	return 0;
}