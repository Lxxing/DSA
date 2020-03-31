/******************************************************************************************
* Binary Search Tree 
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* ��ӭ����ָ�� xiaoxiaomiantianwo@163.com
******************************************************************************************/
#ifndef __SPLAY_BINARY_SEARCH_TREEIMPL__H_
#define __SPLAY_BINARY_SEARCH_TREEIMPL__H_


template <typename NodePosi> inline //�ڽڵ�*p��*lc������Ϊ�գ�֮�佨���������ӹ�ϵ
void attachAsLChild ( NodePosi p, NodePosi lc ) 
{ 
	p->lChild = lc;
	if ( lc ) lc->parent = p; 
}

template <typename NodePosi> inline //�ڽڵ�*p��*rc������Ϊ�գ�֮�佨�������ң��ӹ�ϵ
void attachAsRChild ( NodePosi p, NodePosi rc )
{ 
	p->rChild = rc; 
	if ( rc ) rc->parent = p; 
}

template <typename T>
BinTreeNodePtr Splay<T>::SplayTree(BinTreeNodePtr v)
{
	if ( !v ) return NULL; 
	BinTreeNodePtr p; //����
	BinTreeNodePtr g; //�游
	//���¶��ϣ�������*v��˫����չ
	while ( ( p = v->parent ) && ( g = p->parent ) ) 
	{ 
	  //ÿ��֮��*v����ԭ���游��great-grand parent��Ϊ��
      BinTreeNodePtr gg = g->parent; 
      if ( IsLChild ( *v ) )
         if ( IsLChild ( *p ) ) 
         { //zig-zig
            printf ( "\tzIg-zIg :\n" ); 
            attachAsLChild( g, p->rChild); 
            attachAsLChild( p, v->rChild);attachAsRChild( p, g);attachAsRChild(v, p);
         } 
         else
         { //zig-zag
            printf ( "\tzIg-zAg :\n" ); 
            attachAsLChild ( p, v->rChild); 
            attachAsRChild ( g, v->lChild);attachAsLChild( v, g); attachAsRChild(v,p);
         }
      else if ( IsRChild ( *p ) ) 
      { //zag-zag
        printf ( "\tzAg-zAg :\n" );
         attachAsRChild ( g, p->lChild ); attachAsRChild ( p, v->lChild );
         attachAsLChild ( p, g ); attachAsLChild ( v, p );
      } 
      else 
      { //zag-zig
         printf ( "\tzAg-zIg :\n" );
         attachAsRChild ( p, v->lChild); attachAsLChild ( g, v->rChild );
         attachAsRChild ( v, g ); attachAsLChild ( v, p );
      }
      if ( !gg ) v->parent = NULL; //��*vԭ�ȵ����游*gg�����ڣ���*v����ӦΪ����
      else //����*gg�˺�Ӧ����*v��Ϊ����Һ���
         ( g == gg->lChild ) ? attachAsLChild ( gg, v ) : attachAsRChild ( gg, v );
   } //˫����չ����ʱ������g == NULL����p���ܷǿ�

   if ( p = v->parent ) { //��p����ǿգ����������һ�ε���
      if ( IsLChild ( *v ) ) 
      { 
          attachAsLChild ( p, v->rChild ); 
          attachAsRChild ( v, p ); 
      }
      else                   
      { 
          attachAsRChild ( p, v->lChild ); 
          attachAsLChild ( v, p );
      }
   }
   
   v->parent = NULL; 
   return v;
}

template <typename T>
BinTreeNodePtr& Splay<T>::Search(const T &e)
{
	BinTreeNodePtr &node = SearchRec(this->root,e,hot = NULL);

	root = SplayTree(node ? node : hot);//��������չ����
	return root;
}

template <typename T>
BinTreeNodePtr Splay<T>::Insert(const T &e)
{
	BinTreeNodePtr &node = this->Search(e);
	if ( e == Search (e)->data )
		return root; //Ŀ��ڵ����,ֱ�ӷ���
	//Ŀ��ڵ㲻����
   size++; 
   BinTreeNodePtr t = root; //�����½ڵ�
   if ( root->data < e ) 
   { //�����¸�����t��t->rChildΪ���Һ���
   	  root = new BinTreeNode<T> ( e, NULL, t, t->rChild ); //2 + 3��
      t->parent = root;
      if ( HasRChild ( *t ) ) //<= 2��
      { 
          t->rChild->parent = root;
          t->rChild = NULL; 
      } 
   } 
   else 
   { //�����¸�����t->lChild��tΪ���Һ���
      root = new BinTreeNode<T> ( e, NULL, t->lChild, t ); //2 + 3��
      t->parent = root;
      if ( HasLChild ( *t ) ) 
      {
      	t->lChild->parent = root; 
      	t->lChild = NULL; 
      } 
   }
   return root; //�½ڵ��Ȼ��������
} //����ʱ����root->data == e


template <typename T>
bool Splay<T>::Remove(const T &e)
{
	BinTreeNodePtr &node = this->Search(e);
	if ( !root || ( e != node->data ) ) 
		return false; //�����ջ�Ŀ�겻���ڣ����޷�ɾ��
    BinTreeNodePtr w = root;
    if ( !HasLChild ( *root ) ) 
    { //��������������ֱ��ɾ��
      root = root->rChild; 
      if ( root ) root->parent = NULL;
   } 
   else if ( !HasRChild ( *root ) ) 
   { //������������Ҳֱ��ɾ��
      root = root->lChild; 
      if ( root ) root->parent = NULL;
   } 
   else //����������ͬʱ����
   { 
      BinTreeNodePtr lTree = root->lChild;
      lTree->parent = NULL; 
      root->lChild = NULL; 
      root = root->rChild;
      root->parent = NULL; //����������
      Search(w->data); //��ԭ����ΪĿ�꣬��һ�Σ��ض�ʧ�ܵģ�����.����������С�ڵ����չ�������ң�������ͬ�ڵ㣩���������ؿ�
      root->lChild = lTree; 
      lTree->parent = root; //��ԭ�������ӻ�ԭλ
   }
   
   delete w; //�ͷŽڵ�
   size--; 

   return true; //���سɹ���־
} //��Ŀ��ڵ�����ұ�ɾ��������true�����򷵻�false


#endif //__SPLAY_BINARY_SEARCH_TREEIMPL__H_



