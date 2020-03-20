#ifndef _BIN_TREE_IMPLEMENTATION__H_
#define _BIN_TREE_IMPLEMENTATION__H_


template <typename T>
BinTree<T>::BinTree()
	:size(0),root(NULL)
{
}

template <typename T>
BinTree<T>::~BinTree()
{
	if (NULL != root)
	{
		delete root;
	}
}

template <typename T>
int BinTree<T>::Size() const
{
	return size;
}


template <typename T>
bool BinTree<T>::Empty() const
{
	return root == NULL ? true : false;
}

template <typename T>
BinTreeNodePtr BinTree<T>::Root() const
{
	return root;
}

template <typename T>
BinTreeNodePtr BinTree<T>::InsertRoot(T const &e)
{
	size++;
	root = new BinTreeNode<T>(e);
	return root;
}

template <typename T>
BinTreeNodePtr BinTree<T>::InsertLChild(BinTreeNodePtr node,T const &e)
{
	size++;
	node->InsertLChild(e);
	UpdateAncestor(node);
	return node->lChild;
}

template <typename T>
BinTreeNodePtr BinTree<T>::InsertRChild(BinTreeNodePtr node,T const &e)
{
	size++;
	node->InsertRChild(e);
	UpdateAncestor(node);
	return node->rChild;
}

template <typename T>//assert(node->rChild == NULL)
BinTreeNodePtr BinTree<T>::InsertRTree(BinTreeNodePtr node,BinTree<T> *&e)
{
	size += e->Size();
	node->rChild = e->Root();
	node->rChild->parent = node;
	UpdateAncestor(node);
	e->root = NULL;
	e->size = 0;
	//delete e;
	e = NULL;

	return node;
}

template <typename T>
BinTreeNodePtr BinTree<T>::InsertLTree(BinTreeNodePtr node,BinTree<T> *&e)
{
	size += e->Size();
	//接入
	node->lChild = e->Root();
	node->lChild->parent = node;
	UpdateAncestor(node);
	//清空子树元素e
	e->root = NULL;
	e->size = 0;
	//delete e;//保留子树节点信息，子树类清理
	e = NULL;

	return node;
}

template <typename T>//去掉子树的节点，递归释放
int BinTree<T>::Remove( BinTreeNodePtr node)
{
	FromParentTo(node) = NULL;//父节点引用置空，切除自己
	UpdateAncestor(node->parent);
	int n = RemoveRecursive(node);
	size -= n;
	delete node;
	return n;
}
template <typename T>//去掉子树的节点，递归释放
int BinTree<T>::RemoveRecursive( BinTreeNodePtr node)
{
	//递归基,空树
	if (NULL == node)
	{
		return 0;
	}
	int rnt = 1 + RemoveRecursive(node->lChild) + RemoveRecursive(node->rChild);
	delete node;
	return rnt;
}
template <typename T>
BinTree<T> * BinTree<T>::Secede(BinTreeNodePtr node)
{
	FromParentTo(*node) = NULL;//父节点引用置空，切除自己
	UpdateAncestor(node->parent);
	BinTree<T> * rnt = new BinTree<T>();
	rnt->root = node;
	rnt->size = node->Size();
	node->parent = NULL;//切断自己

	this->size -= rnt->Size();
	return rnt;
}

template <typename T>
int BinTree<T>::RandomBinTree(BinTree<T> & bt, BinTreeNodePtr x, int h)
{
	int num = rand() % h;
	if ( 0 < num ) 
	   RandomBinTree ( bt, bt.InsertRChild(x, h), h - 1 );
	if ( 0 < num )
	   RandomBinTree ( bt, bt.InsertLChild(x, h), h - 1 );

	return true;
}

template <typename T> 
int BinTree<T>::UpdateHeight (BinTreeNodePtr node )
{ 
	return node->height = 1 + max(HEIGHT(node->lChild), HEIGHT(node->rChild));
}

template <typename T> 
void BinTree<T>::UpdateAncestor (BinTreeNodePtr node )
{ 
	while (node) 
	{ 
		UpdateHeight(node); 
		node = node->parent; 
	}
} 

template <typename T>
template <typename VST>
void BinTree<T>::TravLevel ( VST& visit ) 
{ 
	if (root) 
		root->TravLevel ( visit );
} 

template <typename T>
template <typename VST>
void BinTree<T>::TravPre( VST& visit ) 
{ 
	if (root) 
		root->TravPre( visit );
} 

template <typename T>
template <typename VST>
void BinTree<T>::TravIn ( VST& visit ) 
{ 
	if (root) 
		root->TravIn( visit );
} 

template <typename T>
template <typename VST>
void BinTree<T>::TravPost ( VST& visit ) 
{ 
	if (root) 
		root->TravPost( visit );
} 

#endif //_BIN_TREE_IMPLEMENTATION__H_


