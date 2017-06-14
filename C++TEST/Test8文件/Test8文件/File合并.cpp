#include <fstream>
#include <iostream>
using namespace std;

//将文件2中的内容合并到文件1中   
int main1()
{
	fstream file1("1.txt", ios_base::app);//用ios_base
	fstream file2("2.txt", ios_base::in);
	if (file1.is_open()&&file2.is_open())//is_open更好
	{
		char buff[128];
		//逐行向1.txt中输入数据
		while (!file2.eof())
		{
			file2.getline(buff, 128);
			file1 << "\n";
			file1 << buff;
		}
	}
	else
	{
		cout << "无法打开文件！" << endl;
	}
	file1.close();
	file2.close();

	return 0;
}
