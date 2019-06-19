#ifndef DOUBLY_LINKED_LIST_H_
#define DOUBLY_LINKED_LIST_H_
//https://www.cnblogs.com/skywang12345/p/3561803.html
#define SAFE_FREE(p) if (p) { delete (p); (p) = nullptr; };
#define SAFE_FREE_ARRAY(p) if (p) { delete[] (p); (p) = nullptr; };

// Ë«ÏòÁ´±í
template<typename TYPE>
struct Node
{
	Node():preNode(nullptr), nextNode(nullptr)
	{}
	Node* preNode;
	Node* nextNode;
	TYPE data;
};

typedef Node<int> DoublyNode;

class DoublyLinkedList
{
public:
	DoublyLinkedList():m_Length(0)
	{
		m_List->preNode = nullptr;
		m_List->nextNode = nullptr;
		m_List = nullptr;
	};

	bool clear();
	bool empty();
	bool erase(DoublyNode* pNode);
	bool insert(DoublyNode* preNode, DoublyNode* pNode);
	bool push(DoublyNode* pNode);
	int length();
private:
	DoublyNode* m_List;
	int m_Length;
};


#endif //DOUBLY_LINKED_LIST_H_