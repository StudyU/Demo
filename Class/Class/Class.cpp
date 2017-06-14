//类
#include<iostream>

using namespace std;

class Count{
public:
	int x;
	void print(){ cout << x << endl; }

};

int main()
{
	Count counter, //值传递(对象名称)
		&counterRef = counter,//引用调用（引用）
		*counterPtr = &counter;//指针传递（对象指针）

	cout << " Assign 7 to x and print using the object's name: ";
	counter.x = 7;
	counter.print();

	cout << " Assign 8 to x and print using a reference: ";
	counterRef.x = 8;
	counterRef.print();

	cout << " Assign 10 to x and print using a pointer: ";
	counterPtr->x = 10;
	counterPtr->print();

	return 0;
}

/*
class Time{
public:
	Time();
	void setTime( int, int, int );
	void PrintMilitary();
	void PrintStandard();
private:
	int hour;
	int minute;
	int second;
};

//数据成员初始化为0
Time::Time(){ hour = minute = second = 0; }

void Time::setTime( int h, int m, int s )
{
	hour = ( h >= 0 && h < 24 ) ? h : 0;
	minute = ( m >= 0 && m < 60 ) ? m : 0;
	second = ( s >= 0 && s < 60 ) ? s : 0;
}
void Time::PrintMilitary()
{
	cout << ( hour < 10 ? "0":"" ) << hour << ":"
		<< ( minute < 10 ? "0":"" ) << minute;
}

void Time::PrintStandard()
{
	cout << (( hour == 0 || hour == 12 ) ? 12 : hour % 12 )
		<< ":" << ( minute < 10 ? "0":"" ) << minute 
		<< ":" << ( second < 10 ? "0":"" ) << second
		<< ( hour < 12 ? " AM" : " PM" );
}

int main()
{
	Time t;

	cout << "\nWhich initial standard time is ";
	t.PrintMilitary();

	t.setTime( 13, 27, 6 );
	cout << "\n\nMilitary time after setTime is ";
	t.PrintMilitary();

	cout << "\nStandard time after setTime is ";
	t.PrintStandard();

	t.setTime( 99, 99, 99 );
	cout << "\n\nAfter attempting invaild settings: "
		<< "\nMilitary time: ";
	t.PrintMilitary();
	cout << "\nStandard time: ";
	t.PrintStandard();
	cout << endl;
	return 0;
}
*/