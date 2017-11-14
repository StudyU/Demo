//旧函数替换成 Security CRT functions 
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1

#include <cstdio>
#include <ctime>
#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;

// http://lib.csdn.net/article/39/46461?knId=1161
const int MAXN = 10000000;
int numbers[MAXN];

void cin_file()
{
	ofstream outfile;
	//创建file.txt文件，如果已经有此文件则将文件中内容清空
	outfile.open("data.txt");
	for (int i = 0; i < MAXN; i++)
	{
		outfile << i;
	}

	outfile.close();
}
// 32.347 30.425
void scanf_read()
{
	freopen("data.txt", "r", stdin);
	for (int i = 0; i<MAXN; i++)
		scanf("%d", &numbers[i]);
}

// 4.774	4.718
void cin_read()
{
	freopen("data.txt", "r", stdin);
	for (int i = 0; i < MAXN; i++)
	{
		cin >> numbers[i];
	}		
}

// 4.942 4.771 4.973
// std::ios::sync_with_stdio(false);，这样就可以取消cin于stdin的同步了
void cin_read_nosync()
{
	freopen("data.txt", "r", stdin);
	std::ios::sync_with_stdio(false);
	for (int i = 0; i<MAXN; i++)
		std::cin >> numbers[i];
}

void analyse(char *buf, int len)
{
	int i;
	numbers[i = 0] = 0;
	for (char *p = buf; *p && p - buf < len; p++)
	{
		if (*p == ' ')
			numbers[++i] = 0;
		else
			numbers[i] = numbers[i] * 10 + *p - '0';
	}
}

// 0.268 0.256
void fread_analyse()
{
	FILE* fp = freopen("data.txt", "rb", stdin);

	int len = 0;
	fseek(fp, 0, SEEK_END);
	len = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	char* buf = new char[len + 1];
	fread(buf, 1, len, fp);
	buf[len] = '\0';
	analyse(buf, len);
	// 释放
	fclose(fp);
	delete[] buf;
}

int main()
{
	int start = clock();
	fread_analyse();
	printf("use time: %.3lf\n", double(clock() - start) / CLOCKS_PER_SEC);

	system("pause");
}