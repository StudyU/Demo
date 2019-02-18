#pragma once
#include "singleton.h"
#include <iostream>
using namespace std;
class A
{
public:
	void aa() {cout << "aa" << endl; };
private:
	DEFINE_SINGLETON(A);
};

class B
{
public:
	void bb() { cout << "bb" << endl; };
};

typedef Singleton<B> BSingleton;