#ifndef LISTND_H_
#define LISTND_H_

template<class NODETYPE> class List;

template<class NODETYPE> 
class ListNode
{
	friend class List<NODETYPE>;//友元类
public:
	ListNode(const NODETYPE &info):data(info),nextPtr(0) {}//构造函数

	NODETYPE getData()const {return data}//返回节点里的数据
private:
	NODETYPE data;
	ListNode<NODETYPE> *nextPtr; 
};

#endif