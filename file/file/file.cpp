#include<iostream>
#include <fstream>

using namespace std;

//������ı�
int main()
{
	char automoblie[50];
	int year;
	double a_price;
	double b_price;

	ofstream outfile;
	//����file.txt�ļ�������Ѿ��д��ļ����ļ����������
	outfile.open("file.txt");

	cout << "Enter : ";
	cin.getline(automoblie, 50);
	cout << "Year: ";
	cin >> year;
	cout << "a_price: ";
	cin >> a_price;
	b_price = a_price * 0.913;

	//screen
	//fixed����֤�����Զ�����ʽ���ڣ���������ָ���ĸ�ʽ��ʾ��
	//precision(n) ����ʾС������Ϊnλ 
	//showpoint����֤С����Ĵ��ڣ���ʹ�Ǹ����ֲ�û��С�����֡�
	cout << fixed;
	cout.precision(2);
	cout.setf(ios_base::showpoint);
	cout << "Make and modle: " << automoblie <<endl;
	cout << "year: " << year <<endl;
	cout << "a_price:" << a_price <<endl;
	cout << "b_price:" << b_price <<endl;

	//file
	outfile<< fixed;
	outfile.precision(2);
	outfile.setf(ios_base::showpoint);
	outfile << "Make and Modle: " << automoblie << endl;
	outfile << "year: " << year <<endl;
	outfile << "a_price: " << a_price <<endl;
	outfile << "b_price: " << b_price <<endl;

	outfile.close();
}
/*
������Ҫǣ����ios�࣬�������ǹ���������ios��ǣ�fixed��showpoint��

���ñ�ǣ�����ʹ�� �Ա�ǵ�����Ϊ������ ��������setiosflags�������������У�������Ʊ����������֮�󣬲���֮��Ҫ���ֶηֽ����������������

fixed����֤�����Զ�����ʽ���ڣ���������ָ���ĸ�ʽ��ʾ��

showpoint����֤С����Ĵ��ڣ���ʹ�Ǹ����ֲ�û��С�����֡�

setprecision��������������Ϊ��������ʾ���־�ȷ�ȣ���С�����λ������

setw��������������Ϊ�����������ֶεĿ�ȣ��������ֿ��Ҷ��롣

���cout<<setiosflags(ios::fixed) ����д�� cout.setf(ios::fixed)

cout<<setiosflags(ios::showpoint) ����д�� cout.setf(ios::showpoint)

out<<setprecision(2) ����д�� cout.precision(2)

������һЩ�����Ŀ��ƺ�����:

dec �û���Ϊ10 �൱��"%d"

hex �û���Ϊ16 �൱��"%X"

oct �û���Ϊ8 �൱��"%o"

setfill(c) ������ַ�Ϊc

setprecision(n) ����ʾС������Ϊnλ

setw(n) �����Ϊn���ַ�

������Ʒ�����˼�Ǳ�֤������Ϊn���磺

cout<<setw(3)<<1<<setw(3)<<10<<setw(3)<<100; ������Ϊ

1 10100 ��Ĭ�����Ҷ��룩��������ȴ���3ʱ(<<1000)��setw(3)�������á�

setioflags(ios::fixed) �̶��ĸ�����ʾ

setioflags(ios::scientific) ָ����ʾ

setiosflags(ios::left) �����

setiosflags(ios::right) �Ҷ���

setiosflags(ios::skipws ����ǰ���հ�

setiosflags(ios::uppercase) 16��������д���

setiosflags(ios::lowercase) 16����Сд���

setiosflags(ios::showpoint) ǿ����ʾС����

setiosflags(ios::showpos) ǿ����ʾ���� 
*/