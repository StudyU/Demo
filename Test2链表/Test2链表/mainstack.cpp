#include"stack.h"
#include <iostream>
using namespace std;

int main11()
{
	stack<int> intstack;
	intstack.push(3);
	intstack.push(2);
	intstack.push(33);
	intstack.push(4);
	intstack.push(55);
	intstack.push(78);

	while(!intstack.istackempty())
	{
		int i;
		intstack.pop(i);
		cout << i << endl;
		intstack.printstack();
	}
	
	return 0;
}

