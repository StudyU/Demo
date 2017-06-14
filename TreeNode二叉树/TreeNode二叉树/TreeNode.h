/************************************************************************/
/* 创建树节点，将左右节点设置为空                                       */
/************************************************************************/
#ifndef TREE_NODE_H_
#define  TREE_NODE_H_

// 模板类的约束模板友元函数
// 声明树，友元来调用此树节点
template<class NODETYPE> class Tree;

template<class NODETYPE>
class TreeNode
{
	// 将友元函数的类模板参数的类型声明具体化
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