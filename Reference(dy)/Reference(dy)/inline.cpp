//内联函数减少函数调用时所产生的开销 --- 适用于小型的，使用较为频繁的函数
//使用内联函数会减少执行时间，但会增大程序的长度

//计算边长s的立方体体积
#include<iostream>

using namespace std;

inline double cube(const double s) {return s * s * s;}

int main()
{
	cout << "Please Enter the side length of your cube:";

	double side;
	cin >> side;

	cout << "Volume of cube with side "
		<< side << " is " << cube(side) << endl;
	return 0;

}