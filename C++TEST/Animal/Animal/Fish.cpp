#include "Fish.h"
#include <iostream>

using namespace std;

Fish::Fish():Animal(300, 400)//�ǵô��Σ���Ϊ�������в����Ĺ��캯��
{

}

void Fish::breath()
{
	cout << "fish bubble!" << endl;
}