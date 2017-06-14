#ifndef STUDENT_H_
#define STUDENT_H_
#include <string>
#include <iostream>
#include <valarray>//处理不同数据类型模板类
#pragma comment( lib, "opencv_highgui231d.lib")
#pragma comment( lib, "opencv_core231d.lib")
using namespace std;

class Student
{
private:
	typedef valarray<double> ArrayDb;
	string name;
	ArrayDb scores;
	//私有方式定义辅助输出函数
	ostream &arr_out(ostream &os) const;
public:
	//内联函数
	Student() : name("Null Name"), scores() {}
	explicit Student(const string &s) : name(s), scores() {}
	explicit Student(int n) : name("Nully"), scores(n) {}
	Student(const string &s, const ArrayDb &a) : name(s), scores(a) {}
	Student(const char *str, const double *pd, int n) : name(str), scores(pd, n) {}
	~Student() {}
	//声明
	double Average() const;
	const string &Name() const;
	double &operator[](int i);//use valarray<double>::operator[]()
	double operator[](int i) const;
	//友元函数
	friend istream &operator>>(istream &is, Student &stu);
	friend istream &getline(istream &is, Student &stu);
	friend ostream &operator<<(ostream &os, const Student &stu);
};
#endif