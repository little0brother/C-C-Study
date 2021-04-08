// IpInfo.cpp : Defines the entry point for the console application.
//

#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "ws2_32.lib")

#include "stdafx.h"
#include <winsock2.h>
#include <time.h>
#include <iostream>
#include <iomanip>

using namespace std;

class IpInfo
{
private:
	WSADATA			wsaData;
	SOCKET			sock;
	SOCKADDR_IN		sock_in;

	int				flags = 0;
	char			server[32] = "www.ip138.com";
	unsigned short	port = 80;

	bool InitSocket(char* pServer, unsigned short port);

public:
	IpInfo();
	~IpInfo();

	int post(char* in, char* out, int& OutSize);
};

IpInfo::IpInfo()
{
	if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		return;

	InitSocket(server, port);
}

IpInfo::~IpInfo()
{
	if(flags & 1)
		closesocket(sock);
	WSACleanup();
}

bool IpInfo::InitSocket(char* pServer, unsigned short port)
{
	struct hostent *ht;
	int	TimeOut = 1000;

	if((sock = socket(AF_INET, SOCK_STREAM, 0)) == SOCKET_ERROR)
		return false;

	//设置接收超时
	if(setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO,
		(char*)&TimeOut, sizeof(TimeOut)) == SOCKET_ERROR)
		return false;

	sock_in.sin_family = AF_INET;
	sock_in.sin_port = htons(port);

	//域名转换为IP
	if((ht = gethostbyname(pServer)) == NULL)
	{
		//域名解析
		int iError = WSAGetLastError();
		closesocket(sock);
		return false;
	}
	else
		memcpy(&sock_in.sin_addr.s_addr, ht->h_addr_list[0], ht->h_length);

	//连接服务器，建立一次会话
	if(connect(sock, (SOCKADDR*)&sock_in, sizeof(SOCKADDR_IN)) == SOCKET_ERROR)
	{
		//初始化错误，关闭套接字，释放资源
		int iError = WSAGetLastError();
		closesocket(sock);
		return false;
	}
	flags |= 1;
	return true;
}

int IpInfo::post(char* in, char* out, int& OutSize)
{
	// 套接字已关闭或尚未创建
	if((flags & 1) == 0)
		return -1;

	char* pBuf = new char[256 * 1024];
	sprintf(pBuf, "GET /ips1388.asp?ip=%s&action=2 HTTP/1.1\r\n"
				  "Accept: text/html, application/xhtml+xml, image/jxr, */*\r\n"
				  "Accept-Language: zh-CN\r\n"
				  "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) \r\n"
				  "Accept-Encoding: gzip, deflate\r\n"
				  "Host: www.ip138.com\r\n"
				  "Connection: Keep-Alive\r\n\r\n", in);

	int n = send(sock, pBuf, strlen(pBuf), 0);
	n = recv(sock, pBuf, 255 * 1024, 0);
	if(n > 0)
	{
		char* pStart, *pEnd;
		int i, m, nleft;

		if( (pEnd = strstr(pBuf, "\r\n\r\n")) &&
			(pStart = strstr(pBuf, "Content-Length: ")))
		{
			// 剩余未接收数据量
			m = atoi(&pStart[16]);
			nleft = pEnd - pBuf + 4 + m - n;

			// 将数据接受完整
			while(nleft > 0)
			{
				m = recv(sock, &pBuf[n], nleft, 0);
				n += m;
				nleft -= m;
			}
	
			if( (pStart = strstr(pBuf, "<li>本站数据：")) &&
				(pEnd = strstr(pStart, "</li>")))
			{
				pStart += strlen("<li>本站数据：");
				for(i = 0; i < pEnd - pStart && i < OutSize; i++)
					out[i] = pStart[i];

				out[i] = '\0';
				OutSize = i;
			}
		}
	}
	else
	{
		int err = WSAGetLastError();
		sprintf(out, "err: %d", err);
		OutSize = strlen(out);
	}

	delete []pBuf;
	return OutSize;
}

int main()
{
	char ip[32], city[256];
	int len;
	IpInfo ipInfo;

	cout << setiosflags(ios::left);
	srand(clock());

	for(int i = 0; i < 256; i++)
	{
		sprintf(ip, "%d.%d.%d.%d", 
			rand() % 256, rand() % 256, rand() % 256, rand() % 256);

		len = 255;
		city[0] = '\0';

		ipInfo.post(ip, city, len);
		cout << setw(8) << i + 1 << setw(20) << ip << city << endl;
	}

	system("pause");
    return 0;
}