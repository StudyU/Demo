#ifndef COMPLEX_H_
#define COMPLEX_H_

class Complex
{
private:
	float real;
	float image;
public:
	Complex();
	//Complex operator+(Complex right);此方法没有下面的好，引用更加节省空间和时间
	Complex operator+(const Complex &right) const;
	Complex operator=(const Complex &right) ;

	void Reset(float re, float im);
	void Put(char *name);

	~Complex();
};

#endif