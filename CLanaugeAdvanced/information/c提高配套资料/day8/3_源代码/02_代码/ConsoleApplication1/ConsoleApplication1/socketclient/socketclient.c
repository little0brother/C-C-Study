#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//������ʵ��

typedef struct SocketHandle
{
	char ip[100];	//ip
	unsigned int port;	//�˿�

	void *buf;
	int len;

}SocketHandle;

//��ʼ������
int socketclient_init(void **handle)
{

	if (handle == NULL)
	{
		return -1;
	}

	SocketHandle *hd = NULL;
	hd = (SocketHandle *)malloc(sizeof(SocketHandle));
	if (hd == NULL)
	{
		return -2;
	}

	memset(hd, 0, sizeof(SocketHandle)); //��ʼ��Ϊ0


	//�ṹ���Ա������ֵ
	strcpy(hd->ip, "255.255.255.255");
	hd->port = 8888;
	hd->buf = NULL;
	hd->len = 0;

	//��Ӹ�ֵ����ָ������������
	*handle = (void *)hd;

	return 0;
}

//������Ϣ
int socketclient_send(void *handle, void *buf, int len)
{
	if (handle == NULL || buf == NULL)
	{
		return -1;
	}

	SocketHandle *hd = (SocketHandle *)handle;

	if (hd->buf != NULL) //�Ȱ���һ�η���Ŀռ��ͷ�
	{
		free(hd->buf);
		hd->buf = NULL;
	}

	//���ṹ��buf����ռ�
	hd->buf = (char *)malloc(len);
	if (hd->buf == NULL)
	{
		return -2;
	}

	//memcpy
	memcpy(hd->buf, buf, len);
	hd->len = len;

	return 0;
}

//������Ϣ
int socketclient_recv(void *handle, void *buf, int *len)
{
	if (handle == NULL || buf == NULL)
	{
		return -1;
	}

	SocketHandle *hd = (SocketHandle *)handle;

	if (hd->buf != NULL)
	{
		memcpy(buf, hd->buf, hd->len);
		*len = hd->len;
	}
	else
	{
		return -2;
	}

	return 0;
}

//�ͷ���Դ
int socketclient_destroy(void *handle)
{
	if (handle == NULL)
	{
		return -1;
	}

	SocketHandle *hd = (SocketHandle *)handle;

	if (hd->buf != NULL)
	{
		free(hd->buf);
		hd->buf = NULL;
	}

	if (hd != NULL)
	{
		free(hd);
		hd = NULL;
	}


	return 0;
}

//��ʼ������
int socketclient_init2(void **handle)
{
	return socketclient_init(handle);
}

//������Ϣ
int socketclient_send2(void *handle, void *buf, int len)
{
	return socketclient_send(handle, buf, len);
}

//������Ϣ
int socketclient_recv2(void *handle, void **buf, int *len)
{

	if (handle == NULL || buf == NULL)
	{
		return -1;
	}

	SocketHandle *hd = (SocketHandle *)handle;

	if (hd->buf != NULL)
	{
		char *tmp = NULL;
		tmp = (char *)malloc(hd->len + 1);
		if (tmp == NULL)
		{
			return -3;
		}
		memset(tmp, 0, hd->len + 1);
		//memcpy(tmp, hd->buf, hd->len);
		//hd->bufû�е����ַ�������û��0��������
		//strcpy(tmp, (char *)hd->buf);
		strncpy(tmp, (char*)hd->buf, hd->len);

		//��Ӹ�ֵ
		*buf = (void *)tmp;
		*len = hd->len;
	}
	else
	{
		return -2;
	}

	return 0;
}

int socketclient_free2(void **buf)
{

	if (buf == NULL)
	{
		return -1;
	}

	void *tmp = *buf;
	if (tmp != NULL)
	{
		free(tmp);
		*buf = NULL;
	}

	return 0;
}

//�ͷ���Դ
int socketclient_destroy2(void **handle)
{
	int ret = socketclient_destroy(*handle);
	if (ret != 0)
	{
		return ret;
	}

	*handle = NULL;

	return 0;
}