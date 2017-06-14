/************************************************************************/
/* 点                                                                   */
/************************************************************************/
#ifndef __POINT_H_
#define __POINT_H_

#include "shape.h"
#include <iostream>
using namespace std;

class Point : public Shape
{
public:
	//默认构造函数
	Point(double = 0.0, double = 0.0);
	void setPoint(double, double);

	//获得x，y点
	double getX() const {return x;}
	double getY() const {return y;}

	virtual void printShapeName() const {cout << "Point: ";}
	virtual void print() const;

private:
	double x, y;
};

#endif //__POINT_H_