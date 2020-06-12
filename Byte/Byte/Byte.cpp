#include <iostream>
#include <climits>
#include <string>
#include <windows.h>
using namespace std;

// 4个int压缩成一个int (-128  -- 127 之前的数值)
int util_compress_int4(int iUpHigh, int iUpLow, int iDownHigh, int iDownLow)
{
	//缩小4倍放至高16位
	int HighValue = ((iUpHigh << 24) & 0xFF000000) | ((iUpLow << 16) & 0x00FF0000);
	HighValue &= 0xFFFF0000;

	//低位设置(坐标缩小4倍)保存传送
	int LowValue = ((iDownHigh << 8) & 0x0000FF00) | (iDownLow & 0x000000FF);
	LowValue &= 0x0000FFFF;
	HighValue |= LowValue;

	return HighValue;
}

// 2个int压缩成一个int （-32768 -- 32767 之间的数值）
int util_compress_int2(int iHighValue, int iLowValue)
{
	int Value = ((iHighValue << 16) & 0xFFFF0000) | (iLowValue & 0x0000FFFF);
	return Value;
}

class NFGUID
{
public:
	uint64_t data1 = 0;
	uint64_t data2 = 0;
};

int main()
{
	NFGUID g1;
	_GUID*gg = (_GUID*)&g1;
	_GUID ggg;
	HRESULT hs = CoCreateGuid((_GUID*)&g1);
	HRESULT hs1 = CoCreateGuid(&ggg);
	if (hs != S_OK || hs1 != S_OK)
	{
		return 0;
	}

		//stdint.h 
	cout << "int is:" << sizeof(int) << " MaxNum is:" << INT_MAX << endl;
	cout << "short is:" << sizeof(short) << " MaxNum is:" << SHRT_MAX << endl;
	cout << "char is:" << sizeof(char) << " MaxNum is:" << CHAR_MAX << endl;
	cout << "long is:" << sizeof(long) << " MaxNum is:" << LONG_MAX << endl;
	cout << "float is:" << sizeof(float) << endl;
	cout << "double is:" << sizeof(double) << endl;
	cout << "wchar_t is:" << sizeof(wchar_t) << endl;
	cout << "size_t is:" << sizeof(size_t) << endl;
	cout << "string is:" << sizeof(string) << endl;
	cout << "char* is:" << sizeof(char*) <<endl;
	
	//float f = 2.2f;
	//double d = (double)f;

	//cout << "float: " << f << "\nDouble:" << d << endl;

	//f = 2.25f;
	//d = (double)f;
	//cout << "float1: " << f << "\nDouble1:" << d << endl;

	//cout << '$'<< endl;
	////cout.put('$');
	//float i = 10.0f / 3.0f;
	//double j = 10.0 / 3.0;
	////cout会删除结尾的零
	//cout << i << endl;
	//cout << 9.0 / 5 << endl;
	//cout.setf(ios_base::fixed, ios_base::floatfield);
	//cout << 9.0 / 5 << endl;
	//cout << j << endl;

	//int int4 = util_compress_int4(-1, 2, 3, 4);
	//int int2 = util_compress_int2(1, 2);
	//cout << "int4=" << int4 << endl
	//	<< "int2=" << int2;

	//int n = 2147483647;
	//int m = n * 2;
	//int i = n * 3;
	//cout << "n:" << n << "...m:" << m << "...i:" << i << endl;

	//unsigned int nn = 4294967295;
	//unsigned int mm = nn * 2;
	//unsigned int ii = nn * 3;
	//cout << "nn;" << nn << "...mm:" << mm << "...ii:" << ii << endl;

	system("pause");

	return 0;
}

