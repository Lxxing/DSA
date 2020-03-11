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
	if (NULL == root)
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
	return node->lChild;
}

template <typename T>//assert(node->rChild == NULL)
BinTreeNodePtr BinTree<T>::InsertRTree(BinTreeNodePtr node,BinTree<T> *&e)
{
	node->rChild = e->Root();
	e->parent = node;
	UpdateAncestor(node);
	e->root = NULL;
	e->size = 0;
	delete e;
	e = NULL;

	return node;
}

template <typename T>
BinTreeNodePtr BinTree<T>::InsertLTree(BinTreeNodePtr node,BinTree<T> *&e)
{
	size += e->Size();
	//接入
	node->lChild = e->Root();
	e->parent = node;
	UpdateAncestor(node);
	//清空子树元素e
	e->root = NULL;
	e->size = 0;
	delete e;//保留子树节点信息，子树类清理
	e = NULL;

	return node;
}

template <typename T>//去掉子树的节点，递归释放
int BinTree<T>::Remove( BinTreeNodePtr node)
{
	
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

#endif //_BIN_TREE_IMPLEMENTATION__H_


