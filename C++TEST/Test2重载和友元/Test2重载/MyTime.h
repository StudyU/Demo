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
	Time operator*(double n) const;//（A=B*2.5两个格式不一样）

	//友元函数,不是成员函数，但和成员函数权限一样（A=2.5*B）
	//可以访问私有成员，声明时有friend，定义时不需要
	friend Time operator*(double n, Time &t)
	{
		return t * n;//条用成员函数operator*
	}
};


#endif