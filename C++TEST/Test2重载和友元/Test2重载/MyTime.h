#include <iostream>

using namespace std;
#ifndef MYTIME_H_
#define MYTIME_H_

class Time
{
private:
	int hours;
	int minutes;

public:
	Time();
	Time(int h, int m );
	void Reset(int h, int m = 0);
	void Show();
	Time operator+(const Time &t) const;
	Time operator-(const Time &t) const;
	Time operator*(double n) const;//��A=B*2.5������ʽ��һ����

	//��Ԫ����,���ǳ�Ա���������ͳ�Ա����Ȩ��һ����A=2.5*B��
	//���Է���˽�г�Ա������ʱ��friend������ʱ����Ҫ
	friend Time operator*(double n, Time &t)
	{
		return t * n;//���ó�Ա����operator*
	}
};


#endif