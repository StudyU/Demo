//¸¨Öúº¯Êý
#ifndef ALGOSTUFF_H_
#define ALGOSTUFF_H_
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
#include <deque>
using namespace std;

template <class T>
//ÈÝÆ÷£¬ÎÄÑÔ£¬ÌØÊâ·Ö¸ô·û
inline void PRINT_ELEMENTS(const T& coll, const char* optcstr="", const char* special=" ")
{
	typename T::const_iterator pos;
	cout << optcstr;
	for (pos = coll.begin(); pos!=coll.end(); ++pos)
	{
		cout << *pos << special;
	}
	cout << endl;
}

template <class T>
inline void INSERT_ELEMENTS(T& coll, int first, int last)
{
	for (int i=first; i<=last; ++i)
	{
		coll.insert(coll.end(), i);
	}
}

#endif