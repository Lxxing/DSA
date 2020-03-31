/******************************************************************************************
* Binary Search Tree 
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正 xiaoxiaomiantianwo@163.com
******************************************************************************************/
#ifndef __SPLAY_BINARY_SEARCH_TREEIMPL__H_
#define __SPLAY_BINARY_SEARCH_TREEIMPL__H_


template <typename NodePosi> inline //在节点*p与*lc（可能为空）之间建立父（左）子关系
void attachAsLChild ( NodePosi p, NodePosi lc ) 
{ 
	p->lChild = lc;
	if ( lc ) lc->parent = p; 
}

template <typename NodePosi> inline //在节点*p与*rc（可能为空）之间建立父（右）子关系
void attachAsRChild ( NodePosi p, NodePosi rc )
{ 
	p->rChild = rc; 
	if ( rc ) rc->parent = p; 
}

template <typename T>
BinTreeNodePtr Splay<T>::SplayTree(BinTreeNodePtr v)
{
	if ( !v ) return NULL; 
	BinTreeNodePtr p; //父亲
	BinTreeNodePtr g; //祖父
	//自下而上，反复对*v做双层伸展
	while ( ( p = v->parent ) && ( g = p->parent ) ) 
	{ 
	  //每轮之后*v都以原曾祖父（great-grand parent）为父
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
      if ( !gg ) v->parent = NULL; //若*v原先的曾祖父*gg不存在，则*v现在应为树根
      else //否则，*gg此后应该以*v作为左或右孩子
         ( g == gg->lChild ) ? attachAsLChild ( gg, v ) : attachAsRChild ( gg, v );
   } //双层伸展结束时，必有g == NULL，但p可能非空

   if ( p = v->parent ) { //若p果真非空，则额外再做一次单旋
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

	root = SplayTree(node ? node : hot);//最后访问伸展到根
	return root;
}

template <typename T>
BinTreeNodePtr Splay<T>::Insert(const T &e)
{
	BinTreeNodePtr &node = this->Search(e);
	if ( e == Search (e)->data )
		return root; //目标节点存在,直接返回
	//目标节点不存在
   size++; 
   BinTreeNodePtr t = root; //创建新节点
   if ( root->data < e ) 
   { //插入新根，以t和t->rChild为左、右孩子
   	  root = new BinTreeNode<T> ( e, NULL, t, t->rChild ); //2 + 3个
      t->parent = root;
      if ( HasRChild ( *t ) ) //<= 2个
      { 
          t->rChild->parent = root;
          t->rChild = NULL; 
      } 
   } 
   else 
   { //插入新根，以t->lChild和t为左、右孩子
      root = new BinTreeNode<T> ( e, NULL, t->lChild, t ); //2 + 3个
      t->parent = root;
      if ( HasLChild ( *t ) ) 
      {
      	t->lChild->parent = root; 
      	t->lChild = NULL; 
      } 
   }
   return root; //新节点必然置于树根
} //返回时总有root->data == e


template <typename T>
bool Splay<T>::Remove(const T &e)
{
	BinTreeNodePtr &node = this->Search(e);
	if ( !root || ( e != node->data ) ) 
		return false; //若树空或目标不存在，则无法删除
    BinTreeNodePtr w = root;
    if ( !HasLChild ( *root ) ) 
    { //若无左子树，则直接删除
      root = root->rChild; 
      if ( root ) root->parent = NULL;
   } 
   else if ( !HasRChild ( *root ) ) 
   { //若无右子树，也直接删除
      root = root->lChild; 
      if ( root ) root->parent = NULL;
   } 
   else //若左右子树同时存在
   { 
      BinTreeNodePtr lTree = root->lChild;
      lTree->parent = NULL; 
      root->lChild = NULL; 
      root = root->rChild;
      root->parent = NULL; //保留右子树
      Search(w->data); //以原树根为目标，做一次（必定失败的）查找.右子树中最小节点必伸展至根，且（因无雷同节点）其左子树必空
      root->lChild = lTree; 
      lTree->parent = root; //将原左子树接回原位
   }
   
   delete w; //释放节点
   size--; 

   return true; //返回成功标志
} //若目标节点存在且被删除，返回true；否则返回false


#endif //__SPLAY_BINARY_SEARCH_TREEIMPL__H_



