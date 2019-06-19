/*****************************************************
*�ļ�����LinkedList.h
*���ܣ�ʵ��˫������Ļ�������
*ע�⣺Ϊ��ʹ���ճ���ִ�еø��죬����Debugģʽ�¼������Ϸ��ԡ�
*���ⲻ���ڴ����ʧ��������,��Ϊһ�������Ӧ�ó����н�2GB�������õĿռ�
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
		T data; //������,��Ҫ����T��ʵ�������޲ι��캯��
		Node* prior; //ָ��ǰһ�����
		Node* next; //ָ����һ�����
		Node(const T& element, Node*& pri, Node*& nt) :data(element), next(nt), prior(pri) {}
		Node() :data(data) {}//����T��ʵ����ĸ��ƹ��캯����������.��Vc2010���Կ���
	};
	Node* head; //ָ���һ�����
public:
	//��ʼ��������һ���ս�㣬�����
	LinkedList() :head(new Node()) { head->prior = head->next = head; }
	//��ȡԪ������
	int elementToatal()const;
	//�ж��Ƿ�Ϊ����
	bool isEmpty()const { return head == head->next ? true : false; }
	//��Ԫ����������ע��node��ָ������
	void addToLast(const T& element) { Node* ne = new Node(element, head->prior, head); head->prior = head->prior->next = ne; }
	//��ȡ���һ��Ԫ��
	T getLastElement()const { assert(!isEmpty()); return head->prior->data; }
	//ɾ�����һ��Ԫ�أ�ע��node��ָ������
	void delLastElement() { assert(!isEmpty()); Node* p = head->prior->prior; delete head->prior; head->prior = p; p->next = head; }
	//�޸����һ��Ԫ��
	void alterLastEmlent(const T& newElement) { assert(!isEmpty()); head->prior->data = newElement; }
	//����Ԫ��
	void insertElement(const T& element, int position);
	//��ȡԪ��
	T getElement(int index)const;
	//ɾ��Ԫ��
	T delElement(int index);
	//�޸�Ԫ��
	void alterElement(const T & Newelement, int index);
	//����Ԫ��
	int findElement(const T& element) const;
	//�������
	void Traverse(void(*visit)(T&element));
	//�������
	void TraverseBack(void(*visit)(T&element));
	//����[]����
	T& operator [](int index);
	//�������
	void clearAllElement();
	//��������
	~LinkedList();
};
/***************************************
*����Ԫ������
****************************************/
template<class T>
int LinkedList<T>::elementToatal()const
{
	int Total = 0;
	for (Node* p = head->next; p != head; p = p->next) ++Total;
	return Total;
}
/**********************************************
*��positionָ����λ�ò���Ԫ�ء�ԭ��position�������Ԫ
*�غ���
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
	//��ʱpָ��Ҫ����Ľ��
	Node* pNew = new Node(element, p->prior, p);
	p->prior = p->prior->next = pNew;
}
/***************************************
*�����ҵ���Ԫ�صĸ���
***************************************/
template<class T>
T LinkedList<T>::getElement(int index)const
{
	assert(index > 0 && index <= elementToatal() && !isEmpty());//λ�������Ƿ�Ϸ�,�����Ƿ��
	Node* p = head->next;
	while (--index) p = p->next;
	return p->data;
}
/**********************************
*ɾ��ָ��Ԫ�أ���������
**********************************/
template<class T>
T LinkedList<T>::delElement(int index)
{
	assert(index > 0 && index <= elementToatal() && !isEmpty());//λ�������Ƿ�Ϸ�,�����Ƿ��
	Node* del = head->next;
	while (--index) del = del->next;
	//��ʱpָ��Ҫɾ��Ԫ��
	del->prior->next = del->next;
	del->next->prior = del->prior;
	T delData = del->data;
	delete del;
	return delData;
}
/****************************************
*��Newelement��������Ϊindex��Ԫ��
*****************************************/
template<class T>
void LinkedList<T>::alterElement(const T & Newelement, int index)
{
	assert(index > 0 && index <= elementToatal() && !isEmpty());//λ�������Ƿ�Ϸ�,�����Ƿ��
	Node* p = head->next;
	while (--index) p = p->next;
	p->data = Newelement;
}
/********************************
*�ҵ�����Ԫ�ص����������򷵻�0
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
*�����������������ÿ��Ԫ����Ϊ��������visit����
*****************************************/
template<class T>
void LinkedList<T>::Traverse(void(*visit)(T&element))
{
	Node* p = head->next;
	while (p != head)
	{
		visit(p->data);//ע���ʱ�ⲿvisit������Ȩ���޸�LinkedList<T>��˽������
		p = p->next;
	}
}
/*************************************************
*�����������������ÿ��Ԫ����Ϊ��������visit����
*************************************************/
template<class T>
void LinkedList<T>::TraverseBack(void(*visit)(T&element))
{
	Node* p = head->prior;
	while (p != head)
	{
		visit(p->data);//ע���ʱ�ⲿvisit������Ȩ���޸�LinkedList<T>��˽������
		p = p->prior;
	}
}
/**************************************************
*���������Ԫ�����ã����ɶ�д.ʵ��������û��[]�����ϵ����й���
*���[]�����������Ƶ�.��������Ϊ�˿ͻ��˴����࣬��Ϊ�������д
*��������õ�
***************************************************/
template<class T>
T& LinkedList<T>::operator [](int index)
{
	assert(index > 0 && index <= elementToatal() && !isEmpty());//[]����ʹ��ǰ������
	Node* p = head->next;
	while (--index) p = p->next;
	return p->data;
}
/***************************
*�������
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
	head->prior = head->next = head;//��β����
}
/******************************
*�������������ڴ��㹻û��Ҫ���øú���
*******************************/
template<class T>
LinkedList<T>::~LinkedList()
{
	if (head)//��ֹ�û���ʽ�����󣬶����ָպó����������ٵ��øú���
	{
		clearAllElement();
		delete head;
		head = 0;
	}
}
