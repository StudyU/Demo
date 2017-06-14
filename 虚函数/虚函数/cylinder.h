/************************************************************************/
/* 柱面                                                                 */
/************************************************************************/
#ifndef __CYLINDER_H_
#define __CYLINDER_H_

#include "circle.h"
#include "cylinder.h"
#include <iostream>
using namespace std;

class Cylinder : public Circle
{
public:
	Cylinder(double h = 0.0, double r = 0.0, double x = 0.0, double y = 0.0);
	void setHeight(double h) {height = h;}
	double getHeight() const {return height;}

	//面积和体积
	virtual double area() const;
	virtual double volume() const;

	virtual void printShapeName() const {cout << "Cylinder: " << endl;}
	virtual void print() const;
private:
	double height;
};

#endif //__CYLINDER_H_