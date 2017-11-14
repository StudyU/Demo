#include <vector>
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <time.h>
using namespace std;
using std::ofstream;
using std::vector;

int main()
{
	/************************************************************************/
	/* vector如何强制释放内存空间											*/
	/* 默认只有析构时才会释放												*/
	/************************************************************************/
	vector<int> arr;
	cout << "默认情况未初始化时，capacity=" << arr.capacity() << endl;
	arr.resize(100, 100);
	arr.reserve(50);
	arr.resize(50);
	cout << "现在，capacity=" << arr.capacity() << endl;
	vector<int>::iterator itor = arr.begin() + 10;
	arr.erase(arr.begin(), itor);
	cout << "capacity=" << arr.capacity() << ",size=" << arr.size() << endl;
	// 	//方法一、
	vector<int>().swap(arr); //强制释放空间
							 //方法二、
	{
		vector<int> temp;
		arr.swap(temp);
	}//临时变量会被析构
	cout << "capacity=" << arr.capacity() << ",size=" << arr.size() << endl;
	clock_t start = clock();
	for (int num = 0; num<10000; ++num)
	{
		vector<int> v1;
		for (int i = 0; i<100; ++i)
			v1.push_back(i);
	}
	cout << "直接push循环10000次用时：" << clock() - start << endl;
	start = clock();
	for (int num = 0; num<10000; ++num)
	{
		vector<int> v2;
		v2.resize(100);
		for (int i = 0; i<100; ++i)
			v2[i] = i;
	}
	cout << "先resize预设大小再push循环10000次用时：" << clock() - start << endl;
	start = clock();
	for (int num = 0; num<10000; ++num)
	{
		vector<int> v3;
		v3.reserve(100);
		for (int i = 0; i<100; ++i)
			v3.push_back(i);
	}
	cout << "先reserve预设大小再push循环10000次用时：" << clock() - start << endl;
	vector<int> v4;
	ofstream wf("2.txt");
	int nFlag = v4.capacity();
	for (int i = 0; i<100; ++i)
	{
		v4.push_back(i);
		if (nFlag != v4.capacity())
		{
			nFlag = v4.capacity();
			cout << "new buffer size=" << nFlag << endl;
			wf << "capacity=" << nFlag << endl;
		}
	}
	wf.close();
	cout << "max_size=" << arr.max_size() << endl;
	return 0;
}