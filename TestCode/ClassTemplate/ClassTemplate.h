#pragma once
/*
这个 class 的类型为 Stack<T>， T是一个 template parameter。现在，无论何时你以这个class声明变量或函数时，都应该写成 Stack<T>
*/
#ifndef CLASS_TEMPLATE_H_
#define CLASS_TEMPLATE_H_

#include <vector>
using namespace std;

// Class Templates	常规类模板
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
	vector<T> elems;	// 元素
};

template <typename T>
void Stack<T>::push(T const& elem)
{
	elems.push_back(elem);	// 追加（附于尾）
}

template <typename T>
void Stack<T>::clear()
{
	elems.clear();	// 清空
}

template <typename T>
void Stack<T>::pop()
{
	if (elems.empty())
	{
		throw std::out_of_range("Stack<>::pop: empty stack");
		return;
	}

	elems.pop_back();	// 移除最后一个元素
}

// 传回最顶端元素
template <typename T>
T Stack<T>::top() const
{
	if (elems.empty())
	{
		throw std::out_of_range("Stack<>::top: empty stack");
	}

	return elems.back();	// 传回最后一个元素的拷贝
}

// Nontype Class Template Parameters 非类型类别模板参数
/*
你不能把浮点数(double)、 class-type 对象(string)、内部链接（internal linkage）对象（例如字符串字面
常数） 当作 nontype template parameters 的自变量
*/
template <typename T, size_t MAXSIZE>
class NontypeStack
{
private:
	T elems[MAXSIZE];	// 元素
	size_t numElems;		// 当前元素个数
public:
	NontypeStack();		// 构造函数
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