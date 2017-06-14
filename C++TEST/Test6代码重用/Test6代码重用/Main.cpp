#include "Student.h"
#include <valarray>
#include <string>
#include <iostream>

using namespace std;

void set(Student & sa, int n);
const int puplis = 3;
const int quizzes = 5;

int main()
{
	Student ada[puplis] = {Student(quizzes), Student(quizzes), Student(quizzes)};
	int i;
	for (i=0; i < puplis; ++i)
	{
		set(ada[i], quizzes);
	}
	cout << "\nStudent List:\n";
	for (i=0; i<puplis; ++i)
	{
		cout << ada[i].Name() << endl;
	}
	cout << "\nResult:";
	for (i=0; i<puplis; ++i)
	{
		cout << endl << ada[i];
		cout << "average: " << ada[i].Average() << endl;
	}
	cout << "Done.\n";
	return 0;
}

void set(Student & sa, int n)
{
	cout << "Please Enter the student's name: ";
	getline(cin, sa);
	cout << "please enter " << n << " quiz scores:\n";
	for(int i=0; i<n; i++)
	{
		cin >> sa[i];
	}
	while (cin.get() != '\n')
	{
		continue;
	}
}