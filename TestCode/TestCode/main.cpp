//旧函数替换成 Security CRT functions 
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1

#include <iostream>
#include <complex>
#include <limits>
#include <algorithm>
#include <windows.h>
#include "TestCode.h"
#include "TestString.h"
using namespace std;

//类的静态成员变量必须先初始化再使用
//B* B::m_pThis = NULL;
int main()
{
	//TestString();
	//TestSizeofAndStrlen();
	//TestVector();
	//TestOperate();
	TestAlgorithm();
	//B* pB = new B;
	//B::m_pThis->testvirtual();
	//pB->teststatic();
	//pB->testvirtual();

	//char* n = "idhi1";
	//wchar_t* nn = L"idhi1";
	//size_t  HashValue1 = GetHashValue(n);
	//size_t  HashValue2 = GetHashValue(nn);
	//cout << "HashValue1:" << HashValue1 << "HashValue2:" << HashValue2 << endl;

	cout << "↑↑↑ TestCode!!!  ↑↑↑" << endl;
	system("pause");
	return 0;
}