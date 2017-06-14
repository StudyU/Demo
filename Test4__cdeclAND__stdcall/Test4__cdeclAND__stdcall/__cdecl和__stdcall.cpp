#include "stdio.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;
/***********************************
__stdcall __cdecl都是修饰函数的调用方式的关键字。
两种调用方式都是从右向左将参数入栈。
__cdecl是C/C++的默认调用方式；__stdcall是WindowsAPI的默认调用方式。
对于可变参数的成员函数，始终使用__cdecl的转换方式。
__stdcall是由被调函数在执行结束时对堆栈进行清空的，而__cdecl调用形式是又主调代码对堆栈区进行清空的
***********************************/
int (__cdecl func_cdecl)(int param1, int param2)
{
	return 1;
}

int (__stdcall func_stdcall)(int parm1, int parm2)
{
	return 1;
}

int main()
{
	int a = func_cdecl(1, 2);
	a = func_stdcall(1, 2);

	return 0;
}