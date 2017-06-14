#include "circle.h"
#include "cylinder.h"
#include "point.h"
#include "shape.h"
#include <iostream>
#include <iomanip>
using namespace std;

//基于基类指针和引用的函数
void virtualViaPointer(const Shape*);
void virtualViaReference(const Shape&);

int main()
{
	//cout << setiosflags(ios::fixed | ios::showpoint)
	//	<< setprecision(2);

	//Point point(7.0, 8.0);
	//Circle circle(1.0, 2.0, 3.0);
	//Cylinder cylinder(5.0, 1.0, 2.0, 3.0);

	////单个输出名称和数据
	//point.printShapeName();
	//point.print();

	//circle.printShapeName();
	//circle.print();

	//cylinder.printShapeName();
	//cylinder.print();

	////指针数组
	//Shape* arrayShapes[3];
	//arrayShapes[0] = &point;
	//arrayShapes[1] = &circle;
	//arrayShapes[2] = &cylinder;

	////指针
	//for (int i = 0; i < 3; ++i)
	//{
	//	virtualViaPointer(arrayShapes[i]);
	//}

	//for (int j = 0; j < 3; ++j)
	//{
	//	virtualViaReference(*arrayShapes[j]);
	//}
	int ival = 1024;
	int &refVal = ival;
	//cout << "引用" << refVal << endl;
	int *pi = &ival;
	//cout << "指针对象地址=" << pi << "/" << &ival << "指针对象" << *pi << endl;
	//cout << "指针地址" << &pi << endl;

	const int cival = 2048;
	const int *const &refciVal = &cival;
	//cout << refciVal << "/" << &refciVal << "/" << *refciVal << "/" << &cival << endl;
	return 0;
}

void virtualViaPointer(const Shape* baseclassPtr)
{
	baseclassPtr->printShapeName();
	baseclassPtr->print();

	cout << "\nPointerArea" << baseclassPtr->area()
		<<"\nPointerVolume" << baseclassPtr->volume()
		<< endl;
}

void virtualViaReference(const Shape& baseclassRef)
{
	baseclassRef.printShapeName();
	baseclassRef.print();

	cout << "\nReferenceArea" << baseclassRef.area()
		<< "\nReferenceVolume" << baseclassRef.volume() << endl;

}