/******************************************************************************************
** RMQ4CPP
** Auther : luxiang
** github:https://github.com/Lxxing?tab=repositories
** 欢迎交流指正 xiaoxiaomiantianwo@163.com
******************************************************************************************/
#ifndef _B_TREE_IMPLEMENTATION__H_
#define _B_TREE_IMPLEMENTATION__H_

#include <iterator>
#include <algorithm>

	
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
BTreeNodePtr BTree<T>::Search(const T &e)
{
	BTreeNodePtr pHead = root;
	hot = NULL;

	while (pHead)
	{
		vector<T>::iterator item = find(pHead->key.begin(),pHead->key.end(),e);
		int index = (int)distance(item,pHead->key.begin());
		if(index >= 0 && item != pHead->key.end())
		{
			return pHead;
		}
		else
		{
			hot = pHead;
			pHead = pHead->child[index + 1];//child长度总比key多一
		}
	}
	return NULL;
}


template <typename T>
bool BTree<T>::Insert(const T &e)
{
	BTreeNodePtr node = this->Search(e);
	if (node)
	{
		return false;
	}

	int index = -1;
	vector<T>::iterator item = hot->key.begin();
	for (; item < hot->key.end(); ++item)
	{
		if (*item < e)
		{
			index = (int)distance(item,hot->key.begin());
			break;
		}
	}
	 
	hot->key.insert(item, e);

	vector<BTreeNodePtr >::iterator nodeIter = hot->child.begin();
	while (index + 2 > 0)
	{
		nodeIter++;
		index--;
	}
	hot->child.insert(nodeIter, NULL);
	size++;
	OverFlow(hot);

	return true;
}


template <typename T>
bool BTree<T>::Remove(const T &e)
{
	BTreeNodePtr node = this->Search(e);
	if (NULL == node)
	{
		return false;
	}

	size--;
	
	return true;
}

template <typename T>
void BTree<T>::OverFlow(BTreeNodePtr v)
{
	if (order >= v->child.size())
	{
		return;
	}

	int pivot = order >> 1;

	BTreeNodePtr newNode = new BTreeNode<T>();
	for ( int j = 0; j < order - pivot - 1; j++ ) 
	{
		newNode->child.push_back(v->child[pivot+1]);
		newNode->key.push_back(v->key[pivot+1]);
		//remove v->key ,v->child
		newNode->child[j]->parent = newNode;
    }
	BTreeNodePtr parentNode = v->parent;
	if (!parentNode)
	{
		root = parentNode = new BTreeNode<T>(); 
		parentNode->child[0] = v; 
		v->parent = parentNode; 
	}
	vector<T>::iterator keyIter = find(parentNode->key.begin(),parentNode->key.end(),v->key[0]);
	parentNode->key.insert(keyIter,v->key[pivot]);
	//parentNode->child.insert(keyIter++,newNode);
	newNode->parent = parentNode;

	OverFlow(parentNode);
}

template <typename T>
void BTree<T>::UnderFlow(BTreeNodePtr)
{

}

	
#endif //_B_TREE_IMPLEMENTATION__H_
	
	

