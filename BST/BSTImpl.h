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


#endif //__BINARY_SEARCH_TREEIMPL__H_

