/************************************************************************/
/* �������ڵ㣬�����ҽڵ�����Ϊ��                                       */
/************************************************************************/
#ifndef TREE_NODE_H_
#define  TREE_NODE_H_

// ģ�����Լ��ģ����Ԫ����
// ����������Ԫ�����ô����ڵ�
template<class NODETYPE> class Tree;

template<class NODETYPE>
class TreeNode
{
	// ����Ԫ��������ģ������������������廯
	friend class Tree<NODETYPE>;
public:
	// 
	TreeNode(const NODETYPE& value)
		:leftPtr(0), data(value), right(0);

private:
	TreeNode< NODETYPE > *leftPtr;
	NODETYPE data;
	TreeNode< NODETYPE > *rightPtr;
};



















#endif