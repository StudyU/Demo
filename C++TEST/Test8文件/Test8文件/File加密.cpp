#include <iostream>
#include <fstream>
using namespace std;

/*
inputname	原文件路径名
outputname	加密文件路径名
pwd			密码
*/

void encrypt(char *inputname, char *outputname, char *pwd)
{
	fstream inputfile(inputname, ios_base::in);
	if (!inputfile.is_open())
	{
		cout << "文件打开失败！" << endl;
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
	cout << "加密完成！" << endl;
	inputfile.close();
	outputfile.close();
	return;
}

int main()
{
	char sfile[30]; //用户输入要加密的文件名
	char cfile[30];
	char pwd[10];	//密码
	cout << "请输入源文件名称：\n";
	gets(sfile);
	cout << "请输入密码：\n";
	gets(pwd);
	cout << "请输入加密后的文件名：\n";
	gets(cfile);
	encrypt(sfile,cfile,pwd);
}