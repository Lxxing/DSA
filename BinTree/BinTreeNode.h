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

template <typename T>
struct BinTreeNode
{
	T data;	//数据
	BinTreeNodePtr parent;
	BinTreeNodePtr lChild;
	BinTreeNodePtr rChild;
	int height;//高度

	BinTreeNode();
	BinTreeNode(const T &e,BinTreeNodePtr pare);
	BinTreeNode();	

	//ADT
	int Size();//当前节点子树的规模，当前节点后代总数
	BinTreeNodePtr InsertRChild(T const &e);
	BinTreeNodePtr InsertLChild(T const &e);

};

#include "BinTreeNodeImpl.h"

#endif //_BIN_TREE_NODE_H_

