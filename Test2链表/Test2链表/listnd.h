#ifndef LISTND_H_
#define LISTND_H_

template<class NODETYPE> class List;

template<class NODETYPE> 
class ListNode
{
	friend class List<NODETYPE>;//��Ԫ��
public:
	ListNode(const NODETYPE &info):data(info),nextPtr(0) {}//���캯��

	NODETYPE getData()const {return data}//���ؽڵ��������
private:
	NODETYPE data;
	ListNode<NODETYPE> *nextPtr; 
};

#endif