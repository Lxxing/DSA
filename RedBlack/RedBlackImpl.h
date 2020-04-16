/******************************************************************************************
* Binary Search Tree 
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正 xiaoxiaomiantianwo@163.com
******************************************************************************************/
#ifndef __RedBlack_BINARY_SEARCH_TREEIMPL__H_
#define __RedBlack_BINARY_SEARCH_TREEIMPL__H_


template <typename T>
BinTreeNodePtr RedBlack<T>::Insert(const T &e)
{
	BinTreeNodePtr &node = this->Search(e);
	if (node)
	{
		return node;//节点存在
	}

	node = new BinTreeNode<T>(e,hot);
	BinTreeNodePtr result = node;//保存返回结果
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
		return false;//节点不存在
	}

	removeAt(node,hot);
	size--;
	if (!size)
	{
		return true;//空树
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
    return IsBlack (node) ? node->height++ : node->height; //若当前节点为黑，则计入黑深度
}

template <typename T>
void RedBlack<T>::SolveDoubleRed(BinTreeNodePtr node)
{
   if ( IsRoot ( *node ) ) //递归至树根，则将其转黑，整树黑高度也随之递增
   {  
   		root->color = RB_BLACK; 
   		root->height++;
   		return;  
   } 
   //父亲p必存在
   BinTreeNodePtr p = node->parent; 
   if ( IsBlack (p) ) return; //若p为黑，终止调整

   BinTreeNodePtr g = p->parent; //既然p为红，祖父必存在，且必为黑色
   BinTreeNodePtr u = Uncle(node); 
   //叔父u的颜色分别处理
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
	   if ( IsLChild ( *node ) == IsLChild ( *p ) ) //若x与p同侧（即zIg-zIg或zAg-zAg），则
	   {
		   p->color = RB_BLACK;
	   }
	   else //若x与p异侧（即zIg-zAg或zAg-zIg
	   {
		   node->color = RB_BLACK; 
	   }

	   g->color = RB_RED;

	   BinTreeNodePtr gg = g->parent; //曾祖父（great-grand parent）
	   BinTreeNodePtr r = FromParentTo (*g) = RotateAt(node); //调整后的子树根节点
	   r->parent = gg; //与原曾祖父联接
   }

}

template <typename T>
void RedBlack<T>:: SolveDoubleBlack(BinTreeNodePtr r)
{
   BinTreeNodePtr p = r ? r->parent : hot;  //r的父亲
   if ( !p )
   {
	   return;
   }
   BinTreeNodePtr s = ( r == p->lChild ) ? p->rChild : p->lChild; //r的兄弟
   if ( IsBlack ( s ) ) { //兄弟s为黑
      BinTreeNodePtr t = NULL; //s的红孩子（若左、右孩子皆红，左者优先；皆黑时为NULL）
      if ( IsRed ( s->rChild ) ) t = s->rChild; //右子
      if ( IsRed ( s->lChild ) ) t = s->lChild; //左子
      if ( t )
      { //黑s有红孩子：BB-1
         RBColor oldColor = p->color; //备份原子树根节点p颜色，并对t及其父亲、祖父
         //通过旋转重平衡，并将新子树的左、右孩子染黑
         BinTreeNodePtr b = FromParentTo ( *p ) = RotateAt (t);
         if ( HasLChild ( *b ) ) //左子
         { 
         	b->lChild->color = RB_BLACK;
         	UpdateHeight(b->lChild ); 
         }
         if ( HasRChild ( *b ) )//右子
         { 
         	b->rChild->color = RB_BLACK;
         	UpdateHeight(b->rChild); 
         } 
         b->color = oldColor; 
         UpdateHeight(b); //新子树根节点继承原根节点的颜色
      } 
      else 
      { //黑s无红孩子
         s->color = RB_RED;
         s->height--; //s转红
         if ( IsRed ( p ) ) 
         { //BB-2R
            p->color = RB_BLACK; //p转黑，但黑高度不变
         } 
         else
         { //BB-2B
           p->height--; //p保持黑，但黑高度下降
           SolveDoubleBlack(p); //递归上溯
         }
      }
   } 
   else 
   { //兄弟s为红：BB-3
      s->color = RB_BLACK;
      p->color = RB_RED; //s转黑，p转红
      BinTreeNodePtr t = IsLChild ( *s ) ? s->lChild : s->rChild; //取t与其父s同侧
      hot = p; 
      FromParentTo(*p) = RotateAt(t); //对t及其父亲、祖父做平衡调整
      SolveDoubleBlack(r); //继续修正r处双黑——此时的p已转红，故后续只能是BB-1或BB-2R
   }


}

#endif //__RedBlack_BINARY_SEARCH_TREEIMPL__H_



