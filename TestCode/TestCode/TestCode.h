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

// Ҳ���Գ���31��131��1313��13131��131313..  
// ����˵���˷��ֽ�Ϊλ���㼰�Ӽ����������Ч�ʣ��罫��ʽ���Ϊ��hash = hash << 7 + hash << 1 + hash + ch;  
// ����ʵ��Intelƽ̨�ϣ�CPU�ڲ��Զ��ߵĴ���Ч�ʶ��ǲ��ģ�  
// �ҷֱ������100�ڴε������������㣬���ֶ���ʱ�������Ϊ0�������Debug�棬�ֽ��λ�����ĺ�ʱ��Ҫ��1/3����  
// ��ARM����RISCϵͳ��û�в��Թ�������ARM�ڲ�ʹ��Booth's Algorithm��ģ��32λ�����˷����㣬����Ч��������йأ�  
// ������8-31λ��Ϊ1��0ʱ����Ҫ1��ʱ������  
// ������16-31λ��Ϊ1��0ʱ����Ҫ2��ʱ������  
// ������24-31λ��Ϊ1��0ʱ����Ҫ3��ʱ������  
// ������Ҫ4��ʱ������  
// ��ˣ���Ȼ��û��ʵ�ʲ��ԣ���������Ȼ��Ϊ����Ч���ϲ�𲻴� 
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

//��Ϊ��̬��Ա�������������࣬����ʵ��������֮ǰ���Ѿ�����ռ��ˣ�����ķǾ�̬��Ա��������ʵ�������������ڴ�ռ䣬����������þͳ����ˣ��ͺñ�û������һ������ȴ��ǰʹ����һ��
//����ָ������麯����ʱ�򣬼�ʹ�ǻ������͵�ָ�룬Ҳ����õ��������͵ĺ���
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

//Ϊ�˷�ֹ�����Ӱ�죬���������ඨ��һ���븸����ͬ�ľ�̬�����������θ����Ӱ��
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

// �����㷨
void TestAlgorithm()
{
	std::string str = "dgbj12";
	cout << "str:" << str << endl;
	// ����
	sort(str.begin(), str.end());
	cout << "����:" << str << endl;
	// ����
	sort(str.rbegin(), str.rend());
	cout << "����:" << str << endl;

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