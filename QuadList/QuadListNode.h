/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/
#ifndef _QUAD_LIST_NODE_H_
#define _QUAD_LIST_NODE_H_

#define QuadListNodePtr QuadListNode<T>*   
#define QuadListNodeTPtr(T) QuadListNode<T>* 

template <typename T>
struct QuadListNode
{
	T entry;
	QuadListNodePtr pred;
	QuadListNodePtr succ;
	QuadListNodePtr above;
	QuadListNodePtr below;

	QuadListNode(T e = T(),QuadListNodePtr p = NULL,QuadListNodePtr s = NULL,
			QuadListNodePtr a = NULL,QuadListNodePtr b = NULL)
			:entry(e),pred(p),succ(s),above(a),below(b)
			{}

	~QuadListNode(){}

	//ADT
	//插入新节点，以当前节点为前驱，以节点b为下邻
	QuadListNodePtr InsertAsSuccAbove	   ( T const& e, QuadListNodePtr b = NULL );

};

#include "QuadListNodeImpl.h"


#endif //_QUAD_LIST_NODE_H_


