/******************************************************************************************
* Binary Search Tree 
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正 xiaoxiaomiantianwo@163.com
******************************************************************************************/
#ifndef __AVL_BINARY_SEARCH_TREE__H_
#define __AVL_BINARY_SEARCH_TREE__H_

#include <BST/BST.h>

//注释不能卸载\之后
//平衡因子
#define BalanceFactor(node)\
	( HEIGHT( (node).lChild ) - HEIGHT( (node).rChild) )

//AVL平衡条件
#define AVLBalance(node)\
	( ( -2 < BalanceFactor(node) ) && ( BalanceFactor(node) < 2 ) ) 

/******************************************************************************************
 * 在左、右孩子中取更高者, 在AVL平衡调整前，借此确定重构方案
 
 ******************************************************************************************/
#define GetChild(node) ( \
   HEIGHT((node)->lChild) > HEIGHT( (node)->rChild) ? (node)->lChild: ( 	/*左高*/\
   HEIGHT((node)->lChild ) < HEIGHT( (node)->rChild) ? (node)->rChild : /*右高*/\
   (IsLChild(*(node)) ? (node)->lChild : (node)->rChild) /*等高：与父亲x同侧者（zIg-zIg或zAg-zAg）优先*/\
   ) \
)

template <typename T>
class AVL : public BST<T>
{
public:

	BinTreeNodePtr Insert(const T &);
	bool Remove(const T &);

};


#include "AVLImpl.h"


#endif //__AVL_BINARY_SEARCH_TREE__H_


