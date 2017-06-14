#include "circle.h"
#include "cylinder.h"
#include "point.h"
#include "shape.h"
#include <iostream>
#include <iomanip>
using namespace std;

//���ڻ���ָ������õĺ���
void virtualViaPointer(const Shape*);
void virtualViaReference(const Shape&);

int main()
{
	//cout << setiosflags(ios::fixed | ios::showpoint)
	//	<< setprecision(2);

	//Point point(7.0, 8.0);
	//Circle circle(1.0, 2.0, 3.0);
	//Cylinder cylinder(5.0, 1.0, 2.0, 3.0);

	////����������ƺ�����
	//point.printShapeName();
	//point.print();

	//circle.printShapeName();
	//circle.print();

	//cylinder.printShapeName();
	//cylinder.print();

	////ָ������
	//Shape* arrayShapes[3];
	//arrayShapes[0] = &point;
	//arrayShapes[1] = &circle;
	//arrayShapes[2] = &cylinder;

	////ָ��
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
	//cout << "����" << refVal << endl;
	int *pi = &ival;
	//cout << "ָ������ַ=" << pi << "/" << &ival << "ָ�����" << *pi << endl;
	//cout << "ָ���ַ" << &pi << endl;

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