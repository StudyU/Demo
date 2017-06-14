#include <iostream>

using namespace std;

//调用其他文件，使用外部定义的变量warming
extern double warming;
void update(double dt);
void local();

void update(double dt)
{
	//extern double warming;感觉不需要这一句，头文件中声明过了
	warming += dt;
	cout << "after update: " << warming << endl;
}

void local()
{
	double warming = 0.8;
	cout << "After local: " << warming << endl;
	//作用域标识符::取全局变量
	cout << "g_warmingl: " << ::warming << endl;
}