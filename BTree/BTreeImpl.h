/******************************************************************************************
** RMQ4CPP
** Auther : luxiang
** github:https://github.com/Lxxing?tab=repositories
** ��ӭ����ָ�� xiaoxiaomiantianwo@163.com
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

template <typename T>//ȥ�������Ľڵ㣬�ݹ��ͷ�
int BTree<T>::Remove( BTreeNodePtr node)
{
	FromParentTo(node) = NULL;//���ڵ������ÿգ��г��Լ�
	UpdateAncestor(node->parent);
	int n = RemoveRecursive(node);
	size -= n;
	delete node;
	return n;
}
template <typename T>//ȥ�������Ľڵ㣬�ݹ��ͷ�
int BTree<T>::RemoveRecursive( BTreeNodePtr node)
{
	//�ݹ��,����
	if (NULL == node)
	{
		return 0;
	}
	int rnt = 1 + RemoveRecursive(node->lChild) + RemoveRecursive(node->rChild);
	delete node;
	return rnt;
}



	
#endif //_B_TREE_IMPLEMENTATION__H_
	
	

