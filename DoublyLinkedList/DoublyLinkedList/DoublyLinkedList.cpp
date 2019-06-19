#include "DoublyLinkedList.h"

bool DoublyLinkedList::clear()
{
	if (m_List)
	{
		// 向前清空
		DoublyNode* pPre = m_List->preNode;
		while (pPre)
		{
			SAFE_FREE(pPre);
			pPre = pPre->preNode;
		}

		// 向后清空
		DoublyNode* pNext = m_List->nextNode;
		while (pNext)
		{
			SAFE_FREE(pNext);
			pNext = pNext->nextNode;
		}

		SAFE_FREE(m_List);
	}

	m_Length = 0;

	return true;
}

bool DoublyLinkedList::empty()
{
	return m_Length == 0;
}

bool DoublyLinkedList::erase(DoublyNode* pNode)
{
	pNode->preNode->nextNode = pNode->nextNode;
	pNode->nextNode->preNode = pNode->preNode;
	SAFE_FREE(pNode);

	return true;
}

bool DoublyLinkedList::push(DoublyNode* pNode)
{
	pNode->preNode = m_List;
	m_List->nextNode = pNode;
	m_List = pNode;
	return true;
}

bool DoublyLinkedList::insert(DoublyNode* preNode, DoublyNode* pNode)
{

	return true;
}

int DoublyLinkedList::length()
{
	int n = 0;

	return n;
}