#include <iostream>
using namespace std;

//����һ��ȫ��Ϊpublic��ģ����
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
	ex a; //��������

	a.set(100);
	cout << "a.get():";
	cout << a.get() << endl;

	a.value = 200;
	cout << "a.value:";
	cout << a.get() << endl;
	return 0;
}