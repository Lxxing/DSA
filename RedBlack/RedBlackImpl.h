/******************************************************************************************
* Binary Search Tree 
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* ��ӭ����ָ�� xiaoxiaomiantianwo@163.com
******************************************************************************************/
#ifndef __RedBlack_BINARY_SEARCH_TREEIMPL__H_
#define __RedBlack_BINARY_SEARCH_TREEIMPL__H_


template <typename T>
BinTreeNodePtr RedBlack<T>::Insert(const T &e)
{
	BinTreeNodePtr &node = this->Search(e);
	if (node)
	{
		return node;//�ڵ����
	}

	node = new BinTreeNode<T>(e,hot);
	BinTreeNodePtr result = node;//���淵�ؽ��
	size++;

	SolveDoubleRed(node);
	
	return node ? node : hot->parent;
}


template <typename T>
bool RedBlack<T>::Remove(const T &e)
{
	BinTreeNodePtr &node = this->Search(e);
	if (NULL == node)
	{
		return false;//�ڵ㲻����
	}

	removeAt(node,hot);
	size--;
	if (!size)
	{
		return true;//����
	}
	if (!hot)
	{
		root->color = RB_BLACK;
		UpdateHeight(root);
		return true;
	}

	if (BlackHeightUpdated(*hot))
	{
		return true;
	}

	if (IsRed(node))
	{
		node->color = RB_BLACK;
		node->height++;
		return true;
	}
	SolveDoubleBlack(node);
	return true;
}

template <typename T>
int RedBlack<T>::UpdateHeight(BinTreeNodePtr node)
{
	node->height = max ( HEIGHT(node->lChild), HEIGHT(node->rChild) ); 
    return IsBlack (node) ? node->height++ : node->height; //����ǰ�ڵ�Ϊ�ڣ����������
}

template <typename T>
void RedBlack<T>::SolveDoubleRed(BinTreeNodePtr node)
{
   if ( IsRoot ( *node ) ) //�ݹ�������������ת�ڣ������ڸ߶�Ҳ��֮����
   {  
   		root->color = RB_BLACK; 
   		root->height++;
   		return;  
   } 
   //����p�ش���
   BinTreeNodePtr p = node->parent; 
   if ( IsBlack (p) ) return; //��pΪ�ڣ���ֹ����

   BinTreeNodePtr g = p->parent; //��ȻpΪ�죬�游�ش��ڣ��ұ�Ϊ��ɫ
   BinTreeNodePtr u = Uncle(node); 
   //�常u����ɫ�ֱ���
   if (IsRed(node))
   {
      p->color = RB_BLACK; p->height++; 
      u->color = RB_BLACK; u->height++;
      if ( !IsRoot (*g) ) 
      {
		  g->color = RB_RED;
      }
      SolveDoubleRed( g );
   }
   else
   {
	   if ( IsLChild ( *node ) == IsLChild ( *p ) ) //��x��pͬ�ࣨ��zIg-zIg��zAg-zAg������
	   {
		   p->color = RB_BLACK;
	   }
	   else //��x��p��ࣨ��zIg-zAg��zAg-zIg
	   {
		   node->color = RB_BLACK; 
	   }

	   g->color = RB_RED;

	   BinTreeNodePtr gg = g->parent; //���游��great-grand parent��
	   BinTreeNodePtr r = FromParentTo (*g) = RotateAt(node); //��������������ڵ�
	   r->parent = gg; //��ԭ���游����
   }

}

template <typename T>
void RedBlack<T>:: SolveDoubleBlack(BinTreeNodePtr r)
{
   BinTreeNodePtr p = r ? r->parent : hot;  //r�ĸ���
   if ( !p )
   {
	   return;
   }
   BinTreeNodePtr s = ( r == p->lChild ) ? p->rChild : p->lChild; //r���ֵ�
   if ( IsBlack ( s ) ) { //�ֵ�sΪ��
      BinTreeNodePtr t = NULL; //s�ĺ캢�ӣ������Һ��ӽԺ죬�������ȣ��Ժ�ʱΪNULL��
      if ( IsRed ( s->rChild ) ) t = s->rChild; //����
      if ( IsRed ( s->lChild ) ) t = s->lChild; //����
      if ( t )
      { //��s�к캢�ӣ�BB-1
         RBColor oldColor = p->color; //����ԭ�������ڵ�p��ɫ������t���丸�ס��游
         //ͨ����ת��ƽ�⣬���������������Һ���Ⱦ��
         BinTreeNodePtr b = FromParentTo ( *p ) = RotateAt (t);
         if ( HasLChild ( *b ) ) //����
         { 
         	b->lChild->color = RB_BLACK;
         	UpdateHeight(b->lChild ); 
         }
         if ( HasRChild ( *b ) )//����
         { 
         	b->rChild->color = RB_BLACK;
         	UpdateHeight(b->rChild); 
         } 
         b->color = oldColor; 
         UpdateHeight(b); //���������ڵ�̳�ԭ���ڵ����ɫ
      } 
      else 
      { //��s�޺캢��
         s->color = RB_RED;
         s->height--; //sת��
         if ( IsRed ( p ) ) 
         { //BB-2R
            p->color = RB_BLACK; //pת�ڣ����ڸ߶Ȳ���
         } 
         else
         { //BB-2B
           p->height--; //p���ֺڣ����ڸ߶��½�
           SolveDoubleBlack(p); //�ݹ�����
         }
      }
   } 
   else 
   { //�ֵ�sΪ�죺BB-3
      s->color = RB_BLACK;
      p->color = RB_RED; //sת�ڣ�pת��
      BinTreeNodePtr t = IsLChild ( *s ) ? s->lChild : s->rChild; //ȡt���丸sͬ��
      hot = p; 
      FromParentTo(*p) = RotateAt(t); //��t���丸�ס��游��ƽ�����
      SolveDoubleBlack(r); //��������r��˫�ڡ�����ʱ��p��ת�죬�ʺ���ֻ����BB-1��BB-2R
   }


}

#endif //__RedBlack_BINARY_SEARCH_TREEIMPL__H_



