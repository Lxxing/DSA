/******************************************************************************************
* Binary Search Tree 
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* ��ӭ����ָ�� xiaoxiaomiantianwo@163.com
******************************************************************************************/
#ifndef __BINARY_SEARCH_TREEIMPL__H_
#define __BINARY_SEARCH_TREEIMPL__H_

/************************ȫ�־�̬ģ�庯��***************************************/

template <typename T>
static BinTreeNodePtr& SearchRec(BinTreeNodePtr & v,const T &e,BinTreeNodePtr &hot)
{
	//�ݹ��
	if (NULL == v || e == v->data)
	{
		return v;
	}
	hot = v;//��¼����ǰ�Ľڵ�����
	return e < v->data ? SearchRec(v->lChild,e,hot) : SearchRec(v->rChild,e,hot);
}
/*
�ɹ�������ɾ���ڵ�Ľ�����
ʧ�ܣ�������ʧ�ܣ�remove�����Ѿ�����ʧ�����
hotָ��ʵ��ɾ���ڵ�ĸ���
*/

template <typename T>//���յ����
static BinTreeNodePtr removeAt(BinTreeNodePtr &node, BinTreeNodePtr & hot ) 
{
	BinTreeNodePtr backNode = node;//ɾ���ڵ�
	BinTreeNodePtr sucNode = NULL;//����ڵ�
	if (!HasLChild(*node))//��Ϊ�գ��滻��
	{
		node = node->rChild;//��ȫ����backNode��
		sucNode = node;//����ʾ��sucNode = node->rChild;����һ��node->rChild�Ѿ��ı�
	}
	else if(!HasRChild(*node))//��Ϊ�գ��滻��
	{
		node = node->lChild;
		sucNode = node;
	}
	else
	{
		backNode = node->Succ();
		//����Ԫ��ֵ����ʱ��̽ڵ�backNode��ЧΪ��ɾ����Ŀ��ڵ�
		swap(backNode->data,node->data);

		//����ڵ�*backNode
		BinTreeNodePtr backParent = backNode->parent;
		sucNode = backNode->rChild;//һ��û������������Ȼ��̾����������ˡ�

		if (backParent == node)
		{
			backParent->rChild = sucNode;
		}
		else
		{
			backParent->lChild = sucNode;
		}
		
	}

	hot = backNode->parent;//ɾ���ڵ�ĸ���
	if (sucNode)
	{
		sucNode->parent = hot;//�滻�ڵ���hot�ڵ����ӣ��ָ���
	}
	delete backNode;
	return sucNode;//���ؽ�����
}

/***************************************************************/
/*
�ɹ����������нڵ�e
ʧ�ܣ�����NULL,
*/
template <typename T>
BinTreeNodePtr &BST<T>::Search(const T &e)
{
	return SearchRec(this->root,e,hot = NULL);
}

template <typename T>
BinTreeNodePtr BST<T>::Insert(const T &e)
{
	BinTreeNodePtr &node = this->Search(e);//���ص����������ͣ���Ȼ��ֵ���ܽ��ڵ��������
	if (node)
	{
		return node;//�ڵ����
	}

	node = new BinTreeNode<T>(e,hot);//���ýڵ�ָ��hot�ӽڵ㣬���������(��)�ڵ�
	size++;
	UpdateHeight(node);
	return node;//node->data == e
}


template <typename T>
bool BST<T>::Remove(const T &e)
{
	BinTreeNodePtr &node = this->Search(e);
	if (NULL == node)
	{
		return false;//�ڵ㲻����
	}

	removeAt(node,hot);
	size--;
	UpdateHeight(hot);
	return true;
}
/**********************protected****************************/
/******************************************************************************************
 * BST�ڵ���ת�任ͳһ�㷨��3�ڵ� + 4�����������ص���֮��ֲ��������ڵ��λ��
 * ע�⣺��������������ȷָ���ϲ�ڵ㣨������ڣ�������������������ϲ㺯�����
 ******************************************************************************************/
template <typename T>
BinTreeNodePtr BST<T>::RotateAt(BinTreeNodePtr node)
{
	if ( !node ) { printf ( "\a\nFail to rotate a null node\n" ); exit ( -1 ); }
    BinTreeNodePtr p = node->parent; 
    BinTreeNodePtr g = p->parent; 
    //��node��p��g���λ�÷��������
    if ( IsLChild ( *p ) ) /* zig */
    {
      if ( IsLChild ( *node ) ) 
      { /* zIg-ziIg */ 
      	 printf("\tzig-zig: ");
         p->parent = g->parent; //��������
         return Connect34( node, p, g, node->lChild, node->rChild, p->rChild, g->rChild );
      } 
      else 
      { /* zig-zag */  
      	 printf("\tzIg-zAg: ");
         node->parent = g->parent; //��������
         return Connect34( p, node, g, p->lChild, node->lChild, node->rChild, g->rChild );
      }
     }
     else  /* zag */
     {
      	if ( IsRChild ( *node ) ) 
      	{ /* zag-zag */ 
      		printf("\tzAg-zAg: ");
         	p->parent = g->parent; //��������
         	return Connect34( g, p, node, g->lChild, p->lChild, node->lChild, node->rChild );
      	} 
      	else
      	{ /* zag-zig */  
      		printf("\tzAg-zIg: ");
         	node->parent = g->parent; //��������
         	return Connect34( g, node, p, g->lChild, node->lChild, node->rChild, p->rChild );
        }
     }
}


/******************************************************************************************
 * ���ա�3 + 4���ṹ����3���ڵ㼰���Ŀ���������������֮��ľֲ��������ڵ�λ�ã���b��
 * �������ڵ����ϲ�ڵ�֮���˫�����ӣ��������ϲ���������
 * ������AVL��RedBlack�ľֲ�ƽ�����
 * ��������˳�������
 ******************************************************************************************/

template <typename T>
BinTreeNodePtr BST<T>::Connect34(BinTreeNodePtr a,BinTreeNodePtr b, BinTreeNodePtr c,
	BinTreeNodePtr T0, BinTreeNodePtr T1, BinTreeNodePtr T2, BinTreeNodePtr T3)
{
	a->lChild = T0;
	if (T0)
	{
		T0->parent = a;
	}
	a->rChild = T1;
	if (T1)
	{
		T1->parent = a;
	}
	UpdateHeight(a);

	c->lChild = T2;
	if (T2)
	{
		T2->parent = c;
	}
	c->rChild = T3;
	if (T3)
	{
		T3->parent = c;
	}
	UpdateHeight(c);

	b->lChild = a;
	a->parent = b;
	b->rChild = c;
	c->parent = b;
	UpdateHeight(b);

	return b;
}

#endif //__BINARY_SEARCH_TREEIMPL__H_

