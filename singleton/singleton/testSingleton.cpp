#include "testSingleton.h"
#include <windows.h>
int main()
{
	// AΪ�������������ɶ���
	//A a;
	A::getInstance()->aa();

	// B�������ɶ���
	B b;
	b.bb();
	BSingleton::getInstance()->bb();

	system("pause");
	return 0;
}