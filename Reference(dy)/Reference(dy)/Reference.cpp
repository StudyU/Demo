//调用分为传值调用（不修改），引用调用（修改值）；
/*
int count = 1;
int &rec = count;//引用变量必须初始化
 ++rec;
*/
#include <iostream>

using namespace std;

int squareByValue( int );//传值调用
void squareByReference( int & ); //引用调用

int main()
{
	int x = 2, z = 4;
	cout << "x = " << x << " before squareByValue\n"
		<< " Return Value: " << squareByValue( x ) << endl
		<< "x: " << x << " After squareByValue\n" << endl;
	cout << "z = " << z << " before squareByReference\n" << endl;
	 squareByReference( z );
	cout << "z: " << z << " After squareByReference\n" << endl;

	return 0;	
}

int squareByValue( int a )
{
	return a *= a;//值传递，相当于另外开辟的存储单元，不改变原始数据X
}

void squareByReference( int &cref )
{
	cref *= cref;//址传递，这个函数直接在原来数据的存储单元直接操作，改变了Z值，所以调用前后原始数据发生改变
}