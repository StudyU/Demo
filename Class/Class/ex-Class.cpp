#include<iostream>
using namespace std;

//ex_Class类接口定义
class ex_Class
{
private:
	int iv;
	double dv;
public:
	ex_Class(void);
	ex_Class(int n, double x);
	void set_ex_Class(int n, double x);
	void show_ex_Clsaa(char*);
};

//定义构造函数
ex_Class::ex_Class(void):iv(1), dv(1.0) {}
ex_Class::ex_Class(int n, double x):iv(n), dv(x) {}

//定义成员函数
void ex_Class::set_ex_Class(int n, double x)
{
	iv = n;
	dv = x;
}

void ex_Class::show_ex_Clsaa(char *name)
{
	cout << name << ":" << endl;
	cout << "iv = " << iv << endl;
	cout << "dv = " << dv << endl;
}

int main()
{
	ex_Class obj1;
	obj1.show_ex_Clsaa("obj1");
	obj1.set_ex_Class( 5, 5.5 );
	obj1.show_ex_Clsaa("obj1");

	ex_Class obj2( 100, 3.14 );
	obj2.show_ex_Clsaa( "obj2" );
	obj2.set_ex_Class( 2000, 1.732 );
	obj2.show_ex_Clsaa( "obj2" );
	return 0;
}