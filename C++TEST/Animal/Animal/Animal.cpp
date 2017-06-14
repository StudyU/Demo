#include<iostream>//在系统目录下查找头文件
#include "Animal.h"//在当前目录下查找头文件然后再去系统目录查询

using namespace std;

Animal::Animal(int weight, int height)//构造函数没有返回值
{

}

//不需要添加virtual
void Animal::breath()
{
	cout << "Animal breath!" << endl;
}

void Animal::eat()
{
	cout << "Animal eat!" << endl;
}

void Animal::sleep()
{
	cout << "Animal sleep!" << endl;
}