/************************************************************************/
/* ͼ��                                                                 */
/************************************************************************/
#ifndef __SHAPE_H_
#define __SHAPE_H_

class Shape
{
public:
	//ͼ����������
	virtual double area() const {return 0.0;}
	virtual double volume() const {return 0.0;}

	//���麯������������д�����ͼ�����ƺ����
	virtual void printShapeName() const = 0;
	virtual void print() const = 0;
};

#endif //__SHAPE_H_
