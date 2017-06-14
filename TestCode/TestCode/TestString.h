#pragma once
#ifndef  _TEST_STRING_H_
#define _TEST_STRING_H_

#include <iostream>
#include <string.h>
using namespace std;

// 字符串大写
const char* StringUpper(char* str)
{
	// 单个字符大小写
	//string sInfo = "do better!!!";
	//for (char cWord : sInfo)
	//{
	//	cWord = toupper(cWord);
	//	cout << "Every Word is:" << cWord << endl;
	//}

	// 字符串大小写
	//size_t n = size(str);
	//string sUpper;
	//sUpper.resize(n);
	//transform(str.begin(), str.end(), sUpper.begin(), ::toupper);
	//cout << "ToUpper:" << sUpper << endl;
	//string sLower;
	//transform(str.begin(), str.end(), str.begin(), ::tolower);
	//cout << "ToLower:" << str << endl;

	//_ strupr改为大写_strlwr改为小写 只转换s中出现的小写字母，不改变其它字符。返回指向s的指针
	//只能操作字符数组，而不能操作指针字符串，因为指针指向的字符串是作为常量保存在静态存储区的，常量不能被修改
	//字符数组是一个数组，每个元素的值都可以改变。而字符串指针指向的是一个常量字符串，它被存放在程序的静态数据区，一旦定义就不能改变。这是最重要的区别
	int n = strlen(str) + 1;
	char* str1 = new char[n];
	strcpy(str1, str);
	string str2;
	str2.resize(n);
	str2 = _strupr(str1);//转main宏定义

	delete[] str1;
	
	return str2.c_str();
}

// 字符串小写
char* StringLower(char* str)
{
	char* str1 = _strlwr(str);//转main宏定义
	
	return str1;
}

// 测试大小
/*
strlen计算的是字符串的长度,只能用char*做参数，且必须是以''/0''结尾的，
sizeof计算的是变量使用的内存大小，不受里面存储的内容改变,包括结束符'\0'
字符串的size()函数返回字符串的长度,不包括结束符'\0'
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
