#include "ClassTemplate.h"
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

int main()
{
	Stack<int> intStack;
	intStack.push(6);
	Stack<string> strStack;
	strStack.push("Hi World!");

	cout << "intStack:" << intStack.top() << endl
		<< "strStack:" << strStack.top() << endl;

	strStack.clear();
	intStack.clear();

	NontypeStack<int, 2> intNontypeStack;
	intNontypeStack.push(2);
	intNontypeStack.push(42);
	cout << "intNontypeStack:" << intNontypeStack.top() << endl;
	intNontypeStack.pop();
	cout << "intNontypeStack:" << intNontypeStack.top() << endl;

	system("pause");
	return 0;
}




