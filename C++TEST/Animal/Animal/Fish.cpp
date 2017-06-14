#include "Fish.h"
#include <iostream>

using namespace std;

Fish::Fish():Animal(300, 400)//记得传参，因为父类是有参数的构造函数
{

}

void Fish::breath()
{
	cout << "fish bubble!" << endl;
}