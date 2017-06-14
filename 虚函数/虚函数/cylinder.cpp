#include "cylinder.h"
#include <iostream>
using namespace std;

Cylinder::Cylinder(double h /* = 0.0*/, double r /* = 0.0*/, double x /* = 0.0*/, double y /* = 0.0 */) : Circle(r, x, y)
{
	Cylinder::setHeight(h);
}

double Cylinder::area() const
{
	return 2*Circle::area() + PI*(Circle::getRadius())*2*height; 
}

double Cylinder::volume() const
{
	return Circle::area() * height;
}

void Cylinder::print() const
{
	Circle::print();
	cout << "Height: " << height << endl;
}