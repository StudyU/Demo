/************************************************************************/
/* ��                                                                   */
/************************************************************************/
#ifndef __POINT_H_
#define __POINT_H_

#include "shape.h"
#include <iostream>
using namespace std;

class Point : public Shape
{
public:
	//Ĭ�Ϲ��캯��
	Point(double = 0.0, double = 0.0);
	void setPoint(double, double);

	//���x��y��
	double getX() const {return x;}
	double getY() const {return y;}

	virtual void printShapeName() const {cout << "Point: ";}
	virtual void print() const;

private:
	double x, y;
};

#endif //__POINT_H_