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
	~BinTree();	

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
	BinTree<T> * Secede(BinTreeNodePtr node);//��������

	template <typename VST> void TravLevel( VST& visit );//��α��� 
    template <typename VST> void TravPre( VST& visit );//�������
    template <typename VST> void TravIn( VST& visit );//�������
    template <typename VST> void TravPost( VST& visit );//�������
	//test
	// ������������߶�Ϊh�Ķ�����
	int RandomBinTree(BinTree<T> & bt, BinTreeNodePtr x, int h = 20);
protected:
	//���½ڵ�x�߶�
	int UpdateHeight(BinTreeNodePtr x);
	//��x������������������,���¸߶�
	void UpdateAncestor(BinTreeNodePtr x);
private:
	int RemoveRecursive(BinTreeNodePtr node);
protected:
	int size;
	BinTreeNodePtr root;
};

#include "BinTreeImpl.h"

#endif //_BIN_TREE__H_


