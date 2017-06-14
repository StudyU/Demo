#include <iostream>
#include <string>
using namespace std;

const int SIZE = 5;

void display(const string arr[], int n);

int main()
{
	string list[SIZE];
	cout << "Enter your favorite " << SIZE << " girls!\n";

	for (int i = 0; i < SIZE; i++)
	{
		cout << i+1 << ": ";
		getline(cin, list[i]);
	}

	cout << "Your List:\n";
	display(list, SIZE);

	return 0;
}

void display(const string arr[], int n)
{
	for ( int i = 0; i < n; i++ )
	{
		cout << i+1 << ": " << arr[i] << endl;
	}
}