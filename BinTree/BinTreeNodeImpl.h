#ifndef _BIN_TREE_NODE_IMPLEMENTATION__H_
#define _BIN_TREE_NODE_IMPLEMENTATION__H_

#include <queue>

#include "BinTreeNodeTravelImpl.h"

template <typename T>
BinTreeNode<T>::BinTreeNode()
	:parent(NULL),height(0),lChild(NULL),rChild(NULL)
{

}

template <typename T>//初始化高度为叶子节点
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

template <typename T>//元素类型
template <typename VST>//操作器
void BinTreeNode<T>::TravLevel ( VST& visit ) 
{ //二叉树层次遍历算法
	std::queue<BinTreeNodePtr > travQ; //辅助队列
	travQ.push(this); //根节点入队
    while ( !travQ.empty()) 
    {
       BinTreeNodePtr node = travQ.front();
	   travQ.pop();
       visit ( node->data ); //取出队首节点并访问
       if ( HasLChild ( *node ) ) 
       	travQ.push ( node->lChild ); //左孩子入队
       if ( HasRChild ( *node ) ) 
       	travQ.push ( node->rChild ); //右孩子入队
    }
}

template <typename T>//元素类型
template <typename VST>//操作器
void BinTreeNode<T>::TravPre ( VST& visit ) 
{ 
	int randIndex = rand() % 3;
	switch ( randIndex ) 
	{
	   case 1: TravPre1 ( this, visit ); break; //迭代版#1
	   case 2: TravPre2 ( this, visit ); break; //迭代版#2
	   default: TravPreR ( this, visit ); break; //递归版
	}
}
template <typename T>//元素类型
template <typename VST>//操作器
void BinTreeNode<T>::TravIn ( VST& visit ) 
{ 
	int randIndex = rand() % 5;
	switch ( randIndex ) 
	{
	   case 1: TravIn1 ( this, visit ); break; //迭代版#1
	   case 2: TravIn2 ( this, visit ); break; //迭代版#2
	   case 3: TravIn3 ( this, visit ); break; //迭代版#3
	   case 4: TravIn4 ( this, visit ); break; //迭代版#4
	   default: TravInR ( this, visit ); break; //递归版
	}

}
template <typename T>//元素类型
template <typename VST>//操作器
void BinTreeNode<T>::TravPost ( VST& visit ) 
{ 
	int randIndex = rand() % 2;
	switch ( randIndex ) 
	{
	   case 1: TravPost1 ( this, visit ); break; //迭代版#1
	   default: TravPostR ( this, visit ); break; //递归版
	}

}



#endif //_BIN_TREE_NODE_IMPLEMENTATION__H_

