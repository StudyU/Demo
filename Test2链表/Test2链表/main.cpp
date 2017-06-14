#include "list.h"
#include <iostream>
using namespace std;

void instrcutions();

template<class T>
void TestList(List<T> &listobject, const char *type)
{
	cout << "Testing a list of " << type << "values\n";
	instrcutions();
	int choice;
	T value;

	do 
	{
		cout << "Your Choice: ";
		cin >> choice;

		switch(choice)
		{
		case 1:
			cout << "Enter " << type << ": ";
			cin >> value;
			listobject.InsertAtFront(value);
			listobject.print();
			break;
		case 2:
			cout << "Enter " << type << ": ";
			cin >> value;
			listobject.InsertAtBack(value);
			listobject.print();
			break;
		case 3:
			if (listobject.RemoveFromFront(value))
			{
				cout << value << "remove from list front\n";
			}
			
			listobject.print();
			break;
		case 4:
			if (listobject.RemoveFromBack(value))
			{
				cout << value << "remove from list back\n";
			}

			listobject.print();
			break;
		default:
			return;
		}
	} while(choice!=5);

	cout << "End List Test!!!\n\n";

	return;
}

void instrcutions()
{
	cout << "Please Enter the following num to start Testing: \n"
		<<"1 to insert at front\n"
		<<"2 to insert at back\n"
		<<"3 to remove at front\n"
		<<"4 to remove at front\n"
		<<"5 to END\n";

	return;
}
int main()
{
	List<int> intlist;
	TestList(intlist, "intlist");

	List<double> doublelist;
	TestList(doublelist, "doublelist");

	return 0;
}