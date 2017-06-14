/************************************************************************/
/* Ô²ÐÎ                                                                 */
/************************************************************************/
#ifndef __CIRCLE_H_
#define __CIRCLE_H_

#include "point.h"
#include <iostream>
using namespace std;

#define PI 3.14159

class Circle : public Point
{
public:
	Circle(double r = 0.0, double x = 0.0, double y = 0.0);
	void setRadius(double a) {radius = a;}
	double getRadius() const {return radius;}
	//Ãæ»ý
	virtual double area() const;

	virtual void printShapeName() const {cout << "Circle: " << endl;}
	virtual void print() const;

private:
	double radius;
};

#endif //__CIRCLE_H_