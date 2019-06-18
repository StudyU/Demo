#ifndef DOUBLY_LINKED_LIST_H_
#define DOUBLY_LINKED_LIST_H_

// Ë«ÏòÁ´±í
struct Node
{
	Node():preNode(nullptr), nextNode(nullptr), data(0)
	{}
	Node* preNode;
	Node* nextNode;
	int data;
	int index;
};

class DoublyLinkedList
{
public:
	bool init();
	bool clear();
	bool empty();
	bool erase(Node* pNode);
	bool insert(Node* preNode, Node* pNode);
	bool push(Node* pNode);
	int length();
private:
	Node* m_List;
	int m_Length;
};


#endif //DOUBLY_LINKED_LIST_H_