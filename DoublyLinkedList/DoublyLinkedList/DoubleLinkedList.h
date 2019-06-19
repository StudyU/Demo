/*****************************************************
*文件名：LinkedList.h
*功能：实现双向链表的基本功能
*注意：为了使最终程序执行得更快，仅在Debug模式下检测操作合法性。
*另外不对内存分配失败作处理,因为一般情况下应用程序有近2GB真正可用的空间
*********************************************************/
#pragma once
#include <assert.h>
template<class T>
class LinkedList
{
private:
	class Node
	{
	public:
		T data; //数据域,不要求泛型T的实例类有无参构造函数
		Node* prior; //指向前一个结点
		Node* next; //指向下一个结点
		Node(const T& element, Node*& pri, Node*& nt) :data(element), next(nt), prior(pri) {}
		Node() :data(data) {}//泛型T的实例类的复制构造函数将被调用.在Vc2010测试可行
	};
	Node* head; //指向第一个结点
public:
	//初始化：构造一个空结点，搭建空链
	LinkedList() :head(new Node()) { head->prior = head->next = head; }
	//获取元素总数
	int elementToatal()const;
	//判断是否为空链
	bool isEmpty()const { return head == head->next ? true : false; }
	//将元素添加至最后，注意node的指针设置
	void addToLast(const T& element) { Node* ne = new Node(element, head->prior, head); head->prior = head->prior->next = ne; }
	//获取最后一个元素
	T getLastElement()const { assert(!isEmpty()); return head->prior->data; }
	//删除最后一个元素，注意node的指针设置
	void delLastElement() { assert(!isEmpty()); Node* p = head->prior->prior; delete head->prior; head->prior = p; p->next = head; }
	//修改最后一个元素
	void alterLastEmlent(const T& newElement) { assert(!isEmpty()); head->prior->data = newElement; }
	//插入元素
	void insertElement(const T& element, int position);
	//获取元素
	T getElement(int index)const;
	//删除元素
	T delElement(int index);
	//修改元素
	void alterElement(const T & Newelement, int index);
	//查找元素
	int findElement(const T& element) const;
	//正序遍历
	void Traverse(void(*visit)(T&element));
	//逆序遍历
	void TraverseBack(void(*visit)(T&element));
	//重载[]函数
	T& operator [](int index);
	//清空链表
	void clearAllElement();
	//销毁链表
	~LinkedList();
};
/***************************************
*返回元素总数
****************************************/
template<class T>
int LinkedList<T>::elementToatal()const
{
	int Total = 0;
	for (Node* p = head->next; p != head; p = p->next) ++Total;
	return Total;
}
/**********************************************
*在position指定的位置插入元素。原来position及后面的元
*素后移
***********************************************/
template<class T>
void LinkedList<T>::insertElement(const T& element, int position)
{
	assert(position > 0 && position <= elementToatal() + 1);
	Node* p = head;
	while (position)
	{
		p = p->next;
		position--;
	}
	//此时p指向要插入的结点
	Node* pNew = new Node(element, p->prior, p);
	p->prior = p->prior->next = pNew;
}
/***************************************
*返回找到的元素的副本
***************************************/
template<class T>
T LinkedList<T>::getElement(int index)const
{
	assert(index > 0 && index <= elementToatal() && !isEmpty());//位置索引是否合法,链表是否空
	Node* p = head->next;
	while (--index) p = p->next;
	return p->data;
}
/**********************************
*删除指定元素，并返回它
**********************************/
template<class T>
T LinkedList<T>::delElement(int index)
{
	assert(index > 0 && index <= elementToatal() && !isEmpty());//位置索引是否合法,链表是否空
	Node* del = head->next;
	while (--index) del = del->next;
	//此时p指向要删除元素
	del->prior->next = del->next;
	del->next->prior = del->prior;
	T delData = del->data;
	delete del;
	return delData;
}
/****************************************
*用Newelement代替索引为index的元素
*****************************************/
template<class T>
void LinkedList<T>::alterElement(const T & Newelement, int index)
{
	assert(index > 0 && index <= elementToatal() && !isEmpty());//位置索引是否合法,链表是否空
	Node* p = head->next;
	while (--index) p = p->next;
	p->data = Newelement;
}
/********************************
*找到返回元素的索引，否则返回0
********************************/
template<class T>
int LinkedList<T>::findElement(const T& element) const
{
	Node* p = head->next;
	int i = 0;
	while (p != head)
	{
		i++;
		if (p->data == element) return i;
		p = p->next;
	}
	return 0;
}
/***************************************
*正向遍历，以链表中每个元素作为参数调用visit函数
*****************************************/
template<class T>
void LinkedList<T>::Traverse(void(*visit)(T&element))
{
	Node* p = head->next;
	while (p != head)
	{
		visit(p->data);//注意此时外部visit函数有权限修改LinkedList<T>的私有数据
		p = p->next;
	}
}
/*************************************************
*反向遍历，以链表中每个元素作为参数调用visit函数
*************************************************/
template<class T>
void LinkedList<T>::TraverseBack(void(*visit)(T&element))
{
	Node* p = head->prior;
	while (p != head)
	{
		visit(p->data);//注意此时外部visit函数有权限修改LinkedList<T>的私有数据
		p = p->prior;
	}
}
/**************************************************
*返回链表的元素引用，并可读写.实际上链表没有[]意义上的所有功能
*因此[]函数是有限制的.重载它是为了客户端代码简洁，因为从链表读写
*数据是最常用的
***************************************************/
template<class T>
T& LinkedList<T>::operator [](int index)
{
	assert(index > 0 && index <= elementToatal() && !isEmpty());//[]函数使用前提条件
	Node* p = head->next;
	while (--index) p = p->next;
	return p->data;
}
/***************************
*清空链表
***************************/
template<class T>
void LinkedList<T>::clearAllElement()
{
	Node* p = head->next, *pTemp = 0;
	while (p != head)
	{
		pTemp = p->next;
		delete p;
		p = pTemp;
	}
	head->prior = head->next = head;//收尾工作
}
/******************************
*析构函数，若内存足够没必要调用该函数
*******************************/
template<class T>
LinkedList<T>::~LinkedList()
{
	if (head)//防止用户显式析构后，对象又刚好超出作用域再调用该函数
	{
		clearAllElement();
		delete head;
		head = 0;
	}
}
