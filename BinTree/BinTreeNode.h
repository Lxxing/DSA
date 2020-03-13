/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/
#ifndef _BIN_TREE_NODE_H_
#define _BIN_TREE_NODE_H_

/***************************************
二叉树任一节点的高度都等于其孩子节点的最大高度加一
某节点孩子或者后代节点变化，就要更新祖先的高度
***************************************************/
#define BinTreeNodePtr BinTreeNode<T>*   //指针,这种写法无法直接定义变量
#define BinTreeNodeTPtr(T) BinTreeNode<T>* //可直接定义变量


/******************************************************************************************
* BinTreeNode状态与性质的判断
******************************************************************************************/
#define HEIGHT(node) ((node) ? (node)->height : -1) //节点高度
#define IsRoot(node) (!((node).parent))//root为true，非root为false
#define HasParent(node) ((node).parent )
#define HasLChild(node) ( (node).lChild)
#define HasRChild(node) ( (node).rChild )
#define HasChild(node) ( HasLChild(node) || HasRChild(node) ) //至少拥有一个孩子
#define HasBothChild(node) ( HasLChild(node) && HasRChild(node) ) //同时拥有两个孩子
#define IsLeaf(node) ( !HasChild(node) )//没有孩子为叶节点


#define IsLChild(node) \
	(!IsRoot(node) && ( &(node) == (node).parent->lChild))
#define IsRChild(node) \
	(!IsRoot(node) && ( &(node) == (node).parent->rChild))

/*来自父亲的引用*/
#define FromParentTo(node) \
	(IsRoot(node) ? root : (IsLChild(node) ? (node).parent->lChild : (node).parent->rChild))

template <typename T>
struct BinTreeNode
{
	T data;	//数据
	BinTreeNodePtr parent;
	BinTreeNodePtr lChild;
	BinTreeNodePtr rChild;
	int height;//高度

	BinTreeNode();
	BinTreeNode(T e,BinTreeNodePtr pare = NULL);
	~BinTreeNode();	

	//ADT
	int Size();//当前节点子树的规模，当前节点后代总数
	BinTreeNodePtr InsertRChild(T const &e);
	BinTreeNodePtr InsertLChild(T const &e);

	BinTreeNodePtr Succ(); //取当前节点的直接后继
	template <typename VST> void TravLevel( VST& ); //子树层次遍历
	template <typename VST> void TravPre( VST& ); //子树先序遍历
	template <typename VST> void TravIn( VST& ); //子树中序遍历
	template <typename VST> void TravPost( VST& ); //子树后序遍历

};

#include "BinTreeNodeImpl.h"


#endif //_BIN_TREE_NODE_H_

