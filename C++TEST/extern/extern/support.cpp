#include <iostream>

using namespace std;

//���������ļ���ʹ���ⲿ����ı���warming
extern double warming;
void update(double dt);
void local();

void update(double dt)
{
	//extern double warming;�о�����Ҫ��һ�䣬ͷ�ļ�����������
	warming += dt;
	cout << "after update: " << warming << endl;
}

void local()
{
	double warming = 0.8;
	cout << "After local: " << warming << endl;
	//�������ʶ��::ȡȫ�ֱ���
	cout << "g_warmingl: " << ::warming << endl;
}