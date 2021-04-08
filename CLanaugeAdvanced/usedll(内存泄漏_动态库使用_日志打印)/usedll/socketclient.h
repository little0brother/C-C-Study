// 头文件函数声明

// 防止头文件重复包含
// 1.#pragma once
//#pragma once
#ifndef _SOCKETCLIENT_H_
#define _SOCKETCLIENT_H_


// 2.兼容c++编译器
// 如果是c++编译器，按c标准编译
#ifdef __cplusplus
extern "C"
{

#endif

// 第一套接口

	// 初始化环境句柄
	int socketclient_init(void** handle);

	// 发送信息
	int socketclient_send(void* handle, void* buf, int len);

	// 接受信息
	int socketclient_recv(void* handle, void* buf, int *len);

	// 释放资源
	int socketclient_destory(void* handle);


// 第二套接口

	// 初始化环境句柄
	int socketclient_init2(void** handle);

	// 发送信息
	int socketclient_send2(void* handle, void* buf, int len);

	// 接受信息
	int socketclient_recv2(void* handle, void** buf, int* len);

	int socketclient_free2(void** buf);

	// 释放资源
	int socketclient_destory2(void** handle);


#ifdef __cplusplus
}

#endif

#endif // !_SOCKETCLIENT_H_