/******************************************************************************************
* Binary Search Tree 
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* ��ӭ����ָ�� xiaoxiaomiantianwo@163.com
******************************************************************************************/
#ifndef __BINARY_SEARCH_TREEIMPL__H_
#define __BINARY_SEARCH_TREEIMPL__H_


template <typename T>
static BinTreeNodePtr& SearchRec(BinTreeNodePtr & v,const T &e,BinTreeNodePtr &hot)
{
	//�ݹ��
	if (NULL == v || e == v->data)
	{
		return v;
	}
	hot = v;//��¼����ǰ�Ľڵ�����
	return e < v->data ? SearchRec(v->lChild,e,hot) : SearchRec(v->rChild,e,hot);
}
/*
�ɹ����������нڵ�e
ʧ�ܣ�����NULL,
*/
template <typename T>
BinTreeNodePtr &BST<T>::Search(const T &e)
{
	return SearchRec(this->root,e,hot);
}

template <typename T>
BinTreeNodePtr BST<T>::Insert(const T &e)
{
	BinTreeNodePtr node = this->Search(e);
	if (node)
	{
		return node;//�ڵ����
	}

	node = new BinTreeNode<T>(e,hot);
	size++;
	UpdateHeight(node);
	return node;//node->data == e
}

template <typename T>
bool BST<T>::Remove(const T &e)
{
	BinTreeNodePtr node = this->Search(e);
	if (NULL == node)
	{
		return false;//�ڵ㲻����
	}

	//node = new BinTreeNode<T>(e,hot);
	size--;
	UpdateHeight(node);
	return true;
}


#endif //__BINARY_SEARCH_TREEIMPL__H_

