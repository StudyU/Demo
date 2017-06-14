#include <iostream>
using namespace std;

//Y类的不完全定义
class Y;

class X
{
public:
	void disp(Y py, const char *name );//成员函数原型
};

class Y
{
	friend void X::disp(Y py, const char *name );
	friend void putY(Y &yc, const char *name);
private:
	int num;
	void dispY(const char *name)
	{
		cout << name << "num: " << num << endl;
	}

public:
	Y(int n)
	{
		num = n;
	}

};

void X::disp(Y py, const char *name)
{
	cout << "In X::disp= " << endl;
	py.dispY(name);
}

void putY(Y &yc, const char *name)
{
	cout << "In puty= " << endl;
	yc.dispY(name);
	cout << "name= " << name 
		<< "num= " << yc.num << endl;
}

int main()
{
	Y y1(100), y2(200);
	X x1;
	//不可用Y类中的私有成员进行显示
	//公有的可以使用
	//y1.dispY("y1: ");
	//y2.dispY("y2: ");

	//调用X类对象的友元函数进行显示
	x1.disp(y1, "y1 ");
	cout << endl;
	x1.disp(y2, "y2 ");
	cout << endl;

	putY(y1, "y1 ");
	cout << endl;
	putY(y2, "y2 ");

	return 0;
}