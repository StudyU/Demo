#include <stdio.h>
#include <winsock2.h>
#include <iostream>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
using namespace std;
#define BUFF_SIZE 1024
int main()
{
	// ����
	char recv_Buff[BUFF_SIZE];
	char Response[] = "";

	// ��ʼ��
	WSADATA wsadata;
	/*
	WSAStartup������Ӧ�ó����DLL���õĵ�һ��Windows Sockets������������Ӧ�ó����DLLָ��Windows Sockets API�İ汾�ż�����ض�Windows Socketsʵ�ֵ�ϸ��
	MAKEWORD(2, 2)�������ò�ͬ��Winsock�汾������MAKEWORD(2,2)���ǵ���2.2��
	*/
	if (0 != WSAStartup(MAKEWORD(2, 2), &wsadata))
	{
		cout << "��ʼ��ʧ��!" << endl;
		return 0;
	}

	// ����������socket
	/*
	domain����1:Э����(family����TCP/IPЭ����)������socket�ĵ�ַ���ͣ�AF_INETΪipv4(32λ)��˿ں�(16λ)�����
	type����2:Socket������,��Ҫ������ʽTCP�����ݰ�UDP
	protocol����3:Э��,��ҪTCP����Э��UDP����Э���
	type��protocol����������ϣ�protocolΪ0ʱ���Զ�ѡ��type��Ӧ��Ĭ��Э��
	*/
	SOCKET ServerSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (INVALID_SOCKET == ServerSocket)
	{
		cout << "����Socketʧ��!" << endl;
		return 0;
	}

	// ��
	/*
	sockaddr_in��ַ��Ϣ
	htons���������޷��Ŷ�������ת���������ֽ�˳��
	INADDR_ANY���е�ַ,�����ַ
	*/
	sockaddr_in socket_address;
	socket_address.sin_family = AF_INET;//Э����
	socket_address.sin_port = htons(1200);// �˿ں�
	socket_address.sin_addr.s_addr = INADDR_ANY;//�洢IP��ַ��ʹ��in_addr������ݽṹ;���ص�ַ"127.0.0.1"
	if (SOCKET_ERROR == bind(ServerSocket, (sockaddr*)&socket_address, sizeof(socket_address)))//����ʡ�Ըú�����ϵͳ���Զ��� 
	{
		cout << "��ʧ��!" << endl;
		return 0;
	}

	// ����
	sockaddr_in socket_client;
	int fromLen = sizeof(socket_client);
	while (true)
	{
		int last = recvfrom(ServerSocket, recv_Buff, BUFF_SIZE, 0, (sockaddr*)&socket_client, &fromLen);
		if (last>0)
		{      //�жϽ��յ��������Ƿ�Ϊ��
			recv_Buff[last] = '\0';//���ַ������һ��'\0'����ʾ�����ˡ���Ȼ���������
			if (strcmp(recv_Buff, "bye") == 0)
			{
				cout << "                             �ͻ��˲�����������..." << endl;
				closesocket(ServerSocket);
				return 0;
			}
			else {
				char sendBuf[20] = { '\0' };
				printf("���յ����ݣ�%s����%s\n", inet_ntop(AF_INET, (void*)&socket_client.sin_addr, sendBuf, 16), recv_Buff);
			}
		}
		cout << "�ظ��ͻ�����Ϣ:";
		cin >> Response; //���ͻ��˻ظ���Ϣ
		sendto(ServerSocket, Response, strlen(Response), 0, (SOCKADDR*)&socket_client, sizeof(SOCKADDR));
	}

	closesocket(ServerSocket);

	WSACleanup();

	return 0;
}