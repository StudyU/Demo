#include <stdio.h>
#include <windows.h>
#include <string>
/*
https://blog.csdn.net/g5dsk/article/details/6680698
*/
typedef int(__cdecl* MYPROC)(int,int);
int main(int argc, char **argv)
{
	std::string str = "D:/GitHub/Demo/Dll/x64/Debug/Math.dll";
	// ��ʽ���ã�ʹ��LoadLibrary���붯̬���ӿ�-GetProcAddress��ȡĳ������ַ
	HMODULE hid = LoadLibraryExA(str.c_str(), NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
	if (hid == nullptr)
	{
		return 0;
	}
	MYPROC p = (MYPROC)GetProcAddress(hid, "Add");
	if (p == nullptr)
	{
		return 0;
	}
	int result = p(1, 2);
	printf("result = %d", result);
	return 0;
}