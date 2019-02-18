#include "testSingleton.h"
#include <windows.h>
int main()
{
	// A为单例，不能生成对象
	//A a;
	A::getInstance()->aa();

	// B还能生成对象
	B b;
	b.bb();
	BSingleton::getInstance()->bb();

	system("pause");
	return 0;
}