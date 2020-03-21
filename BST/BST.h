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
	 //��node���丸�ס��游��ͳһ��ת����,Ϊ�˸��������̳�
	BinTreeNodePtr RotateAt(BinTreeNodePtr node);
	//���ա�3 + 4���ṹ������3���ڵ㼰�Ŀ�����
	BinTreeNodePtr Connect34(BinTreeNodePtr,BinTreeNodePtr, BinTreeNodePtr,
		BinTreeNodePtr, BinTreeNodePtr, BinTreeNodePtr, BinTreeNodePtr );

public:

	virtual BinTreeNodePtr& Search(const T &);
	virtual BinTreeNodePtr Insert(const T &);
	virtual bool Remove(const T &);

};


#include "BSTImpl.h"


#endif //__BINARY_SEARCH_TREE__H_

