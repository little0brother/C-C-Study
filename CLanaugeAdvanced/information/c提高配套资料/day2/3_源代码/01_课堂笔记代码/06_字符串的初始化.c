#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*c����û���ַ������ͣ�ͨ���ַ�����ģ��
  C�����ַ��������ַ���\0��, ����0
*/
int main01(void)
{
	//��ָ������, û��0���������ж��ٸ�Ԫ�ؾ��ж೤
	char buf[] = { 'a', 'b', 'c' };
	printf("buf = %s\n", buf);

	//ָ�����ȣ�����û�и�ֵ��Ԫ�أ��Զ���0
	char buf2[100] = { 'a', 'b', 'c' };
	printf("buf2 = %s\n", buf2);

	//����Ԫ�ظ�ֵΪ0
	char buf3[100] = { 0 };

	//char buf4[2] = { '1', '2', '3' };//����Խ��

	char buf5[50] = { '1', 'a', 'b', '0', '7' };
	printf("buf5 = %s\n", buf5);

	char buf6[50] = { '1', 'a', 'b', 0, '7' };
	printf("buf6 = %s\n", buf6);

	char buf7[50] = { '1', 'a', 'b', '\0', '7' };
	printf("buf7 = %s\n", buf7);


	//ʹ���ַ�����ʼ��������
	char buf8[] = "agjdslgjlsdjg";
	//strlen: ���ַ������ȣ�����������0���ַ�'\0'
	//sizeof�������鳤�ȣ���������0���ַ�'\0'
	printf("strlen = %d, sizeof = %d\n", strlen(buf8), sizeof(buf8));

	char buf9[100] = "agjdslgjlsdjg";
	printf("strlen = %d, sizeof = %d\n", strlen(buf9), sizeof(buf9));

	printf("test");
	//\012�൱��\n
	char str[] = "\0129";
	printf("%s\n", str);
	

	printf("\n");
	system("pause");
	return 0;
}

int main(void)
{
	char buf[] = "algjdlksajgldksjg";
	int i = 0;
	int n = strlen(buf);
	char *p = NULL;

	//[]��ʽ
	for (i = 0; i < n; i++)
	{
		printf("%c", buf[i]);
	}
	printf("\n");

	//ָ�뷽��
	//�������֣�������Ԫ�ص�ַ
	p = buf;
	for (i = 0; i < n; i++)
	{
		printf("%c", p[i]);
	}
	printf("\n");

	for (i = 0; i < n; i++)
	{
		printf("%c", *(p+i) );
	}
	printf("\n");

	for (i = 0; i < n; i++)
	{
		printf("%c", *(buf+i) );
	}
	printf("\n");

	//buf��p��ȫ�ȼ���
	//p++;
	//buf++;
	//bufֻ��һ�������������޸�


	printf("\n");
	system("pause");
	return 0;
}