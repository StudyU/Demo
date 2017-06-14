#include <iostream>
using namespace std;

class You
{
private:
	//可以访问私有变量
	friend class me;
	int num;
public:
	You(int n)
	{
		num = n;
	}
	~You()
	{
	}

	void display(char *name)
	{
		cout << name << "num:" << num << endl;
	}

};

class me
{
public:
	me()
	{
	}
	~me()
	{
	}

	void display1(You &m, char *name)
	{
		cout << name << "num:" << m.num << endl;
	}
	
	void display2(You &m, char *name)
	{
		m.display(name);
	}
	
};

int main()
{
	You y1(3);
	You y2(7);
	y1.display("Your y1 ");
	y2.display("Your y2 ");

	me m1;
	m1.display1(y1, "friend y1 ");
	m1.display2(y2, "friend y2 ");

	return 0;
}