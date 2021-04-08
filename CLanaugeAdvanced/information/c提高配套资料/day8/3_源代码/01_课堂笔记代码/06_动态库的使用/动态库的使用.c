#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socketclient.h"

int main01(void)
{
	void *handle = NULL;
	int ret = 0;

	//��ʼ������
	ret = socketclient_init(&handle);
	if (ret != 0)
	{
		printf("socketclient_init err:%d\n", ret);
		system("pause");
		return ret;
	}

	//������Ϣ
	char buf[100] = "abcdefgdsagdsgsdg";
	ret = socketclient_send(handle, buf, strlen(buf));
	if (ret != 0)
	{
		printf("socketclient_send err:%d\n", ret);
		system("pause");
		return ret;
	}

	printf("���ݷ��ͳɹ�\n");

	memset(buf, 0, sizeof(buf));

	int len = 0;
	//��������
	ret = socketclient_recv(handle, buf, &len);
	if (ret != 0)
	{
		printf("socketclient_recv err:%d\n", ret);
		system("pause");
		return ret;
	}

	printf("buf = %s, len = %d\n", buf, len);


	//�ͷ���Դ
	ret = socketclient_destroy(handle);
	if (ret != 0)
	{
		printf("socketclient_destroy err:%d\n", ret);
		system("pause");
		return ret;
	}

	handle = NULL;

	printf("\n");
	system("pause");
	return 0;
}

int main(void)
{
	void *handle = NULL;
	int ret = 0;

	//��ʼ������
	ret = socketclient_init2(&handle);
	if (ret != 0)
	{
		printf("socketclient_init err:%d\n", ret);
		system("pause");
		return ret;
	}

	//������Ϣ
	char buf[100] = "abcdefgdsagdsgsdg";
	ret = socketclient_send2(handle, buf, strlen(buf));
	if (ret != 0)
	{
		printf("socketclient_send err:%d\n", ret);
		system("pause");
		return ret;
	}

	printf("���ݷ��ͳɹ�\n");

	void *str = NULL;

	int len = 0;
	//��������
	ret = socketclient_recv2(handle, &str, &len); //str���ں����ڲ�����ռ�
	if (ret != 0)
	{
		printf("socketclient_recv err:%d\n", ret);
		system("pause");
		return ret;
	}

	printf("buf = %s, len = %d\n", (char *)str, len);

	socketclient_free2(&str);


	//�ͷ���Դ
	ret = socketclient_destroy2(&handle);
	if (ret != 0)
	{
		printf("socketclient_destroy err:%d\n", ret);
		system("pause");
		return ret;
	}

	printf("\n");
	system("pause");
	return 0;
}