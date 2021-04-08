#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socketclient.h"

#if 0
int main(void)
{
	void* handle = NULL;
	int ret = 0;

	// ��ʼ������
	ret = socketclient_init(&handle);
	if (ret != 0)
	{
		printf("socketclient_init err:%d\n", ret);
		return ret;
	}

	// ������Ϣ
	char buf[100] = "abcdefghijklmnopqrstuvwxyz";
	ret = socketclient_send(handle, buf, strlen(buf));
	if (ret != 0)
	{
		printf("socketclient_send err:%d\n", ret);
		return ret;
	}
	printf("���ݷ��ͳɹ���\n");

	// ��������
	memset(buf, 0, sizeof(buf));

	int len = 0;
	ret = socketclient_recv(handle, buf, &len);
	if (ret != 0)
	{
		printf("socketclient_recv err:%d\n", ret);
		return ret;
	}
	printf("buf = %s, len = %d\n", buf, len);

	// �ͷ���Դ
	ret = socketclient_destory(handle);
	if (ret != 0)
	{
		printf("socketclient_destory err:%d\n", ret);
		return ret;
	}

	handle = NULL;

	printf("\n");
	return 0;
}
#endif // 0

int main()
{
	void* handle = NULL;
	int ret = 0;

	// ��ʼ������
	ret = socketclient_init2(&handle);
	if (ret != 0)
	{
		printf("socketclient_init2 err:%d\n", ret);
		return ret;
	}

	// ������Ϣ
	char buf[100] = "abcdefghijklmnopqrstuvwxyz";
	ret = socketclient_send2(handle, buf, strlen(buf));
	if (ret != 0)
	{
		printf("socketclient_send2 err:%d\n", ret);
		return ret;
	}
	printf("���ݷ��ͳɹ���\n");

	void* str = NULL;

	// ��������
	int len = 0;
	ret = socketclient_recv2(handle, &str, &len);	// str���ں����з���ռ�
	if (ret != 0)
	{
		printf("socketclient_recv2 err:%d\n", ret);
		return ret;
	}
	printf("buf = %s, len = %d\n", (char*)str, len);

	socketclient_free2(&str);

	// �ͷ���Դ
	ret = socketclient_destory2(&handle);
	if (ret != 0)
	{
		printf("socketclient_destory2 err:%d\n", ret);
		return ret;
	}

	return 0;
}