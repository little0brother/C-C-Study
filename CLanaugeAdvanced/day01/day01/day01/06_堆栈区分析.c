#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �洢��ջ��
char* get_str()
{
	/* �˺���������ϣ�str�ռ��Զ����գ�str�Ŀռ�����δ֪���п��ܻ�������֮ǰ������ �п��������� */

	char str[] = "abcdefgh";	// ����ڶ�ջ������ΪΪ�������Բ�����ָ���ϵ��ֻ�и�ֵ��ϵ

	return str;
}

// �洢�ڶ���
char* get_str2()
{
	char* temp = (char*)malloc(100);		// �����ڴ�ռ佫temp->������ڴ�ռ�
	if (temp == NULL)
	{
		return NULL;
	}

	strcpy(temp, "adfadffda");			// ���ַ�����ȫ���������ݸ��Ƶ�������ڴ�ռ��У������з��ص�ַ����
	return temp;
}

int main(void)
{
	char buf[128] = { 0 };


	/* ���ݴ���ջ��ԭ����� */
	strcpy(buf, get_str());	  // ��get_str�еķ���ֵ����buf����Ϊget_str���ص�Ϊstr�����ָ�룬
							  //����strΪ�ֲ���ʱ������������ϣ��ڴ������ͷţ����Է��ص�ַ�������ݲ�ȷ��
	printf("buf = %s\n");		 // ��ӡ����Ϊ���룬��Ϊget_str�е�str���ڶ�ջ����Ϊ�ֲ�������������ϻ��Զ��ͷ�

	char* p = NULL;				// �˹���������ԭ����ͬ
	p = get_str();
	printf("p = %s\n", p);


	/* ���ݴ洢�ڶ���ԭ����� ��ͨ��malloc�����ڴ�ռ䣬��ȷ���ڴ治���Զ��ͷţ�*/
	char* q = NULL;
	q = get_str2();
	if (p != NULL)
	{
		printf("q = %s\n", q);

		free(q);			// �ͷ��ڴ�ռ�
		q = NULL;
	}


	printf("\n");
	return 0;
}