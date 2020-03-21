/******************************************************************************************
* Binary Search Tree 
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正 xiaoxiaomiantianwo@163.com
******************************************************************************************/
#ifndef __AVL_BINARY_SEARCH_TREEIMPL__H_
#define __AVL_BINARY_SEARCH_TREEIMPL__H_


template <typename T>
BinTreeNodePtr AVL<T>::Insert(const T &e)
{
	BinTreeNodePtr &node = this->Search(e);
	if (node)
	{
		return node;//节点存在
	}

	node = new BinTreeNode<T>(e,hot);
	BinTreeNodePtr result = node;//保存返回结果
	size++;

	// 此时，node的父亲hot若增高，则其祖父有可能失衡
    for (BinTreeNodePtr g = hot; g; g = g->parent )
    { //从node之父出发向上，逐层检查各代祖先g
      if ( !AVLBalance( *g ) )
      { //一旦发现g失衡，则（采用“3 + 4”算法）使之复衡
		  ///FromParentTo(*g) = RotateAt(GetChild(GetChild(g)));只用一句话，宏定义会先展开计算
      	 BinTreeNodePtr tallerNode = GetChild (GetChild(g));//获取高子树
      	 BinTreeNodePtr rotateNode = RotateAt( tallerNode );
         rotateNode->parent->lChild = rotateNode;//完成父亲指向子树，将子树重新接入原树。此处不能用宏定义，不是完整的结构
		 	 
         break; //g复衡后，局部子树高度必然复原；其祖先亦必如此，故调整随即结束
      } 
      else //否则（g依然平衡）
      {
         UpdateHeight(g); //更新其高度（即便g未失衡，高度亦可能增加）
      }
    } //至多只需一次调整；若果真做过调整，则全树高度必然复原
	
	return result;//result->data == e
}


template <typename T>
bool AVL<T>::Remove(const T &e)
{
	BinTreeNodePtr &node = this->Search(e);
	if (NULL == node)
	{
		return false;//节点不存在
	}

	removeAt(node,hot);
	size--;

	//原节点之父hot及其祖先均可能失衡
    for (BinTreeNodePtr g = hot; g; g = g->parent )
    { //从_hot出发向上，逐层检查各代祖先g
      if ( !AVLBalance( *g ) ) //一旦发现g失衡，则（采用“3 + 4”算法）使之复衡
      {
         //并将该子树联至原父亲
         BinTreeNodePtr tallerNode = GetChild (GetChild(g));//获取高子树
      	 BinTreeNodePtr rotateNode = RotateAt( tallerNode );
         g = rotateNode->parent->lChild = rotateNode;
      }
      UpdateHeight( g ); 
     } //可能需做O(logn)次调整——无论是否做过调整，全树高度均可能降低

	return true;
}


#endif //__AVL_BINARY_SEARCH_TREEIMPL__H_


