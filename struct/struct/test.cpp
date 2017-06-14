#include <iostream>
using namespace std;

const int minute = 60; 

struct travel_time 
{
	int hour;
	int min;
};
// 传值
travel_time sum_time(travel_time tra1, travel_time tra2);
// 引用
void sumtime(travel_time& tr1, travel_time& tr2);
// 指针
void SUMtime(travel_time* t1, travel_time* t2);

int main()
{
	travel_time day1 = {18, 50};
	travel_time day2 = {20, 50};

	travel_time total_time = sum_time(day1, day2);

	cout << "You spend:" << total_time.hour << "Hours" << total_time.min << "Minutes in Traveling!" << endl;

	
	sumtime(day1, day2);
	cout << day2.hour << ":"<< day2.min << endl;
	
	//传递结构的地址比传递结构节省空间和时间
	SUMtime(&day1, &day2);
	cout << day1.hour << ":" << day1.min << endl;

	return 0;
}
// 传值
travel_time sum_time(travel_time tra1, travel_time tra2)
{
	travel_time totaldays;
	totaldays.hour = tra1.hour + tra2.hour + (tra1.min +tra2.min) / minute;
	totaldays.min = (tra1.min +tra2.min) % minute;	

	return totaldays;
}
// 引用
void sumtime(travel_time& tr1, travel_time& tr2)
{
	tr2.hour = tr2.hour + tr1.hour + (tr1.min + tr2.min) / minute;
	tr2.min = (tr1.min + tr2.min) % minute;
}

// 指针
void SUMtime(travel_time* t1, travel_time* t2)
{
	t1->hour = t2->hour + t1->hour + (t1->min + t2->min) / minute;
	t1->min = (t1->min + t2->min) % minute;
}