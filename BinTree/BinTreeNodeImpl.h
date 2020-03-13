#ifndef _BIN_TREE_NODE_IMPLEMENTATION__H_
#define _BIN_TREE_NODE_IMPLEMENTATION__H_

#include <queue>

#include "BinTreeNodeTravelImpl.h"

template <typename T>
BinTreeNode<T>::BinTreeNode()
	:parent(NULL),height(0),lChild(NULL),rChild(NULL)
{

}

template <typename T>//��ʼ���߶�ΪҶ�ӽڵ�
BinTreeNode<T>::BinTreeNode(T e,BinTreeNodePtr pare)
	:data(e),parent(pare),height(0),lChild(NULL),rChild(NULL)
{
}


template <typename T>
BinTreeNode<T>::~BinTreeNode()
{

}

template <typename T>
int BinTreeNode<T>::Size()
{
	int res = 1;
	if (this->lChild)
	{
		res += this->lChild->Size();
	}
	if (this->rChild)
	{
		res += this->rChild->Size();
	}
	return res;
}

template <typename T>
BinTreeNodePtr BinTreeNode<T>::InsertRChild(T const &e)
{
	this->rChild = new BinTreeNode(e,this);
	return this->rChild;
}

template <typename T>
BinTreeNodePtr BinTreeNode<T>::InsertLChild(T const &e)
{
	this->lChild = new BinTreeNode(e,this);
	return this->lChild;
}

template <typename T>//Ԫ������
template <typename VST>//������
void BinTreeNode<T>::TravLevel ( VST& visit ) 
{ //��������α����㷨
	std::queue<BinTreeNodePtr > travQ; //��������
	travQ.push(this); //���ڵ����
    while ( !travQ.empty()) 
    {
       BinTreeNodePtr node = travQ.front();
	   travQ.pop();
       visit ( node->data ); //ȡ�����׽ڵ㲢����
       if ( HasLChild ( *node ) ) 
       	travQ.push ( node->lChild ); //�������
       if ( HasRChild ( *node ) ) 
       	travQ.push ( node->rChild ); //�Һ������
    }
}

template <typename T>//Ԫ������
template <typename VST>//������
void BinTreeNode<T>::TravPre ( VST& visit ) 
{ 
	int randIndex = rand() % 3;
	switch ( randIndex ) 
	{
	   case 1: TravPre1 ( this, visit ); break; //������#1
	   case 2: TravPre2 ( this, visit ); break; //������#2
	   default: TravPreR ( this, visit ); break; //�ݹ��
	}
}
template <typename T>//Ԫ������
template <typename VST>//������
void BinTreeNode<T>::TravIn ( VST& visit ) 
{ 
	int randIndex = rand() % 5;
	switch ( randIndex ) 
	{
	   case 1: TravIn1 ( this, visit ); break; //������#1
	   case 2: TravIn2 ( this, visit ); break; //������#2
	   case 3: TravIn3 ( this, visit ); break; //������#3
	   case 4: TravIn4 ( this, visit ); break; //������#4
	   default: TravInR ( this, visit ); break; //�ݹ��
	}

}
template <typename T>//Ԫ������
template <typename VST>//������
void BinTreeNode<T>::TravPost ( VST& visit ) 
{ 
	int randIndex = rand() % 2;
	switch ( randIndex ) 
	{
	   case 1: TravPost1 ( this, visit ); break; //������#1
	   default: TravPostR ( this, visit ); break; //�ݹ��
	}

}



#endif //_BIN_TREE_NODE_IMPLEMENTATION__H_

