/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/
#ifndef _B_TREE__H_
#define _B_TREE__H_

#include "BTreeNode.h"

template <typename T>
class BTree
{
public:

	BTree(int orderNumber = 3);
	~BTree();	

	//ADT
   int const Order();
   int const Size();
   BTreeNodePtr & Root();
   bool Empty() const;
   BTreeNodePtr Search(const T& e );
   bool Insert( const T& e );
   bool Remove( const T& e );
private:

protected:
	int size;
	int order;
	
	BTreeNodePtr root;
	BTreeNodePtr hot;
};

#include "BTreeImpl.h"

#endif //_B_TREE__H_



