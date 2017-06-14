#include "MyTime.h"
#include <iostream>

using namespace std;

Time::Time()
{
	hours = minutes = 0;
}
Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}
void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}
void Time::Show()
{
	cout << "Hours: " << hours << "Minutes: " << minutes << endl;
}
Time Time::operator +(const Time &t) const
{
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes/60;
	sum.minutes %= 60;

	return sum;
}
Time Time::operator -(const Time &t) const
{
	Time diff;
	int tot1, tot2;
	tot1 = t.minutes + 60*t.hours;
	tot2 = minutes + 60*hours;
	diff.minutes = (tot2 - tot1)%60;
	diff.hours = (tot2 - tot1)/60;

	return diff;
}

Time Time::operator *(double n) const
{
	Time result;
	long total = hours * n * 60 + minutes * n;
	result.minutes = total % 60;
	result.hours = total / 60;
	 
	return result;
}
/*
Time operator *(double n, Time &t)
{
	Time result;
	long total = t.hours * n * 60 + t.minutes * n;
	result.minutes = total % 60;
	result.hours = total / 60;

	return result;
}*/