/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* ��ӭ����ָ��
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
	//�����½ڵ㣬�Ե�ǰ�ڵ�Ϊǰ�����Խڵ�bΪ����
	QuadListNodePtr InsertAsSuccAbove	   ( T const& e, QuadListNodePtr b = NULL );

};

#include "QuadListNodeImpl.h"


#endif //_QUAD_LIST_NODE_H_


