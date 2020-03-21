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
	 //对node及其父亲、祖父做统一旋转调整,为了各个特例继承
	BinTreeNodePtr RotateAt(BinTreeNodePtr node);
	//按照“3 + 4”结构，联接3个节点及四棵子树
	BinTreeNodePtr Connect34(BinTreeNodePtr,BinTreeNodePtr, BinTreeNodePtr,
		BinTreeNodePtr, BinTreeNodePtr, BinTreeNodePtr, BinTreeNodePtr );

public:

	virtual BinTreeNodePtr& Search(const T &);
	virtual BinTreeNodePtr Insert(const T &);
	virtual bool Remove(const T &);

};


#include "BSTImpl.h"


#endif //__BINARY_SEARCH_TREE__H_

