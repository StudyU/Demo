#include <iostream>
using namespace std;

double de (int);
double sum (int);

void estimate(int len, double (*pf)(int));

int main()
{
	int lens;
	cout << "Enter your want lens: ";
	cin >> lens;

	cout << "de: \n";
	estimate(lens, de);

	cout << "sum: \n";
	estimate(lens, sum);

	return 0;
}

double de(int lns)
{
	return 0.05*lns;
}

double sum(int lns)
{
	return 0.04*lns + 0.03*lns*lns;
}

void estimate(int len, double (*pf) (int))
{
	cout << len << endl;
	cout << (*pf)(len) << "hours " << endl;
}