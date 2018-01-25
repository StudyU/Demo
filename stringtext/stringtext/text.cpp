#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

const int NUM = 5;

void display(const string arr[], int n);

int SafeSprint(char* buff, size_t byte_size, const char* format, ...);

int main()
{
	//string list[NUM];
	//cout << "Enter your favorite " << NUM << " girls!\n";

	//for (int i = 0; i < NUM; i++)
	//{
	//	cout << i+1 << ": ";
	//	getline(cin, list[i]);
	//}

	//cout << "Your List:\n";
	//display(list, SIZE);

	char buff[32];
	int nCnt = SafeSprint(buff, 32, "%s", "ngjuhfiusfifgahdfagawiuehwogdaidasdaaashdasu");

	cout << "char sizeof:" << nCnt << "buff sizeof:" << sizeof(buff) << "buff strlen:"<< strlen(buff) <<" buff:" << buff << endl;

	for (size_t i = 0; i < 32; i++)
	{
		cout << buff[i] << endl;
	}

	cout << int(buff[31]) << endl;
	system("pause");
	return 0;
}

void display(const string arr[], int n)
{
	for ( int i = 0; i < n; i++ )
	{
		cout << i+1 << ": " << arr[i] << endl;
	}
}

int SafeSprint(char* buff, size_t byte_size, const char* format, ...)
{
	if (byte_size <= 1)
	{
		return 0;
	}
	va_list varList;
	__crt_va_start(varList, format);
	int res = vsnprintf(buff, byte_size, format, varList);
	__crt_va_end(varList);

	// 此处理并不需要，vsnprintf已经对最后一位进行了处理
	//if ((size_t)res > byte_size)
	//{
	//	buff[byte_size - 1] = 0;
	//	res = byte_size;
	//}

	return res;
}