#include <iostream>
using namespace std;

//Y��Ĳ���ȫ����
class Y;

class X
{
public:
	void disp(Y py, const char *name );//��Ա����ԭ��
};

class Y
{
	friend void X::disp(Y py, const char *name );
	friend void putY(Y &yc, const char *name);
private:
	int num;
	void dispY(const char *name)
	{
		cout << name << "num: " << num << endl;
	}

public:
	Y(int n)
	{
		num = n;
	}

};

void X::disp(Y py, const char *name)
{
	cout << "In X::disp= " << endl;
	py.dispY(name);
}

void putY(Y &yc, const char *name)
{
	cout << "In puty= " << endl;
	yc.dispY(name);
	cout << "name= " << name 
		<< "num= " << yc.num << endl;
}

int main()
{
	Y y1(100), y2(200);
	X x1;
	//������Y���е�˽�г�Ա������ʾ
	//���еĿ���ʹ��
	//y1.dispY("y1: ");
	//y2.dispY("y2: ");

	//����X��������Ԫ����������ʾ
	x1.disp(y1, "y1 ");
	cout << endl;
	x1.disp(y2, "y2 ");
	cout << endl;

	putY(y1, "y1 ");
	cout << endl;
	putY(y2, "y2 ");

	return 0;
}