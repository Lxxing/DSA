/******************************************************************************************
* Binary Search Tree 
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正 xiaoxiaomiantianwo@163.com
******************************************************************************************/
#ifndef __SPLAY_BINARY_SEARCH_TREE__H_
#define __SPLAY_BINARY_SEARCH_TREE__H_

#include <BST/BST.h>


template <typename T>
class Splay : public BST<T>
{
public:
	BinTreeNodePtr & Search( const T& );
	BinTreeNodePtr Insert(const T &);
	bool Remove(const T &);
protected:
   BinTreeNodePtr SplayTree( BinTreeNodePtr v ); //将节点v伸展至根
};


#include "SplayImpl.h"


#endif //__SPLAY_BINARY_SEARCH_TREE__H_



