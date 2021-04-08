#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 函数的实现

typedef struct SockerHandle
{
	char ip[64];		// ip
	unsigned int port;  // 端口

	void* buf;
	int len;

}SockerHandle;

// 第一套接口

// 初始化环境句柄
int socketclient_init(void** handle)
{
	if (handle == NULL)
	{
		return -1;
	}

	SockerHandle* hd = NULL;
	hd = (SockerHandle*)malloc(sizeof(SockerHandle));
	if (hd == NULL)
	{
		return -2;
	}

	memset(hd, 0, sizeof(SockerHandle)); // 初始化为0, 在接下来的赋值中如果没有给结尾写 '/0', 不会导致字符串没有结束符

	// 结构体成员变量赋值
	strcpy(hd->ip, "255.255.255.255");
	hd->port = 8888;
	hd->buf = NULL;
	hd->len = 0;

	// 间接赋值
	*handle = (void*)hd;


	return 0;
}

// 发送信息
int socketclient_send(void* handle, void* buf, int len)
{
	if (handle == NULL || buf == NULL)
	{
		return -1;
	}

	SockerHandle* hd = (SockerHandle*)handle;

	if (hd->buf != NULL)	// 先把上一次分配的空间释放
	{
		free(hd->buf);
		hd->buf = NULL;
	}

	// 给结构体buf分配空间
	hd->buf = (char*)malloc(len);
	if (hd->buf == NULL)
	{
		return -2;
	}

	// memcpy 内存拷贝，不会因为字符串的内容结束字符串
	memcpy(hd->buf, buf, len);
	hd->len = len;

	return 0;
}

// 接收信息
int socketclient_recv(void* handle, void* buf, int* len)
{
	if (handle == NULL || buf == NULL)
	{
		return -1;
	}

	SockerHandle* hd = (SockerHandle*)handle;
	
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

// 释放资源
int socketclient_destory(void* handle)
{
	if (handle == NULL)
	{
		return -1;
	}

	// 释放资源必须要进行类型转换，否则无法释放void类型
	SockerHandle* hd = (SockerHandle*)handle;

	if (hd->buf != NULL)
	{
		free(hd->buf);
		hd->buf == NULL;
	}

	if (hd != NULL)
	{
		free(hd);
		hd = NULL;
	}

	return 0;
}


// 第二套接口

// 初始化环境句柄
int socketclient_init2(void** handle)
{
	return socketclient_init(handle);
}

// 发送信息
int socketclient_send2(void* handle, void* buf, int len)
{
	return socketclient_send(handle, buf, len);
}

// 接受信息
int socketclient_recv2(void* handle, void** buf, int* len)
{
	if (handle == NULL || buf == NULL)
	{
		return -1;
	}

	SockerHandle* hd = (SockerHandle*)handle;

	if (hd->buf != NULL)
	{
		char* tmp = NULL;
		tmp = (char*)malloc(hd->len + 1);
		if (tmp == NULL)
		{
			return -3;
		}
		memset(tmp, 0, hd->len + 1);

		memcpy(tmp, hd->buf, hd->len);
		// hd->buf 没有当作字符串处理，没有0结束符
		//strcpy(tmp, (char*)hd->buf);

		strncpy(tmp, (char*)hd->buf, hd->len);

		// 间接赋值
		*buf = (void*)tmp;
		*len = hd->len;
	}
	else
	{
		return -2;
	}

	return 0;
}

int socketclient_free2(void** buf)
{
	if (buf == NULL)
	{
		return -1;
	}

	void* tmp = *buf;

	if (tmp != NULL)
	{
		free(tmp);
		*buf = NULL;
	}

	return 0;
}

// 释放资源
int socketclient_destory2(void** handle)
{
	int ret = socketclient_destory(*handle);
	if (ret != 0)
	{
		return ret;
	}

	*handle = NULL;

	return 0;
}