/******************************************************************************************
* Binary Search Tree 
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正 xiaoxiaomiantianwo@163.com
******************************************************************************************/
#ifndef __BINARY_SEARCH_TREE__H_
#define __BINARY_SEARCH_TREE__H_

#include <BinTree/BinTree.h>


template <typename T>
class BST : public BinTree<T>
{
protected:
	BinTreeNodePtr hot; //“命中”节点的父亲

public:

	virtual BinTreeNodePtr& Search(const T &);
	virtual BinTreeNodePtr Insert(const T &);
	virtual bool Remove(const T &);

};


#include "BSTImpl.h"


#endif //__BINARY_SEARCH_TREE__H_

