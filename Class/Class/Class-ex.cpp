#include <iostream>
using namespace std;

//定义一个全部为public的模板类
class ex
{
public:
	int value;
	void set(int n){
		value = n;
	}
	int get(void){
		return value;
	}
};

int main()
{
	ex a; //创建对象

	a.set(100);
	cout << "a.get():";
	cout << a.get() << endl;

	a.value = 200;
	cout << "a.value:";
	cout << a.get() << endl;
	return 0;
}