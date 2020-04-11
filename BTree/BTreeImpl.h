/******************************************************************************************
** RMQ4CPP
** Auther : luxiang
** github:https://github.com/Lxxing?tab=repositories
** 欢迎交流指正 xiaoxiaomiantianwo@163.com
******************************************************************************************/
#ifndef _B_TREE_IMPLEMENTATION__H_
#define _B_TREE_IMPLEMENTATION__H_
	
	
template <typename T>
BTree<T>::BTree(int orderNumber)
	:order(orderNumber),size(0)
{}

template <typename T>
BTree<T>::~BTree()
{
	if (NULL != root)
	{
		delete root;
	}
}

template <typename T>
int BTree<T>::Size() const
{
	return size;
}


template <typename T>
bool BTree<T>::Empty() const
{
	return root == NULL ? true : false;
}

template <typename T>
BTreeNodePtr BTree<T>::Root() const
{
	return root;
}

template <typename T>
BTreeNodePtr BTree<T>::InsertRoot(T const &e)
{
	size++;
	root = new BTreeNode<T>(e);
	return root;
}

template <typename T>//去掉子树的节点，递归释放
int BTree<T>::Remove( BTreeNodePtr node)
{
	FromParentTo(node) = NULL;//父节点引用置空，切除自己
	UpdateAncestor(node->parent);
	int n = RemoveRecursive(node);
	size -= n;
	delete node;
	return n;
}
template <typename T>//去掉子树的节点，递归释放
int BTree<T>::RemoveRecursive( BTreeNodePtr node)
{
	//递归基,空树
	if (NULL == node)
	{
		return 0;
	}
	int rnt = 1 + RemoveRecursive(node->lChild) + RemoveRecursive(node->rChild);
	delete node;
	return rnt;
}



	
#endif //_B_TREE_IMPLEMENTATION__H_
	
	

