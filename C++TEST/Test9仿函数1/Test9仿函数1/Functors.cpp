#include <iostream>
#include <list>
#include <algorithm>
#include "algostuff.h"

using namespace std;
//仿函数只能增加int型或强制转换成int型
class AddValue
{
private:
	int theValue;
public:
	AddValue(int v) : theValue(v) {}

	void operator() (int &elem) const {
		elem += theValue;
	}

};

int main()
{
	list<int> coll;
	//for (int i=1; i<10; ++i)
	//{
	//	coll.push_back(i);
	//}
	INSERT_ELEMENTS(coll, 1, 9);
	PRINT_ELEMENTS(coll, "initialized: ");
	//copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	//cout << endl;

	for_each(coll.begin(), coll.end(), AddValue(10));

	//copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, ","));
	//cout << endl;
	PRINT_ELEMENTS(coll, "after adding 10: ", ",");
	for_each(coll.begin(), coll.end(), AddValue(*coll.begin()));
	//copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, "_"));
	//cout << endl;
	PRINT_ELEMENTS(coll, "after adding 10: ", "__");
	return 0;

}

//使用模板仿函数，可以是各种型别
/*
template <class T>
class AddValue1
{
private:
	T theValue;
public:
	AddValue1(const T& v) : theValue(v) {}

	void operator() (T& elem) const {
		elem += theValue;
	}
};

int main()
{
	list<int> coll;
	for (int i=1; i<10; ++i)
	{
		coll.push_back(i);
	}
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	for_each(coll.begin(), coll.end(), AddValue1<int>(10.6));

	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, ","));
	cout << endl;

	for_each(coll.begin(), coll.end(), AddValue1<int>(*coll.begin()));
	copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, "_"));
	cout << endl;
	return 0;

}
*/