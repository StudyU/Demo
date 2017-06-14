#include <iostream>
#include <string>
using namespace std;

template <typename T>
//引用比指针效率高
void swap(T &val1, T &val2)
{
	T temp;
	temp = val1;
	val1 = val2;
	val2 = temp;
}

struct student
{
	char name[30];
	int num;
	float grade;
};

int main()
{
	int i = 4;
	int j = 5;
	char c1 = 'A';
	char c2 = 'B';
	string st1("You are best!");
	string st2("Yes you right!");

	//明确使用全局范围定义的模板函数。不用::会与STL中的重用
	::swap(i,j);
	::swap(c1, c2);
	::swap(st1, st2);
	
	cout << i << j << endl;
	cout << c1 << c2 << endl;
	cout << st1 << st2 << endl;

	student stu1={"liuyifei", 1, 100};
	student stu2={"yaoxin", 2, 99};

	::swap(stu1, stu2);
	cout << stu1.name <<" "<< stu1.num << " " << stu1.grade << endl;
	cout << stu2.name <<" "<< stu2.num << " " << stu2.grade << endl;
	return 0;

}