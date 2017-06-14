#include <iostream>
using namespace std;

template <class T1, class T2>
void Display(const T1 st1, const T2 st2)
{
	cout << st1 <<" " << st2 << endl;
}

int main()
{
	char c = 'A';
	char ch[] = "this is a good day!";
	int i = 10;
	float x = 0.5;
	double z = 3.1415926;

	//参数相同
	Display(c, char(c+2));
	Display(ch, ch);
	Display(i, 2*i);
	Display(x, 2*x);
	Display(z, 2*z);
	cout << "--------------" << endl;

	//参数不同
	Display(c, ch);
	Display(c, i);
	Display(ch, x);
	Display(x, z);

	return 0;
}