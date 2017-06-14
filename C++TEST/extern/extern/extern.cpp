#include <iostream>

using namespace std;

double warming = 0.3;

void update(double dt);
void local();

int main()
{
	cout << "First:" << warming << endl;
	update(0.1);
	local();
	cout << "endl: " << warming << endl;

	return 0;
}
