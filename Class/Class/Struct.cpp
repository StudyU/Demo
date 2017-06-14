//类和结构体，圆点操作符（.）是通过对象变量名或对象的引用访问结构成员或类成员；箭头操作符（->）是通过对象指针访问结构成员或类成员
//设timeObject为结构体 timePtr = &timeObject; cout << timePtr->hour或(*timePtr).hour; （.）优先级高于（*）;


//时间判断
#include<iostream>
using namespace std;

//结构体
struct Time
{
	int hour;
	int minute;
	int second;
};

//声明原型
//结构通常通过传值调用传递，但是为了避免复制结构的开销，使用引用调用传递结构更好
void PrintMilitary( const Time &);
void PrintStandard( const Time &);

int main()
{
	Time dinnerTime;
	dinnerTime.hour = 18;
	dinnerTime.minute = 30;
	dinnerTime.second = 0;

	cout << "Dinner will be held at ";
	PrintMilitary( dinnerTime );
	cout << " Military time,\nwhich is ";
	PrintStandard( dinnerTime );
	cout << " Standard time.\n";

	dinnerTime.hour = 29;
	dinnerTime.minute = 73;
	
	cout << "\nTime with invaild values: ";
	PrintMilitary( dinnerTime );
	cout << endl;
	return 0;
}

void PrintMilitary( const Time &t )
{
	cout << ( t.hour < 10 ? "0":"" ) << t.hour << ":"
		<< ( t.minute < 10 ? "0":"" ) << t.minute;
}

void PrintStandard( const Time &t )
{
	cout << (( t.hour == 0 || t.hour == 12 ) ? 12 : t.hour % 12 )
		<< ":" << ( t.minute < 10 ? "0":"" ) << t.minute 
		<< ":" << ( t.second < 10 ? "0":"" ) << t.second
		<< ( t.hour < 12 ? " Am" : " PM" );
}