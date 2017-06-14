#include "Animal.h"

#ifndef FISH_H_
#define FISH_H_
class Fish : public Animal
{
public:
	Fish();//:Animal(300, 400), a(1)//初始化
	//{
		//cout << "fish construct!" << endl;
	//}
	//~Fish()
	//{
		//cout << "fish end" << endl;
	//}
	void breath();//也是虚函数
	//{
		//Animal::breath();
	//	cout << "fish bubble!" << endl;
	//}

//protected:
//	const int a;
};

#endif