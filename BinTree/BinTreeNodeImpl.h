#ifndef _BIN_TREE_NODE_IMPLEMENTATION__H_
#define _BIN_TREE_NODE_IMPLEMENTATION__H_


template <typename T>
BinTreeNode<T>::BinTreeNode()
	:parent(NULL),height(0),lChild(NULL),rChild(NULL)
{

}

template <typename T>//初始化高度为叶子节点
BinTreeNode<T>::BinTreeNode(T e,BinTreeNodePtr pare)
	:data(e),parent(pare),height(0),lChild(NULL),rChild(NULL)
{
}


template <typename T>
BinTreeNode<T>::~BinTreeNode()
{

}

template <typename T>
int BinTreeNode<T>::Size()
{
	int res = 1;
	if (this->lChild)
	{
		res += this->lChild->size();
	}
	if (this->rChild)
	{
		res += this->rChild->size();
	}
	return res;
}

template <typename T>
BinTreeNodePtr BinTreeNode<T>::InsertRChild(T const &e)
{
	this->rChild = new BinTreeNode(e,this);
	return this->rChild;
}

template <typename T>
BinTreeNodePtr BinTreeNode<T>::InsertLChild(T const &e)
{
	this->lChild = new BinTreeNode(e,this);
	return this->lChild;
}

#endif //_BIN_TREE_NODE_IMPLEMENTATION__H_

