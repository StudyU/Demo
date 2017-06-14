#include <iostream>
#include <fstream>
using namespace std;

int main2()
{
	cout << "请输入源文件的路径：\n";
	char filename[30];
	cin >> filename;
	fstream file(filename, ios_base::in);
	if (file.is_open())
	{
		cout << "请输入保存文件的路径：\n";
		cin >> filename;
		fstream file_copy(filename, ios_base::app);//复制追加
		char buff[128];
		//逐行复制文件内容
		while (!file.eof())
		{
			file.getline(buff, 128);
			file_copy << buff << '\n';
		}
		cout << "复制完成！" << endl;
		file_copy.close();
	}
	else
		cout << "文件无法打开！" << endl;
	file.close();
	return 0;
}