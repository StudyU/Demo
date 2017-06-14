#include "String.h"
#include <iostream>

using namespace std;

const int ArSize = 10;
const int MaxLen = 81;
int main()
{
	String name;
	cout << "Hi,what's your name?\n";
	cin >> name;

	cout << name << ", please enter up to " << ArSize 
		<< " short sayings <empty line to quit>:\n";

	String saying[ArSize];
	char temp[MaxLen];
	int i;
	for (i = 0; i < ArSize; i++)
	{
		cout << i+1 << ": ";
		cin.get(temp, MaxLen);
		while (cin && cin.get() != '\n')
		{
			continue;
		}
		if (!cin || temp[0] == '\0')
		{
			break;
		}
		else
		{
			saying[i] = temp;
		}
	}
	int total = i;

	if (total > 0)
	{
		cout << "Here are you sayings:\n";
		for (i = 0; i < total; i++)
		{
			cout << saying[i][0] << ": " << saying[i] << endl;
		}

		int shortest = 0;
		int first = 0;

		for (i = 1; i < total; i++)
		{
			if (saying[i].Length() < saying[shortest].Length())
			{
				shortest = i;
			}
			if (saying[i] < saying[first])
			{
				first = i;
			}
		}
		cout << "shortest saying:\n" << saying[shortest] << endl;
		cout << "First ×ÖÄ¸Ë³Ðò:\n" << saying[first] << endl;
		cout << "This program used " << String::HowMany()
			<< " string objects.bye.\n";

		String s1;
		s1 = saying[0];
		cout << "s1: " << s1 << endl;
	}
	else
		cout << "No input! Bye.\n";

	return 0;
}
