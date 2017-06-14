#include <iostream>
#include <list>
#include <vector>
#include <deque>
using namespace std;

void main()
{
	int arr[5] = {1,2,3,4,5};
	list<int>mylist(arr, arr+5);

	auto rb = mylist.rbegin();
	auto re = mylist.rend();
	for (;rb!=re;rb++)
	{
		cout << *rb << " ";
	}
	cout << endl;

	cin.get();
}