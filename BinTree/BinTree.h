/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* ��ӭ����ָ��
******************************************************************************************/
#ifndef _BIN_TREE__H_
#define _BIN_TREE__H_

#include "BinTreeNode.h"

template <typename T>
class BinTree
{
public:

	BinTree();
	BinTree();	

	//ADT
    int Size() const;//�����ģ
	bool Empty() const;//���ж�
	BinTreeNodePtr Root() const;
	BinTreeNodePtr InsertRoot(T const &e);//������ڵ�
	BinTreeNodePtr InsertRChild(BinTreeNodePtr node,T const &e);
	BinTreeNodePtr InsertLChild(BinTreeNodePtr node,T const &e);
	BinTreeNodePtr InsertRTree(BinTreeNodePtr node,BinTree<T> *&e);
	BinTreeNodePtr InsertLTree(BinTreeNodePtr node,BinTree<T> *&e);
	//ɾ����λ��node���ڵ�Ϊ�������������ظ�����ԭ�ȵĹ�ģ
	int Remove( BinTreeNodePtr node); 
	//test
	// ������������߶�Ϊh�Ķ�����
	int RandomBinTree(BinTree<T> & bt, BinTreeNodePtr x, int h = 20);
protected:
	//���½ڵ�x�߶�
	int BinTree<T>::UpdateHeight(BinTreeNodePtr x);
	//��x������������������,���¸߶�
	int BinTree<T>::UpdateAncestor(BinTreeNodePtr x);

protected:
	int size;
	BinTreeNodePtr
};

#include "BinTreeImpl.h"

#endif //_BIN_TREE__H_


