#include "stdio.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;
/***********************************
__stdcall __cdecl�������κ����ĵ��÷�ʽ�Ĺؼ��֡�
���ֵ��÷�ʽ���Ǵ������󽫲�����ջ��
__cdecl��C/C++��Ĭ�ϵ��÷�ʽ��__stdcall��WindowsAPI��Ĭ�ϵ��÷�ʽ��
���ڿɱ�����ĳ�Ա������ʼ��ʹ��__cdecl��ת����ʽ��
__stdcall���ɱ���������ִ�н���ʱ�Զ�ջ������յģ���__cdecl������ʽ������������Զ�ջ��������յ�
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