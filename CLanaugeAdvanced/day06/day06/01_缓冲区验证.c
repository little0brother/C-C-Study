#include <stdio.h>

/*
* �����ļ��ڱ�����ɺ� 
* ���û�ж��ļ����� fclose()�����򲻻��������ɣ������ڹرս��̺����������
*/

int main()
{
	char buf[] = "this is a test\n";

	FILE* fp = fopen("./test.txt", "w+");

	fputs(buf, fp);
	fflush(fp);		// ˢ�»�����
	fclose(fp);

	printf("\n");
	return 0;
}