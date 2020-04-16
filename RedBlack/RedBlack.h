/******************************************************************************************
* Binary Search Tree 
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正 xiaoxiaomiantianwo@163.com
******************************************************************************************/
#ifndef __RED_BLACK_BINARY_SEARCH_TREE__H_
#define __RED_BLACK_BINARY_SEARCH_TREE__H_

#include <BST/BST.h>


#define IsBlack(node) ( !(node) || (RB_BLACK == (node)->color) )//外部节点也视作黑节点
#define IsRed(node) ( !IsBlack(node) ) 

/*RedBlack高度更新条件*/
#define BlackHeightUpdated(x) ( \
   ( HEIGHT( (x).lChild ) == HEIGHT( (x).rChild ) ) && \
   ( (x).height == ( IsRed(& x) ? HEIGHT( (x).lChild) : HEIGHT( (x).lChild) + 1 ) ) \
)

/*叔叔*/ 
#define Uncle(x)\
   ( IsLChild( * ((x)->parent)) ? (x)->parent->parent->rChild : (x)->parent->parent->lChild )

template <typename T>
class RedBlack : public BST<T>
{

protected:
   void SolveDoubleRed(BinTreeNodePtr node);
   void SolveDoubleBlack(BinTreeNodePtr node);
   int UpdateHeight(BinTreeNodePtr node);

public:

	BinTreeNodePtr Insert(const T &);
	bool Remove(const T &);

};


#include "RedBlackImpl.h"


#endif //__RED_BLACK_BINARY_SEARCH_TREE__H_



