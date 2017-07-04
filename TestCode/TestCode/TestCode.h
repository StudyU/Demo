#pragma once
#ifndef __TEST_CODE_H_
#define __TEST_CODE_H_
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 也可以乘以31、131、1313、13131、131313..  
// 有人说将乘法分解为位运算及加减法可以提高效率，如将上式表达为：hash = hash << 7 + hash << 1 + hash + ch;  
// 但其实在Intel平台上，CPU内部对二者的处理效率都是差不多的，  
// 我分别进行了100亿次的上述两种运算，发现二者时间差距基本为0（如果是Debug版，分解成位运算后的耗时还要高1/3）；  
// 在ARM这类RISC系统上没有测试过，由于ARM内部使用Booth's Algorithm来模拟32位整数乘法运算，它的效率与乘数有关：  
// 当乘数8-31位都为1或0时，需要1个时钟周期  
// 当乘数16-31位都为1或0时，需要2个时钟周期  
// 当乘数24-31位都为1或0时，需要3个时钟周期  
// 否则，需要4个时钟周期  
// 因此，虽然我没有实际测试，但是我依然认为二者效率上差别不大 
template<typename T>
size_t GetHashValue(const T* str)
{
	register size_t hash = 0;
	while (size_t ch = *str++)
	{
		hash = hash * 131 + ch;
	}

	return hash;
}

//因为静态成员函数属于整个类，在类实例化对象之前就已经分配空间了，而类的非静态成员必须在类实例化对象后才有内存空间，所以这个调用就出错了，就好比没有声明一个变量却提前使用它一样
//当用指针调用虚函数的时候，即使是基类类型的指针，也会调用到派生类型的函数
class A
{
public:
	A()
	{

	}
	~A() {};
public:
	static void teststatic()
	{
		cout << "A static" << endl;
	};

	virtual void testvirtual()
	{
		cout << "A virtual" << endl;
	}


};

//为了防止父类的影响，可以在子类定义一个与父类相同的静态变量，以屏蔽父类的影响
class B : public A
{
public:
	B() { m_pThis = this; }
	~B() {};

public:
	static void teststatic()
	{
		cout << "B static" << endl;
	}

	//void testvirtual()
	//{
	//	cout << "B virtual" << endl;
	//}

	static B* m_pThis;
};

// 测试算法
void TestAlgorithm()
{
	std::string str = "dgbj12";
	cout << "str:" << str << endl;
	// 升序
	sort(str.begin(), str.end());
	cout << "升序:" << str << endl;
	// 降序
	sort(str.rbegin(), str.rend());
	cout << "降序:" << str << endl;

	int n = min(5, 10);
	cout << "Min:" << n << endl;
	int m = max(5, 10);
	cout << "Max:" << m << endl;
}

void TestVector()
{
	vector<int> vecInt;
	for (int i = 0; i < 10; i++)
	{
		vecInt.push_back(i);
	}

	for (auto k : vecInt)
	{
		cout << "vecInt every num:" << k << endl;
	}
}

void TestOperate()
{
	int n = 5;
	int m = n % 10;

	cout << "Get%:" << m << endl;
}














#endif // !__TEST_CODE_H_