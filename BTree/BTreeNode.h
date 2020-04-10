/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/
#ifndef _B_TREE_NODE_H_
#define _B_TREE_NODE_H_

#include <vector.h>
using namespace std;

#define BTreeNodePtr BTreeNode<T>*   
#define BTreeNodeTPtr(T) BTreeNode<T>* 

template <typename T>
struct BTreeNode
{
	BTreeNodePtr parent;
	vector<T> key;
	vector<BTreeNodePtr > child;

	BTreeNode()
	{
		parent = NULL;
		child.insert(child.begin(),NULL);
	}	

	BTreeNode(T e,BTreeNodePtr ,BTreeNodePtr,BTreeNodePtr);
	~BTreeNode();	

};

#include "BinTreeNodeImpl.h"


#endif //_B_TREE_NODE_H_


