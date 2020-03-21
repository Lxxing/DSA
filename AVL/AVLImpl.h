/******************************************************************************************
* Binary Search Tree 
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* ��ӭ����ָ�� xiaoxiaomiantianwo@163.com
******************************************************************************************/
#ifndef __AVL_BINARY_SEARCH_TREEIMPL__H_
#define __AVL_BINARY_SEARCH_TREEIMPL__H_


template <typename T>
BinTreeNodePtr AVL<T>::Insert(const T &e)
{
	BinTreeNodePtr &node = this->Search(e);
	if (node)
	{
		return node;//�ڵ����
	}

	node = new BinTreeNode<T>(e,hot);
	BinTreeNodePtr result = node;//���淵�ؽ��
	size++;

	// ��ʱ��node�ĸ���hot�����ߣ������游�п���ʧ��
    for (BinTreeNodePtr g = hot; g; g = g->parent )
    { //��node֮���������ϣ�������������g
      if ( !AVLBalance( *g ) )
      { //һ������gʧ�⣬�򣨲��á�3 + 4���㷨��ʹ֮����
		  ///FromParentTo(*g) = RotateAt(GetChild(GetChild(g)));ֻ��һ�仰���궨�����չ������
      	 BinTreeNodePtr tallerNode = GetChild (GetChild(g));//��ȡ������
      	 BinTreeNodePtr rotateNode = RotateAt( tallerNode );
         rotateNode->parent->lChild = rotateNode;//��ɸ���ָ�����������������½���ԭ�����˴������ú궨�壬���������Ľṹ
		 	 
         break; //g����󣬾ֲ������߶ȱ�Ȼ��ԭ�������������ˣ��ʵ����漴����
      } 
      else //����g��Ȼƽ�⣩
      {
         UpdateHeight(g); //������߶ȣ�����gδʧ�⣬�߶���������ӣ�
      }
    } //����ֻ��һ�ε�����������������������ȫ���߶ȱ�Ȼ��ԭ
	
	return result;//result->data == e
}


template <typename T>
bool AVL<T>::Remove(const T &e)
{
	BinTreeNodePtr &node = this->Search(e);
	if (NULL == node)
	{
		return false;//�ڵ㲻����
	}

	removeAt(node,hot);
	size--;

	//ԭ�ڵ�֮��hot�������Ⱦ�����ʧ��
    for (BinTreeNodePtr g = hot; g; g = g->parent )
    { //��_hot�������ϣ�������������g
      if ( !AVLBalance( *g ) ) //һ������gʧ�⣬�򣨲��á�3 + 4���㷨��ʹ֮����
      {
         //��������������ԭ����
         BinTreeNodePtr tallerNode = GetChild (GetChild(g));//��ȡ������
      	 BinTreeNodePtr rotateNode = RotateAt( tallerNode );
         g = rotateNode->parent->lChild = rotateNode;
      }
      UpdateHeight( g ); 
     } //��������O(logn)�ε������������Ƿ�����������ȫ���߶Ⱦ����ܽ���

	return true;
}


#endif //__AVL_BINARY_SEARCH_TREEIMPL__H_


