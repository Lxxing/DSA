/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* ��ӭ����ָ��
******************************************************************************************/
#ifndef _QUAD_LIST_NODE_IMPL_H_
#define _QUAD_LIST_NODE_IMPL_H_

template <typename T>
QuadListNodePtr QuadListNode::InsertAsSuccAbove	   ( T const& e, QuadListNodePtr b = NULL )
{

   QuadListNodePtr newNode = new QuadListNode<T>( e, this, succ, NULL, b ); //�����½ڵ�
   succ->pred = newNode; succ = newNode; //����ˮƽ��������
   if ( b )
   {
	   b->above = newNode; //���ô�ֱ��������
   }
   return newNode; //�����½ڵ��λ��
}


#endif //_QUAD_LIST_NODE_IMPL_H_



