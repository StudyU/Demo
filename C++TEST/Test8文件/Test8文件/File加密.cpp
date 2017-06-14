#include <iostream>
#include <fstream>
using namespace std;

/*
inputname	ԭ�ļ�·����
outputname	�����ļ�·����
pwd			����
*/

void encrypt(char *inputname, char *outputname, char *pwd)
{
	fstream inputfile(inputname, ios_base::in);
	if (!inputfile.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		inputfile.close();
		return;
	}
	fstream outputfile(outputname, ios_base::out);
	char buff[128];
	while (!inputfile.eof())
	{
		inputfile.getline(buff, 128);
		for (int i=0; i<128&&buff[i]!='\0'; i++)
		{
			buff[i] = buff[i]^*(pwd+i);
		}
		outputfile << buff << '\n';
	}
	cout << "������ɣ�" << endl;
	inputfile.close();
	outputfile.close();
	return;
}

int main()
{
	char sfile[30]; //�û�����Ҫ���ܵ��ļ���
	char cfile[30];
	char pwd[10];	//����
	cout << "������Դ�ļ����ƣ�\n";
	gets(sfile);
	cout << "���������룺\n";
	gets(pwd);
	cout << "��������ܺ���ļ�����\n";
	gets(cfile);
	encrypt(sfile,cfile,pwd);
}