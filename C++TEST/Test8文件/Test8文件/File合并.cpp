#include <fstream>
#include <iostream>
using namespace std;

//���ļ�2�е����ݺϲ����ļ�1��   
int main1()
{
	fstream file1("1.txt", ios_base::app);//��ios_base
	fstream file2("2.txt", ios_base::in);
	if (file1.is_open()&&file2.is_open())//is_open����
	{
		char buff[128];
		//������1.txt����������
		while (!file2.eof())
		{
			file2.getline(buff, 128);
			file1 << "\n";
			file1 << buff;
		}
	}
	else
	{
		cout << "�޷����ļ���" << endl;
	}
	file1.close();
	file2.close();

	return 0;
}
