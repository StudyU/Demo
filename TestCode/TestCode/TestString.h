#pragma once
#ifndef  _TEST_STRING_H_
#define _TEST_STRING_H_

#include <iostream>
#include <string.h>
using namespace std;

// �ַ�����д
const char* StringUpper(char* str)
{
	// �����ַ���Сд
	//string sInfo = "do better!!!";
	//for (char cWord : sInfo)
	//{
	//	cWord = toupper(cWord);
	//	cout << "Every Word is:" << cWord << endl;
	//}

	// �ַ�����Сд
	//size_t n = size(str);
	//string sUpper;
	//sUpper.resize(n);
	//transform(str.begin(), str.end(), sUpper.begin(), ::toupper);
	//cout << "ToUpper:" << sUpper << endl;
	//string sLower;
	//transform(str.begin(), str.end(), str.begin(), ::tolower);
	//cout << "ToLower:" << str << endl;

	//_ strupr��Ϊ��д_strlwr��ΪСд ֻת��s�г��ֵ�Сд��ĸ�����ı������ַ�������ָ��s��ָ��
	//ֻ�ܲ����ַ����飬�����ܲ���ָ���ַ�������Ϊָ��ָ����ַ�������Ϊ���������ھ�̬�洢���ģ��������ܱ��޸�
	//�ַ�������һ�����飬ÿ��Ԫ�ص�ֵ�����Ըı䡣���ַ���ָ��ָ�����һ�������ַ�������������ڳ���ľ�̬��������һ������Ͳ��ܸı䡣��������Ҫ������
	int n = strlen(str) + 1;
	char* str1 = new char[n];
	strcpy(str1, str);
	string str2;
	str2.resize(n);
	str2 = _strupr(str1);//תmain�궨��

	delete[] str1;
	
	return str2.c_str();
}

// �ַ���Сд
char* StringLower(char* str)
{
	char* str1 = _strlwr(str);//תmain�궨��
	
	return str1;
}

// ���Դ�С
/*
strlen��������ַ����ĳ���,ֻ����char*���������ұ�������''/0''��β�ģ�
sizeof������Ǳ���ʹ�õ��ڴ��С����������洢�����ݸı�,����������'\0'
�ַ�����size()���������ַ����ĳ���,������������'\0'
*/
void TestSizeofAndStrlen()
{
	char *str1 = "absde";
	int32_t a = 111;
	int64_t b = 1111111111111111111;
	char str2[] = "absde";
	char str3[8] = { 'a', };
	char str4[8] = { 'a','b','s','e','f','g','h','j' };

	//cout << "sizeof(str1)=" << sizeof(str1) << endl;
	//cout << "sizeof(str2)=" << sizeof(str2) << endl;
	//cout << "sizeof(str3)=" << sizeof(str3) << endl;
	//cout << "sizeof(str4)=" << sizeof(str4) << endl;
	//cout << "strlen(str1)=" << strlen(str1) << endl;
	//cout << "strlen(str2)=" << strlen(str2) << endl;
	//cout << "strlen(str3)=" << strlen(str3) << endl;
	//cout << "strlen(str4)=" << strlen(str4) << endl;
	//cout << "size(str1)=" << size(*str1) << endl;
	//cout << "size(str2)=" << size(str2) << endl;
	//cout << "size(str3)=" << size(str3) << endl;
	//cout << "size(str4)=" << size(str4) << endl;

	cout << "size(str3)=" << sizeof(a) << endl;
	cout << "size(str4)=" << sizeof(b) << endl;
}












void TestString()
{
	const char* str = StringUpper("fsdD");
	cout << "str:" << str << endl;

}





#endif // ! _TEST_STRING_H_
