#ifndef COMPLEX_H_
#define COMPLEX_H_

class Complex
{
private:
	float real;
	float image;
public:
	Complex();
	//Complex operator+(Complex right);�˷���û������ĺã����ø��ӽ�ʡ�ռ��ʱ��
	Complex operator+(const Complex &right) const;
	Complex operator=(const Complex &right) ;

	void Reset(float re, float im);
	void Put(char *name);

	~Complex();
};

#endif