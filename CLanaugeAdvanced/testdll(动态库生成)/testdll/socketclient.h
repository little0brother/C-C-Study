// ͷ�ļ���������

// ��ֹͷ�ļ��ظ�����
// 1.#pragma once
//#pragma once
#ifndef _SOCKETCLIENT_H_
#define _SOCKETCLIENT_H_


// 2.����c++������
// �����c++����������c��׼����
#ifdef __cplusplus
extern "C"
{

#endif

// ��һ�׽ӿ�

	// ��ʼ���������
	int socketclient_init(void** handle);

	// ������Ϣ
	int socketclient_send(void* handle, void* buf, int len);

	// ������Ϣ
	int socketclient_recv(void* handle, void* buf, int *len);

	// �ͷ���Դ
	int socketclient_destory(void* handle);


// �ڶ��׽ӿ�

	// ��ʼ���������
	int socketclient_init2(void** handle);

	// ������Ϣ
	int socketclient_send2(void* handle, void* buf, int len);

	// ������Ϣ
	int socketclient_recv2(void* handle, void** buf, int* len);

	int socketclient_free2(void** buf);

	// �ͷ���Դ
	int socketclient_destory2(void** handle);


#ifdef __cplusplus
}

#endif

#endif // !_SOCKETCLIENT_H_