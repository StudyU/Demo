#include <iostream>
#include "Animal.h"
#include "Fish.h"//Animal类重复定义

using namespace std;
/*
class Animal
{
public:
	int weight;
	int height;
	Animal(	int weight, int height)
	{
		this->weight = weight;
		this->height = height;
		//cout << this->weight << this->height <<"Animal Construct!" << endl;
	}

	~Animal()
	{
		//cout << "Animal end!" << endl;
	}

	void eat()
	{
		cout << "Animal eat!" << endl;
	}

	void sleep()
	{
		cout << "Animal sleep!" << endl;
	}

	//虚函数，采用迟邦定技术。C++多态性
	virtual void breath() = 0;
//	{
//		cout << "Animal breath!" << endl;
//	}


};

class Fish : public Animal
{
public:
	Fish():Animal(300, 400), a(1)//初始化
	{
		//cout << "fish construct!" << endl;
	}
	~Fish()
	{
		//cout << "fish end" << endl;
	}
	void breath()
	{
		//Animal::breath();
		cout << "fish bubble!" << endl;
	}

protected:
	const int a;
};
*/
void fn(Animal *pan)
{
	pan->breath();
}

//引用传参比指针好因为指针传递时可能改变内存空间地址
/*
void change(int &a, int &b)
{
	int c = 0;
	c = a;
	a = b;
	b = c;
}
*/

int main()
{
/*	Animal sheep(100, 200);
	sheep.breath(); 
	sheep.eat();
	sheep.sleep();
*/
	Animal *pn;
	Fish fish;

	pn = &fish;
	fn(pn);
	
	//int x = 3;
	//int y = 5;
	//change(x, y);
	//cout << x << y << endl;
	//int a = 5;
	//int &b = a; //引用定义时需初始化
	//b = 4; //a的值也随之改变
	//cout << "A=" << a << "b=" << b << endl;
	//fish.breath(); 
	//fish.eat();
	//fish.sleep();

	return 0;

}