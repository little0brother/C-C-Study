/*************/
/* �ַ���д�� */
/*************/

#include <stdio.h>

#define LEN 10

int main6()
{
	FILE* fp;
	char buf[LEN], ch;

	if (!(fp = fopen("test.txt", "at+")))
	{
		printf("can not open file !");
		exit(0);
	}

	printf("Please input string to file: ");
	fgets(buf, LEN, stdin);			// ����scanf����Ϊ %s�����ַ���ʱ �����ո񡢻��лس���ֹͣ����
									// stdin Ϊ�������뻺����
	fputs(buf, fp);

	rewind(fp);  // ���ļ�ָ������ָ�����ļ���ͷ��

	ch = fgetc(fp);
	while (ch != EOF)
	{
		putchar(ch);
		ch = fgetc(fp);
	}

	fclose(fp);

	return 0;
}