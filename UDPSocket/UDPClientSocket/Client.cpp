#include<winsock2.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<WS2tcpip.h>
using namespace std;
#pragma comment(lib,"ws2_32.lib")
/*
�ڳ���ʼ���ͷ�ļ�:
#include<WS2tcpip.h>
���ڣ� inet_ntoa(addr2.sin_addr);
����ȼ��滻Ϊ
char sendBuf[20] = {'\0'};
inet_ntop(AF_INET,(void*)&addr2.sin_addr,sendBuf,16);
���ڣ� addr.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
�ȼ��滻Ϊ�� inet_pton(AF_INET, "127.0.0.1", (void*)&addr.sin_addr.S_un.S_addr);
*/

# define BUFFER_SIZE  1024    //��������С

int main()
{
	SOCKET sock_Client; //�ͻ�������ͨ�ŵ�Socket
	WSADATA WSAData;
	char  receBuf[BUFFER_SIZE]; //�������ݵĻ�����
	char  sendBuf[BUFFER_SIZE]; //�������ݵĻ�����

	if (WSAStartup(MAKEWORD(2, 2), &WSAData) != 0) {
		printf("��ʼ��ʧ��!");
		return -1;
	}    //��ʼ��
	sock_Client = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);//�����ͻ�������ͨ�ŵ�Socket
	SOCKADDR_IN addr_server;   //�������ĵ�ַ���ݽṹ
	addr_server.sin_family = AF_INET;
	addr_server.sin_port = htons(1200);//�˿ں�Ϊ4567
									   //addr_server.sin_addr.s_addr = inet_addr("127.0.0.1");   //127.0.0.1Ϊ������IP��ַ
	addr_server.sin_addr.s_addr = inet_pton(AF_INET, "127.0.0.1", (void*)&addr_server.sin_addr.s_addr);
	SOCKADDR_IN sock;
	int len = sizeof(sock);
	while (true) {
		cout << "������Ҫ���͵�����:";
		cin >> sendBuf;
		int code = sendto(sock_Client, sendBuf, strlen(sendBuf), 0, (SOCKADDR*)&addr_server, sizeof(SOCKADDR));
		if (code == -1)
		{
			cout << "����ʧ��code��" << code << endl;
		}
		//int last=recv(sock_Client, receBuf, strlen(receBuf), 0);              // (����recv��recvfrom������)
		int last = recvfrom(sock_Client, receBuf, strlen(receBuf), 0, (SOCKADDR*)&sock, &len);
		if (last>0) {
			receBuf[last] = '\0';      //���ַ������һ��'\0'����ʾ�����ˡ���Ȼ���������
			if (strcmp(receBuf, "bye") == 0) {
				cout << "                               ������������������..." << endl;//������������byeʱ���ر�socket
				closesocket(sock_Client);
				break;
			}
			else {
				printf("���յ����ݣ�%s\n", receBuf);
			}

		}

	}
	closesocket(sock_Client);
	WSACleanup();


	return 0;
}