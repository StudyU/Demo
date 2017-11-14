#pragma once
/*
��� class ������Ϊ Stack<T>�� T��һ�� template parameter�����ڣ����ۺ�ʱ�������class������������ʱ����Ӧ��д�� Stack<T>
*/
#ifndef CLASS_TEMPLATE_H_
#define CLASS_TEMPLATE_H_

#include <vector>
using namespace std;

// Class Templates	������ģ��
template <typename T>
class Stack
{
public:
	void push(T const&);
	void pop();
	void clear();
	T top() const;
	bool empty() const {
		return elems.empty();
	}

private:
	vector<T> elems;	// Ԫ��
};

template <typename T>
void Stack<T>::push(T const& elem)
{
	elems.push_back(elem);	// ׷�ӣ�����β��
}

template <typename T>
void Stack<T>::clear()
{
	elems.clear();	// ���
}

template <typename T>
void Stack<T>::pop()
{
	if (elems.empty())
	{
		throw std::out_of_range("Stack<>::pop: empty stack");
		return;
	}

	elems.pop_back();	// �Ƴ����һ��Ԫ��
}

// �������Ԫ��
template <typename T>
T Stack<T>::top() const
{
	if (elems.empty())
	{
		throw std::out_of_range("Stack<>::top: empty stack");
	}

	return elems.back();	// �������һ��Ԫ�صĿ���
}

// Nontype Class Template Parameters ���������ģ�����
/*
�㲻�ܰѸ�����(double)�� class-type ����(string)���ڲ����ӣ�internal linkage�����������ַ�������
������ ���� nontype template parameters ���Ա���
*/
template <typename T, size_t MAXSIZE>
class NontypeStack
{
private:
	T elems[MAXSIZE];	// Ԫ��
	size_t numElems;		// ��ǰԪ�ظ���
public:
	NontypeStack();		// ���캯��
	void push(T const& elem);
	void pop();
	T top() const;
	bool empty() const {
		return numElems == 0;
	}

	bool full() const {
		return numElems == MAXSIZE;
	}
};

template<typename T, size_t MAXSIZE>
NontypeStack<T, MAXSIZE>::NontypeStack()
	: numElems(0)
{

}

template<typename T, size_t MAXSIZE>
void NontypeStack<T, MAXSIZE>::push(T const& elem)
{
	if (numElems >= MAXSIZE)
	{
		throw std::out_of_range("Stack<>::push: stack is full");
		return;
	}

	elems[numElems] = elem;
	++numElems;
}

template<typename T, size_t MAXSIZE>
void NontypeStack<T, MAXSIZE>::pop()
{
	if (numElems == 0)
	{
		throw std::out_of_range("Stack<>::push: stack is empty");
		return;
	}

	--numElems;
}

template<typename T, size_t MAXSIZE>
T NontypeStack<T, MAXSIZE>::top() const
{
	if (numElems == 0)
	{
		throw std::out_of_range("Stack<>::push: stack is empty");
		return NULL;
	}

	return elems[numElems - 1];
}
#endif	// CLASS_TEMPLATE_H_