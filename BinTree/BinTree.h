/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
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
    int Size() const;//整体规模
	bool Empty() const;//空判断
	BinTreeNodePtr Root() const;
	BinTreeNodePtr InsertRoot(T const &e);//插入根节点
	BinTreeNodePtr InsertRChild(BinTreeNodePtr node,T const &e);
	BinTreeNodePtr InsertLChild(BinTreeNodePtr node,T const &e);
	BinTreeNodePtr InsertRTree(BinTreeNodePtr node,BinTree<T> *&e);
	BinTreeNodePtr InsertLTree(BinTreeNodePtr node,BinTree<T> *&e);
	//删除以位置node处节点为根的子树，返回该子树原先的规模
	int Remove( BinTreeNodePtr node); 
	//test
	// 随机生成期望高度为h的二叉树
	int RandomBinTree(BinTree<T> & bt, BinTreeNodePtr x, int h = 20);
protected:
	//更新节点x高度
	int BinTree<T>::UpdateHeight(BinTreeNodePtr x);
	//从x出发，覆盖历代祖先,更新高度
	int BinTree<T>::UpdateAncestor(BinTreeNodePtr x);

protected:
	int size;
	BinTreeNodePtr
};

#include "BinTreeImpl.h"

#endif //_BIN_TREE__H_


