#include "circle.h"
#include <iostream>
using namespace std;

Circle::Circle(double r, double x, double y) : Point(x, y)
{
	Circle::setRadius(r);
}

double Circle::area() const 
{
	return PI*radius*radius;
}

void Circle::print() const
{
	Point::print();
	cout << "Radius: " << radius << endl;
}