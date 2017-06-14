#include <iostream>
//#include <string>
using namespace std;
const int mi = 5;
int main()
{
	/*struct student 
	{
		char Name[20];
		int Num;
		float Score;
		char Address[100];
	};

	student LI = { "LiHong", 1, 99.9, "ZhangShun_Road"};

	cout << LI.Name << " Address" << &LI.Name << endl;
	cout << LI.Num << " Address" << &LI.Num << endl;
	cout << LI.Score << " Address" << &LI.Score << endl;

	int val = 6;
	int ind = 4;

	cout << val << " Add:" << &val << endl;
	cout << ind << " Add:" << &ind << endl;

	int * pt = new int [10];
	*pt = 5;
	//
	pt[9] = 14;
	int coats[10];
	*(coats + 4) = 12;
	cout << "pt:" << pt << " *pt:" << *pt << " pt[0]:" << pt[0] << endl;
	pt[0] = 6;//对指针解除引用
	cout << "pt1:" << pt << " *pt1:" << *pt << " pt[0]:" << pt[0] << endl;
	cout << "pt[9]:" << pt[9] <<endl;


	char ch;
	int cnt = 0;
	cout << "Enter a string and '#' is end: \n";
	//字符之间没有原来的空格了
	//cin >> ch;
	//输入什么就是什么，保留空格之类特殊的字符
	cin.get(ch);
	while ( ch != '#' )
	{
		cout << ch;
		++cnt;
		//cin >> ch;
		cin.get(ch);
	}
	cout << endl << cnt << " characters read\n";
	

	//文件尾条件EOF
	char ch;
	int cnt = 0;
	cout << "Enter a string: \n";
	cin.get(ch);
	while ( cin.fail() == false )
	{
		cout << ch;
		++cnt;
		cin.get(ch);
	}
	cout << endl << cnt << " characters read\n";

	//文件尾条件EOF(-1)比较，字符没有-1值
	int ch;
	int cnt = 0;
	cout << "Enter a string: \n";
	while ( (ch = cin.get()) != EOF )
	{
		cout.put(char(ch));
		++cnt;
	}
	cout << endl << cnt << " characters read\n";
	*/	


	double fish[mi];
	cout << "Please enter the weights of your fish.\n";
	cout << "You may enter up to " << mi <<" fish <q to the end>.\n";

	cout << "fish #1: ";
	int i = 0;
	while ( i < mi && cin >> fish[i])
	{
		if ( ++i )
		{
			cout <<"fish #" << i+1 <<": ";
		}
	}
	double total = 0.0;
	for ( int j = 0; j < i; j++ )
	{
		total += fish[j];
	}

	if ( i == 0 )
	{
		cout << "You no fish\n";
	}
	else
	{
		cout << total / i << " = average weight of " << i << " fish\n";
	}

	cout << "Done.\n";
	return 0;
}