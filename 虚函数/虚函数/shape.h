/************************************************************************/
/* 图形                                                                 */
/************************************************************************/
#ifndef __SHAPE_H_
#define __SHAPE_H_

class Shape
{
public:
	//图形面积和体积
	virtual double area() const {return 0.0;}
	virtual double volume() const {return 0.0;}

	//纯虚函数在子类中重写，输出图形名称和输出
	virtual void printShapeName() const = 0;
	virtual void print() const = 0;
};

#endif //__SHAPE_H_
