#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ������ʵ��

typedef struct SockerHandle
{
	char ip[64];		// ip
	unsigned int port;  // �˿�

	void* buf;
	int len;

}SockerHandle;

// ��һ�׽ӿ�

// ��ʼ���������
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

	memset(hd, 0, sizeof(SockerHandle)); // ��ʼ��Ϊ0, �ڽ������ĸ�ֵ�����û�и���βд '/0', ���ᵼ���ַ���û�н�����

	// �ṹ���Ա������ֵ
	strcpy(hd->ip, "255.255.255.255");
	hd->port = 8888;
	hd->buf = NULL;
	hd->len = 0;

	// ��Ӹ�ֵ
	*handle = (void*)hd;


	return 0;
}

// ������Ϣ
int socketclient_send(void* handle, void* buf, int len)
{
	if (handle == NULL || buf == NULL)
	{
		return -1;
	}

	SockerHandle* hd = (SockerHandle*)handle;

	if (hd->buf != NULL)	// �Ȱ���һ�η���Ŀռ��ͷ�
	{
		free(hd->buf);
		hd->buf = NULL;
	}

	// ���ṹ��buf����ռ�
	hd->buf = (char*)malloc(len);
	if (hd->buf == NULL)
	{
		return -2;
	}

	// memcpy �ڴ濽����������Ϊ�ַ��������ݽ����ַ���
	memcpy(hd->buf, buf, len);
	hd->len = len;

	return 0;
}

// ������Ϣ
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

// �ͷ���Դ
int socketclient_destory(void* handle)
{
	if (handle == NULL)
	{
		return -1;
	}

	// �ͷ���Դ����Ҫ��������ת���������޷��ͷ�void����
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


// �ڶ��׽ӿ�

// ��ʼ���������
int socketclient_init2(void** handle)
{
	return socketclient_init(handle);
}

// ������Ϣ
int socketclient_send2(void* handle, void* buf, int len)
{
	return socketclient_send(handle, buf, len);
}

// ������Ϣ
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
		// hd->buf û�е����ַ�������û��0������
		//strcpy(tmp, (char*)hd->buf);

		strncpy(tmp, (char*)hd->buf, hd->len);

		// ��Ӹ�ֵ
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

// �ͷ���Դ
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