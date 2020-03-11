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
#define IsRoot(node) (!((node).parent ))//rootΪtrue����rootΪfalse
#define HasParent(node) ((node).parent )
#define HasLChild(node) ( (node).lChild)
#define HasRChild(node) ( (node).rChild )
#define HasChild(node) ( HasLChild(node) || HasRChild(node) ) //����ӵ��һ������
#define HasBothChild(node) ( HasLChild(node) && HasRChild(node) ) //ͬʱӵ����������
#define IsLeaf(node) ( !HasChild(node) )//û�к���ΪҶ�ڵ�


#define IsLChild(node) \
	(!IsRoot(node) && ( &(node) == (node).parent->lChild))
#define IsRChild(node) \
	(!IsRoot(node) && ( &(node) == (node).parent->rChild))


/******************************************************************************************
 * ��BinNode�����ض���ϵ�Ľڵ㼰ָ��
 ******************************************************************************************/
#define FromParentTo(x) \/*���Ը��׵�����*/ 
   ( IsRoot(x) ? root : ( IsLChild(x) ? (x).parent->lc : (x).parent->rc ) )

template <typename T>
struct BinTreeNodes
{
	T data;	//����
	BinTreeNodePtr parent;
	BinTreeNodePtr lChild;
	BinTreeNodePtr rChild;
	int height;//�߶�

	BinTreeNode();
	BinTreeNode(T e,BinTreeNodePtr pare = NULL);
	~BinTreeNode();	

	//ADT
	int Size();//��ǰ�ڵ������Ĺ�ģ����ǰ�ڵ�������
	BinTreeNodePtr InsertRChild(T const &e);
	BinTreeNodePtr InsertLChild(T const &e);

};

#include "BinTreeNodeImpl.h"

#endif //_BIN_TREE_NODE_H_

