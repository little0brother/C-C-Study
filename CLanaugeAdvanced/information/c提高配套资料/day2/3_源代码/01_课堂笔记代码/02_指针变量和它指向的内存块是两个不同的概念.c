#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *p = NULL; 
	char buf[] = "abcdef";

	printf("p1 = %d\n", p);
	//�ı�ָ�������ֵ
	p = buf; 
	printf("p2 = %d\n", p);

	//ָ���������ָ��ָ����ڴ���������ͬ�ĸ���
	p = p + 1; //�ı���ָ�������ֵ���ı���ָ���ָ��
	printf("p2 = %d\n", p);
	printf("buf = %s\n", buf);

	printf("*p = %c\n", *p);

	//�ı�ָ��ָ����ڴ棬������Ӱ�쵽ָ���ֵ
	printf("�ı�ָ��ָ����ڴ棬������Ӱ�쵽ָ���ֵ\n");
	buf[1] = '1';
	printf("p3 = %d\n", p);
	printf("buf2 = %s\n", buf);

	*p = 'm';
	printf("p4 = %d\n", p);
	printf("buf3 = %s\n", buf);

	//д�ڴ�ʱ��һ��Ҫȷ���ڴ��д
	char *buf2 = "sadgkdsjlgjlsdk"; //���ֳ��������ڴ治�ɸ�
	//buf2[2] = '1'; //err

	char buf3[] = "skgjkdsjgjds";
	buf3[1] = '1'; //ok

	char *p3 = NULL;
	//��p3ָ����ڴ����򿽱��ڴ�
	p3 = buf3;
	strcpy(p3, "1111"); //err

	printf("\n");
	system("pause");
	return 0;
}