#include<iostream>//��ϵͳĿ¼�²���ͷ�ļ�
#include "Animal.h"//�ڵ�ǰĿ¼�²���ͷ�ļ�Ȼ����ȥϵͳĿ¼��ѯ

using namespace std;

Animal::Animal(int weight, int height)//���캯��û�з���ֵ
{

}

//����Ҫ���virtual
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