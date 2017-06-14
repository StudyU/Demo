#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	typedef map<string, double> StringFloatMap;
	StringFloatMap coll;

	//赋值插入
	/*
	coll["BASF"] = 369.50;
	coll["VW"] = 413.50;
	coll["Daimler"] = 819.00;
	coll["BMW"] = 834.00;
	coll["Siemens"] = 842.20;
	*/
	coll.insert(make_pair("BASF", 369.50));
	coll.insert(make_pair("VW", 413.50));
	coll.insert(make_pair("Daimler", 819.00));
	coll.insert(make_pair("BMW", 834.00));
	coll.insert(make_pair("Siemens", 842.20));

	StringFloatMap::iterator pos;
	for (pos=coll.begin(); pos!=coll.end(); ++pos)
	{
		cout << "Key:" << pos->first 
			<<" Value:" << pos->second << endl;
	}
	cout << endl;

	//替换Key值
	cout << "Exchange Key:" << endl;
	coll["Volkswagen"] = coll["VW"];
	coll.erase("VW");
	for (pos=coll.begin(); pos!=coll.end(); ++pos)
	{
		cout << "Key:" << pos->first 
			<<" Value:" << pos->second << endl;
	}
	cout << endl;

	//删除键值Key
	coll.erase("BMW");
	cout << "Delete Key BMW:" << endl;
	for (pos=coll.begin(); pos!=coll.end(); ++pos)
	{
		cout << "Key:" << pos->first 
			<<" Value:" << pos->second << endl;
	}
	cout << endl;

	//按键值给定的区域输出
	cout << "Print for area of key:" << endl;
	for (pos=coll.lower_bound("C"); pos!=coll.upper_bound("V"); ++pos)
	{
		cout << "Key:" << pos->first 
			<<" Value:" << pos->second << endl;
	}
	cout << endl;

	//删除元素Value
	cout << "Delete Value:" << endl;
	cout << "Enter You want to delete value: ";
	double val;
	bool VAL=false;
	cin >> val;

	for (pos=coll.begin(); pos!=coll.end(); ++pos)
	{
		if (pos->second == val)
		{
			VAL = true;
		}
	}

	if (VAL)
	{
		for (pos=coll.begin(); pos!=coll.end();)
		{
			if (pos->second == val)
			{
				coll.erase(pos++);
			}
			else
			{
				++pos;
			}
		}
		for (pos=coll.begin(); pos!=coll.end(); ++pos)
		{
			cout << "Key:" << pos->first 
				<<" Value:" << pos->second << endl;
		}
		cout << endl;
	}
	else
	{
		cout << "No find the value!" << endl;
	}

// 	pos = find_if(coll.begin(), coll.end(), 834.00);
// 	if (pos!=coll.end())
// 	{
// 		cout << pos->first << " " << pos->second << endl;
// 		cout << "You find it" << endl;
// 	}
	
	return 0;
}