#include <iostream>
using namespace std;
int c_in_str(const char *str, char ch);//const限定符
char * string1(char ch, int val);

int main()
{
	char str1[11] = "adhdh0dffu";//参数越界
	char *str2 = "dnfud0fdfh";

	int num1 = c_in_str(str1, 'd');
	int num2 = c_in_str(str2, '0');

	cout << num1 << " 'd' in str1:" << str1 << endl;
	cout << num2 << " '0' in str2:" << str2 << endl;

	char *pstr = string1('&', 5);
	cout << pstr << endl;
	//输出之后再释放
	delete[] pstr;

	pstr = string1('+', 20);
	cout << pstr << "DONE" << pstr << endl;
	delete[] pstr;



	/*
	char ch;
	int ct1, ct2;
	ct1 = ct2 = 0;

	while ((ch = cin.get()) != '$')
	{
		cout << ch;
		ct1++;

		if ( ch == '$' )
		{
			ct2++;
		}
		cout << ch;
	}

	cout << "ct1= " << ct1 << "ct2= " << ct2 << "\n";
		*/

	return 0;

}
int c_in_str(const char *str, char ch)
{
	int num = 0;

	
	while (*str)
	{
		if ( *str == ch )
		{
			num++;
		}

		str++;
	}
	return num;
}
char * string1(char ch, int val)
{
	char *str1 = new char[val+1];
	str1[val] = '\0';

	//数组
	while (val-- > 0)
	{
		str1[val] = ch;
	}
	return str1;
}