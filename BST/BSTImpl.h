/******************************************************************************************
* Binary Search Tree 
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正 xiaoxiaomiantianwo@163.com
******************************************************************************************/
#ifndef __BINARY_SEARCH_TREEIMPL__H_
#define __BINARY_SEARCH_TREEIMPL__H_

/************************全局静态模板函数***************************************/

template <typename T>
static BinTreeNodePtr& SearchRec(BinTreeNodePtr & v,const T &e,BinTreeNodePtr &hot)
{
	//递归基
	if (NULL == v || e == v->data)
	{
		return v;
	}
	hot = v;//记录返回前的节点引用
	return e < v->data ? SearchRec(v->lChild,e,hot) : SearchRec(v->rChild,e,hot);
}
/*
成功，返回删除节点的接替者
失败，不可能失败，remove函数已经过滤失败情况
hot指向实际删除节点的父亲
*/

template <typename T>//按照单向的
static BinTreeNodePtr removeAt(BinTreeNodePtr &node, BinTreeNodePtr & hot ) 
{
	BinTreeNodePtr backNode = node;//删除节点
	BinTreeNodePtr sucNode = NULL;//接替节点
	if (!HasLChild(*node))//左为空，替换右
	{
		node = node->rChild;//完全隔离backNode，
		sucNode = node;//错误示例sucNode = node->rChild;，上一步node->rChild已经改变
	}
	else if(!HasRChild(*node))//右为空，替换左
	{
		node = node->lChild;
		sucNode = node;
	}
	else
	{
		backNode = node->Succ();
		//交换元素值，此时后继节点backNode等效为待删除的目标节点
		swap(backNode->data,node->data);

		//隔离节点*backNode
		BinTreeNodePtr backParent = backNode->parent;
		sucNode = backNode->rChild;//一定没有左子树，不然后继就是左子树了。

		if (backParent == node)
		{
			backParent->rChild = sucNode;
		}
		else
		{
			backParent->lChild = sucNode;
		}
		
	}

	hot = backNode->parent;//删除节点的父亲
	if (sucNode)
	{
		sucNode->parent = hot;//替换节点与hot节点连接，恢复树
	}
	delete backNode;
	return sucNode;//返回接替者
}

/***************************************************************/
/*
成功，返回命中节点e
失败，返回NULL,
*/
template <typename T>
BinTreeNodePtr &BST<T>::Search(const T &e)
{
	return SearchRec(this->root,e,hot = NULL);
}

template <typename T>
BinTreeNodePtr BST<T>::Insert(const T &e)
{
	BinTreeNodePtr &node = this->Search(e);//返回的是引用类型，不然赋值不能将节点加入树中
	if (node)
	{
		return node;//节点存在
	}

	node = new BinTreeNode<T>(e,hot);//引用节点指向hot子节点，即插入的左(右)节点
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
		return false;//节点不存在
	}

	removeAt(node,hot);
	size--;
	UpdateHeight(hot);
	return true;
}
/**********************protected****************************/
/******************************************************************************************
 * BST节点旋转变换统一算法（3节点 + 4子树），返回调整之后局部子树根节点的位置
 * 注意：尽管子树根会正确指向上层节点（如果存在），但反向的联接须由上层函数完成
 ******************************************************************************************/
template <typename T>
BinTreeNodePtr BST<T>::RotateAt(BinTreeNodePtr node)
{
	if ( !node ) { printf ( "\a\nFail to rotate a null node\n" ); exit ( -1 ); }
    BinTreeNodePtr p = node->parent; 
    BinTreeNodePtr g = p->parent; 
    //视node、p和g相对位置分四种情况
    if ( IsLChild ( *p ) ) /* zig */
    {
      if ( IsLChild ( *node ) ) 
      { /* zIg-ziIg */ 
      	 printf("\tzig-zig: ");
         p->parent = g->parent; //向上联接
         return Connect34( node, p, g, node->lChild, node->rChild, p->rChild, g->rChild );
      } 
      else 
      { /* zig-zag */  
      	 printf("\tzIg-zAg: ");
         node->parent = g->parent; //向上联接
         return Connect34( p, node, g, p->lChild, node->lChild, node->rChild, g->rChild );
      }
     }
     else  /* zag */
     {
      	if ( IsRChild ( *node ) ) 
      	{ /* zag-zag */ 
      		printf("\tzAg-zAg: ");
         	p->parent = g->parent; //向上联接
         	return Connect34( g, p, node, g->lChild, p->lChild, node->lChild, node->rChild );
      	} 
      	else
      	{ /* zag-zig */  
      		printf("\tzAg-zIg: ");
         	node->parent = g->parent; //向上联接
         	return Connect34( g, node, p, g->lChild, node->lChild, node->rChild, p->rChild );
        }
     }
}


/******************************************************************************************
 * 按照“3 + 4”结构联接3个节点及其四棵子树，返回重组之后的局部子树根节点位置（即b）
 * 子树根节点与上层节点之间的双向联接，均须由上层调用者完成
 * 可用于AVL和RedBlack的局部平衡调整
 * 按照中序顺序来理解
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

