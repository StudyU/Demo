#ifndef LIST_H_
#define LIST_H_

#include "listnd.h"
#include <iostream>
#include <cassert>

using namespace std;

template<class NODETYPE>
class List
{
public:
	List():firstPtr(0),lastPtr(0) {};
	~List();
	void InsertAtFront(const NODETYPE &);
	void InsertAtBack(const NODETYPE &);
	bool RemoveFromFront(NODETYPE &);
	bool RemoveFromBack(NODETYPE &);
	bool IsEmpty() const;
	void print() const;
private:
	ListNode<NODETYPE> *firstPtr;
	ListNode<NODETYPE> *lastPtr;
	ListNode<NODETYPE> *getNewNode(const NODETYPE &);
};

template<class NODETYPE>
List<NODETYPE>::~List()
{
	if (!IsEmpty())
	{
		cout << "Destroying Nodes...\n";
	}

	ListNode<NODETYPE> *currentPtr = firstPtr;

	while (currentPtr!=0)
	{
		ListNode<NODETYPE> *temPtr;
		temPtr = currentPtr;
		cout << temPtr->data << endl;
		currentPtr = currentPtr->nextPtr;
		delete temPtr;
	}

	cout << "All Nodes Destroied\n\n";
}

template<class NODETYPE> 
void List<NODETYPE>::InsertAtFront(const NODETYPE &value)
{
	ListNode<NODETYPE> *newPtr = getNewNode(value);
	if (IsEmpty())
	{
		firstPtr = lastPtr = newPtr;
	}
	else
	{
		newPtr->nextPtr = firstPtr;
		firstPtr = newPtr;
	}
}

template<class NODETYPE>
void List<NODETYPE>::InsertAtBack(const NODETYPE &value)
{
	ListNode<NODETYPE> *newPtr = getNewNode(value);
	if (IsEmpty())
	{
		firstPtr = lastPtr = newPtr;
	}
	else
	{
		lastPtr->nextPtr = newPtr;
		lastPtr = newPtr;
	}
}
template<class NODETYPE>
bool List<NODETYPE>::RemoveFromFront(NODETYPE &value)
{
	if (IsEmpty())
	{
		return false;
	}
	else
	{
		ListNode<NODETYPE> *temPtr = firstPtr;
		if (firstPtr==lastPtr)
		{
			firstPtr = lastPtr = 0;
		}
		else
		{
			firstPtr = firstPtr->nextPtr;
		}
		value = temPtr->data;
		delete temPtr;
		return true;
	}
	
}
template<class NODETYPE>
bool List<NODETYPE>::RemoveFromBack(NODETYPE &value)
{
	if (IsEmpty())
	{
		return false;
	}
	else
	{
		ListNode<NODETYPE> *newPtr = lastPtr;

		if (firstPtr == lastPtr)
		{
			firstPtr = lastPtr = 0;
		}
		else
		{
			ListNode<NODETYPE> *temPtr = firstPtr;
			while (temPtr->nextPtr!=lastPtr)
			{
				temPtr = temPtr->nextPtr;
			}
			lastPtr = temPtr;
			temPtr->nextPtr = 0;
		}
		value = newPtr->data;
		delete newPtr;
		return true;
	}
}

template<class NODETYPE>
bool List<NODETYPE>::IsEmpty() const
{
	return firstPtr==0;
}

template<class NODETYPE>
void List<NODETYPE>::print() const
{
	if (IsEmpty())
	{
		cout << "The List is Empty!\n\n";
	}
	
	ListNode<NODETYPE> *temPtr = firstPtr;
	cout << "The List is: " ;
	while (temPtr!=0)
	{
		cout << temPtr->data << " ";
		temPtr = temPtr->nextPtr;
	}

	cout << "\n\n";
}

template<class NODETYPE>
ListNode<NODETYPE> *List<NODETYPE>::getNewNode(const NODETYPE &value)
{
	ListNode<NODETYPE> *ptr = new ListNode<NODETYPE> (value);
	assert(ptr != 0);
	return ptr;
}

#endif