/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/
#ifndef _QUAD_LIST_NODE_IMPL_H_
#define _QUAD_LIST_NODE_IMPL_H_

template <typename T>
QuadListNodePtr QuadListNode::InsertAsSuccAbove	   ( T const& e, QuadListNodePtr b = NULL )
{

   QuadListNodePtr newNode = new QuadListNode<T>( e, this, succ, NULL, b ); //创建新节点
   succ->pred = newNode; succ = newNode; //设置水平逆向链接
   if ( b )
   {
	   b->above = newNode; //设置垂直逆向链接
   }
   return newNode; //返回新节点的位置
}


#endif //_QUAD_LIST_NODE_IMPL_H_



