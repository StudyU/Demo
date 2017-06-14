#include "Complex.h"
#include <iostream>

using namespace std;

Complex::Complex()
{
	real = image = 0.0;
}
Complex::~Complex()
{
}
/*
Complex Complex::operator +(Complex right)
{
	Complex Temp;
	Temp.real = this->real + right.real;
	Temp.image = this->image + right.image;

	return Temp;
}*/

Complex Complex::operator +(const Complex &right) const
{
	Complex Temp;
	Temp.real = real + right.real;
	Temp.image = image + right.image;

	return Temp;
}

Complex Complex::operator =(const Complex &right)//不能用const后置，因为返回值改变
{
	real = right.real;
	image = right.image;

	return *this;
}

void Complex::Reset(float re, float im)
{
	real = re;
	image = im;
}

void Complex::Put(char *name)
{
	cout << name << ": " << real << "i";
	if (image >= 0)
	{
		cout << "+";
	}
	cout << image << "j" << endl;
}