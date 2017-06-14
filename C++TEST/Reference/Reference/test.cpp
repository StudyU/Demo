#include <iostream>
#include <string>

using namespace std;

string version(string &s1, const string &s2);
const string &version1(string &s1, const string &s2);
const string &version2(string &s1, const string &s2);

int main()
{
	string s;
	string result;
	string copy;

	cout << "Enter string:" << '\t';
	getline(cin, s);
	copy = s;

	result = version(s, "***");
	cout << "Reference:" << result << endl;
	cout << "before:" << copy << endl;

	result = version1(s, "$$$");
	cout << "Reference:" << result << endl;
	cout << "before:" << copy << endl;

	result = version2(s, "&&&");
	cout << "Reference:" << result << endl;
	cout << "before:" << copy << endl;
}

string version(string &s1, const string &s2)
{
	string temp;
	temp = s2 + s1 + s2;
	return temp;
}

const string &version1(string &s1, const string &s2)
{
	s1 = s2 + s1 + s2;

	return s1;
}

//����
const string &version2(string &s1, const string &s2)
{
	string temp;
	temp = s2 + s1 + s2;
//temp�����Ѿ��ͷ��ڴ�
	//���ؾֲ���������ʱ�����ĵ�ַ
	return temp;
}