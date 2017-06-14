#include "MyTime.h"
#include <iostream>

using namespace std;

int main()
{
	Time t1(12, 35);
	Time t2(2, 20);
	Time total;
	Time diff;
	Time result;
/*
	cout << "t1:";
	t1.Show();
	cout << endl;
	cout << "t2:";
	t2.Show();
	cout << endl;
	
	total = t1 + t2;
	cout << "total:";
	total.Show();
	cout << endl;

	diff = t1 - t2;
	cout << "diff:";
	diff.Show();
	cout << endl;
*/
	result = t1 * 1.5;
	cout << "result:";
	result.Show();
	cout << endl;

	result = 1.5 * t1;
	cout << "Friend result:";
	result.Show();
	cout << endl;
/*
	t1.Reset(10, 10);
	cout << "New t1:";
	t1.Show();
	cout << endl;
*/
	return 0;
}