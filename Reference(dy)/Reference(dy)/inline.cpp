//�����������ٺ�������ʱ�������Ŀ��� --- ������С�͵ģ�ʹ�ý�ΪƵ���ĺ���
//ʹ���������������ִ��ʱ�䣬�����������ĳ���

//����߳�s�����������
#include<iostream>

using namespace std;

inline double cube(const double s) {return s * s * s;}

int main()
{
	cout << "Please Enter the side length of your cube:";

	double side;
	cin >> side;

	cout << "Volume of cube with side "
		<< side << " is " << cube(side) << endl;
	return 0;

}