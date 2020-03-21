/******************************************************************************************
* Binary Search Tree 
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* ��ӭ����ָ�� xiaoxiaomiantianwo@163.com
******************************************************************************************/
#ifndef __AVL_BINARY_SEARCH_TREE__H_
#define __AVL_BINARY_SEARCH_TREE__H_

#include <BST/BST.h>

//ע�Ͳ���ж��\֮��
//ƽ������
#define BalanceFactor(node)\
	( HEIGHT( (node).lChild ) - HEIGHT( (node).rChild) )

//AVLƽ������
#define AVLBalance(node)\
	( ( -2 < BalanceFactor(node) ) && ( BalanceFactor(node) < 2 ) ) 

/******************************************************************************************
 * �����Һ�����ȡ������, ��AVLƽ�����ǰ�����ȷ���ع�����
 
 ******************************************************************************************/
#define GetChild(node) ( \
   HEIGHT((node)->lChild) > HEIGHT( (node)->rChild) ? (node)->lChild: ( 	/*���*/\
   HEIGHT((node)->lChild ) < HEIGHT( (node)->rChild) ? (node)->rChild : /*�Ҹ�*/\
   (IsLChild(*(node)) ? (node)->lChild : (node)->rChild) /*�ȸߣ��븸��xͬ���ߣ�zIg-zIg��zAg-zAg������*/\
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


