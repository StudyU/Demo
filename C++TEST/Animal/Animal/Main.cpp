#include <iostream>
#include "Animal.h"
#include "Fish.h"//Animal���ظ�����

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

	//�麯�������óٰ������C++��̬��
	virtual void breath() = 0;
//	{
//		cout << "Animal breath!" << endl;
//	}


};

class Fish : public Animal
{
public:
	Fish():Animal(300, 400), a(1)//��ʼ��
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

//���ô��α�ָ�����Ϊָ�봫��ʱ���ܸı��ڴ�ռ��ַ
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
	//int &b = a; //���ö���ʱ���ʼ��
	//b = 4; //a��ֵҲ��֮�ı�
	//cout << "A=" << a << "b=" << b << endl;
	//fish.breath(); 
	//fish.eat();
	//fish.sleep();

	return 0;

}