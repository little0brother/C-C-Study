#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//函数的实现

typedef struct SocketHandle
{
	char ip[100];	//ip
	unsigned int port;	//端口

	void *buf;
	int len;

}SocketHandle;

//初始化环境
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

	memset(hd, 0, sizeof(SocketHandle)); //初始化为0


	//结构体成员变量赋值
	strcpy(hd->ip, "255.255.255.255");
	hd->port = 8888;
	hd->buf = NULL;
	hd->len = 0;

	//间接赋值，是指针存在最大意义
	*handle = (void *)hd;

	return 0;
}

//发送信息
int socketclient_send(void *handle, void *buf, int len)
{
	if (handle == NULL || buf == NULL)
	{
		return -1;
	}

	SocketHandle *hd = (SocketHandle *)handle;

	if (hd->buf != NULL) //先把上一次分配的空间释放
	{
		free(hd->buf);
		hd->buf = NULL;
	}

	//给结构体buf分配空间
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

//接受信息
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

//释放资源
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

//初始化环境
int socketclient_init2(void **handle)
{
	return socketclient_init(handle);
}

//发送信息
int socketclient_send2(void *handle, void *buf, int len)
{
	return socketclient_send(handle, buf, len);
}

//接受信息
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
		//hd->buf没有当做字符串处理，没有0结束符，
		//strcpy(tmp, (char *)hd->buf);
		strncpy(tmp, (char*)hd->buf, hd->len);

		//间接赋值
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

//释放资源
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