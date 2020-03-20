/******************************************************************************************
* Binary Search Tree 
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* ��ӭ����ָ�� xiaoxiaomiantianwo@163.com
******************************************************************************************/
#ifndef __BINARY_SEARCH_TREE__H_
#define __BINARY_SEARCH_TREE__H_

#include <BinTree/BinTree.h>


template <typename T>
class BST : public BinTree<T>
{
protected:
	BinTreeNodePtr hot; //�����С��ڵ�ĸ���

public:

	virtual BinTreeNodePtr& Search(const T &);
	virtual BinTreeNodePtr Insert(const T &);
	virtual bool Remove(const T &);

};


#include "BSTImpl.h"


#endif //__BINARY_SEARCH_TREE__H_

