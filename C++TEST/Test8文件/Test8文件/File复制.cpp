#include <iostream>
#include <fstream>
using namespace std;

int main2()
{
	cout << "������Դ�ļ���·����\n";
	char filename[30];
	cin >> filename;
	fstream file(filename, ios_base::in);
	if (file.is_open())
	{
		cout << "�����뱣���ļ���·����\n";
		cin >> filename;
		fstream file_copy(filename, ios_base::app);//����׷��
		char buff[128];
		//���и����ļ�����
		while (!file.eof())
		{
			file.getline(buff, 128);
			file_copy << buff << '\n';
		}
		cout << "������ɣ�" << endl;
		file_copy.close();
	}
	else
		cout << "�ļ��޷��򿪣�" << endl;
	file.close();
	return 0;
}