#include<iostream>
#include <fstream>

using namespace std;

//输出到文本
int main()
{
	char automoblie[50];
	int year;
	double a_price;
	double b_price;

	ofstream outfile;
	//创建file.txt文件，如果已经有此文件则将文件中内容清空
	outfile.open("file.txt");

	cout << "Enter : ";
	cin.getline(automoblie, 50);
	cout << "Year: ";
	cin >> year;
	cout << "a_price: ";
	cin >> a_price;
	b_price = a_price * 0.913;

	//screen
	//fixed：保证数字以定点形式存在，而不会以指数的格式显示。
	//precision(n) 设显示小数精度为n位 
	//showpoint：保证小数点的存在，即使那个数字并没有小数部分。
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
这里主要牵扯到ios类，这里我们关心这两个ios标记：fixed和showpoint。

设置标记，可以使用 以标记的名称为参数的 操作程序setiosflags。其中在括号中，标记名称必须跟在类名之后，并且之间要有字段分解运算符（：：）；

fixed：保证数字以定点形式存在，而不会以指数的格式显示。

showpoint：保证小数点的存在，即使那个数字并没有小数部分。

setprecision（）：用数字作为参数，表示数字精确度（即小数点的位数）。

setw（）：用数字作为参数，设置字段的宽度，并且文字靠右对齐。

这里：cout<<setiosflags(ios::fixed) 可以写成 cout.setf(ios::fixed)

cout<<setiosflags(ios::showpoint) 可以写成 cout.setf(ios::showpoint)

out<<setprecision(2) 可以写成 cout.precision(2)

以下是一些常见的控制函数的:

dec 置基数为10 相当于"%d"

hex 置基数为16 相当于"%X"

oct 置基数为8 相当于"%o"

setfill(c) 设填充字符为c

setprecision(n) 设显示小数精度为n位

setw(n) 设域宽为n个字符

这个控制符的意思是保证输出宽度为n。如：

cout<<setw(3)<<1<<setw(3)<<10<<setw(3)<<100; 输出结果为

1 10100 （默认是右对齐）当输出长度大于3时(<<1000)，setw(3)不起作用。

setioflags(ios::fixed) 固定的浮点显示

setioflags(ios::scientific) 指数表示

setiosflags(ios::left) 左对齐

setiosflags(ios::right) 右对齐

setiosflags(ios::skipws 忽略前导空白

setiosflags(ios::uppercase) 16进制数大写输出

setiosflags(ios::lowercase) 16进制小写输出

setiosflags(ios::showpoint) 强制显示小数点

setiosflags(ios::showpos) 强制显示符号 
*/