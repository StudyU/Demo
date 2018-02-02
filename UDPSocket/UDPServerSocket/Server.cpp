#include <stdio.h>
#include <winsock2.h>
#include <iostream>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
using namespace std;
#define BUFF_SIZE 1024
int main()
{
	// 定义
	char recv_Buff[BUFF_SIZE];
	char Response[] = "";

	// 初始化
	WSADATA wsadata;
	/*
	WSAStartup必须是应用程序或DLL调用的第一个Windows Sockets函数。它允许应用程序或DLL指明Windows Sockets API的版本号及获得特定Windows Sockets实现的细节
	MAKEWORD(2, 2)声明调用不同的Winsock版本。例如MAKEWORD(2,2)就是调用2.2版
	*/
	if (0 != WSAStartup(MAKEWORD(2, 2), &wsadata))
	{
		cout << "初始化失败!" << endl;
		return 0;
	}

	// 创建服务器socket
	/*
	domain参数1:协议族(family代表TCP/IP协议族)决定了socket的地址类型，AF_INET为ipv4(32位)与端口号(16位)的组合
	type参数2:Socket的类型,主要区分流式TCP和数据包UDP
	protocol参数3:协议,主要TCP传输协议额，UDP传输协议等
	type和protocol不可随意组合，protocol为0时会自动选择type对应的默认协议
	*/
	SOCKET ServerSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (INVALID_SOCKET == ServerSocket)
	{
		cout << "创建Socket失败!" << endl;
		return 0;
	}

	// 绑定
	/*
	sockaddr_in地址信息
	htons将主机的无符号短整形数转换成网络字节顺序
	INADDR_ANY所有地址,任意地址
	*/
	sockaddr_in socket_address;
	socket_address.sin_family = AF_INET;//协议族
	socket_address.sin_port = htons(1200);// 端口号
	socket_address.sin_addr.s_addr = INADDR_ANY;//存储IP地址，使用in_addr这个数据结构;本地地址"127.0.0.1"
	if (SOCKET_ERROR == bind(ServerSocket, (sockaddr*)&socket_address, sizeof(socket_address)))//可以省略该函数，系统会自动绑定 
	{
		cout << "绑定失败!" << endl;
		return 0;
	}

	// 接收
	sockaddr_in socket_client;
	int fromLen = sizeof(socket_client);
	while (true)
	{
		int last = recvfrom(ServerSocket, recv_Buff, BUFF_SIZE, 0, (sockaddr*)&socket_client, &fromLen);
		if (last>0)
		{      //判断接收到的数据是否为空
			recv_Buff[last] = '\0';//给字符数组加一个'\0'，表示结束了。不然输出有乱码
			if (strcmp(recv_Buff, "bye") == 0)
			{
				cout << "                             客户端不跟我聊天了..." << endl;
				closesocket(ServerSocket);
				return 0;
			}
			else {
				char sendBuf[20] = { '\0' };
				printf("接收到数据（%s）：%s\n", inet_ntop(AF_INET, (void*)&socket_client.sin_addr, sendBuf, 16), recv_Buff);
			}
		}
		cout << "回复客户端消息:";
		cin >> Response; //给客户端回复消息
		sendto(ServerSocket, Response, strlen(Response), 0, (SOCKADDR*)&socket_client, sizeof(SOCKADDR));
	}

	closesocket(ServerSocket);

	WSACleanup();

	return 0;
}