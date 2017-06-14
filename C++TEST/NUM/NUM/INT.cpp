#include <iostream>
using namespace std;

//数值精度=
int main()
{
	cout.setf(ios_base::fixed, ios_base::floatfield);
	float tree = 3;
	int guess(3.9832);
	int debt = 7.2E12;
	double doub = 7.11112;
	cout << "Tree:" << tree << endl;
	cout << "guess:" << guess << endl;
	cout << "debt:" << debt << endl;
	cout << "doub:" << doub << endl;

	return 0;
}