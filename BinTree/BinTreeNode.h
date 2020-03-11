/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* ��ӭ����ָ��
******************************************************************************************/
#ifndef _BIN_TREE_NODE_H_
#define _BIN_TREE_NODE_H_

/***************************************
��������һ�ڵ�ĸ߶ȶ������亢�ӽڵ�����߶ȼ�һ
ĳ�ڵ㺢�ӻ��ߺ���ڵ�仯����Ҫ�������ȵĸ߶�
***************************************************/
#define BinTreeNodePtr BinTreeNode<T>*   //ָ��,����д���޷�ֱ�Ӷ������
#define BinTreeNodeTPtr(T) BinTreeNode<T>* //��ֱ�Ӷ������

/******************************************************************************************
 * BinTreeNode״̬�����ʵ��ж�
 ******************************************************************************************/
#define HEIGHT(node) ((node) ? (node)->height : -1) //�ڵ�߶�

template <typename T>
struct BinTreeNode
{
	T data;	//����
	BinTreeNodePtr parent;
	BinTreeNodePtr lChild;
	BinTreeNodePtr rChild;
	int height;//�߶�

	BinTreeNode();
	BinTreeNode(const T &e,BinTreeNodePtr pare);
	BinTreeNode();	

	//ADT
	int Size();//��ǰ�ڵ������Ĺ�ģ����ǰ�ڵ�������
	BinTreeNodePtr InsertRChild(T const &e);
	BinTreeNodePtr InsertLChild(T const &e);

};

#include "BinTreeNodeImpl.h"

#endif //_BIN_TREE_NODE_H_

