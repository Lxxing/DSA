
/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/

#ifndef __LISTNODE__H_
#define __LISTNODE__H_


typedef int Rank;    //采用统一的rank表述
#define ListNodePtr ListNode<T>*   //指针,这种写法无法直接定义变量
#define ListNodeTPtr(T) ListNode<T>* //可直接定义变量

template <typename T>
struct ListNode
{
	T data;	//数据
	ListNodePtr pred;	//前驱prediction
	ListNodePtr succ;	//后继

	ListNode();
	ListNode(const T &e);
	~ListNode();

	
	

};

#include "ListNodeImplementation.h"

#endif //__LISTNODE__H_
