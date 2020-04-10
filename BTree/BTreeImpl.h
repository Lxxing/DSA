/******************************************************************************************
** RMQ4CPP
** Auther : luxiang
** github:https://github.com/Lxxing?tab=repositories
** ��ӭ����ָ�� xiaoxiaomiantianwo@163.com
******************************************************************************************/
#ifndef _B_TREE_IMPLEMENTATION__H_
#define _B_TREE_IMPLEMENTATION__H_
	
	
template <typename T>
BTree<T>::BTree(int orderNumber)
	:order(orderNumber),size(0)
{}

template <typename T>
BTree<T>::~BTree()
{
	if (NULL != root)
	{
		delete root;
	}
}

template <typename T>
int BTree<T>::Size() const
{
	return size;
}


template <typename T>
bool BTree<T>::Empty() const
{
	return root == NULL ? true : false;
}

template <typename T>
BTreeNodePtr BTree<T>::Root() const
{
	return root;
}

template <typename T>
BTreeNodePtr BTree<T>::InsertRoot(T const &e)
{
	size++;
	root = new BTreeNode<T>(e);
	return root;
}

template <typename T>
BTreeNodePtr BTree<T>::InsertLChild(BTreeNodePtr node,T const &e)
{
	size++;
	node->InsertLChild(e);
	UpdateAncestor(node);
	return node->lChild;
}

template <typename T>
BTreeNodePtr BTree<T>::InsertRChild(BTreeNodePtr node,T const &e)
{
	size++;
	node->InsertRChild(e);
	UpdateAncestor(node);
	return node->rChild;
}

template <typename T>//assert(node->rChild == NULL)
BTreeNodePtr BTree<T>::InsertRTree(BTreeNodePtr node,BTree<T> *&e)
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
BTreeNodePtr BTree<T>::InsertLTree(BTreeNodePtr node,BTree<T> *&e)
{
	size += e->Size();
	//����
	node->lChild = e->Root();
	node->lChild->parent = node;
	UpdateAncestor(node);
	//�������Ԫ��e
	e->root = NULL;
	e->size = 0;
	//delete e;//���������ڵ���Ϣ������������
	e = NULL;

	return node;
}

template <typename T>//ȥ�������Ľڵ㣬�ݹ��ͷ�
int BTree<T>::Remove( BTreeNodePtr node)
{
	FromParentTo(node) = NULL;//���ڵ������ÿգ��г��Լ�
	UpdateAncestor(node->parent);
	int n = RemoveRecursive(node);
	size -= n;
	delete node;
	return n;
}
template <typename T>//ȥ�������Ľڵ㣬�ݹ��ͷ�
int BTree<T>::RemoveRecursive( BTreeNodePtr node)
{
	//�ݹ��,����
	if (NULL == node)
	{
		return 0;
	}
	int rnt = 1 + RemoveRecursive(node->lChild) + RemoveRecursive(node->rChild);
	delete node;
	return rnt;
}
template <typename T>
BTree<T> * BTree<T>::Secede(BTreeNodePtr node)
{
	FromParentTo(*node) = NULL;//���ڵ������ÿգ��г��Լ�
	UpdateAncestor(node->parent);
	BTree<T> * rnt = new BTree<T>();
	rnt->root = node;
	rnt->size = node->Size();
	node->parent = NULL;//�ж��Լ�

	this->size -= rnt->Size();
	return rnt;
}

template <typename T>
int BTree<T>::RandomBTree(BTree<T> & bt, BTreeNodePtr x, int h)
{
	int num = rand() % h;
	if ( 0 < num ) 
	   RandomBTree ( bt, bt.InsertRChild(x, h), h - 1 );
	if ( 0 < num )
	   RandomBTree ( bt, bt.InsertLChild(x, h), h - 1 );

	return true;
}

template <typename T> 
int BTree<T>::UpdateHeight (BTreeNodePtr node )
{ 
	return node->height = 1 + max(HEIGHT(node->lChild), HEIGHT(node->rChild));
}

template <typename T> 
void BTree<T>::UpdateAncestor (BTreeNodePtr node )
{ 
	while (node) 
	{ 
		UpdateHeight(node); 
		node = node->parent; 
	}
} 

template <typename T>
template <typename VST>
void BTree<T>::TravLevel ( VST& visit ) 
{ 
	if (root) 
		root->TravLevel ( visit );
} 

template <typename T>
template <typename VST>
void BTree<T>::TravPre( VST& visit ) 
{ 
	if (root) 
		root->TravPre( visit );
} 

template <typename T>
template <typename VST>
void BTree<T>::TravIn ( VST& visit ) 
{ 
	if (root) 
		root->TravIn( visit );
} 

template <typename T>
template <typename VST>
void BTree<T>::TravPost ( VST& visit ) 
{ 
	if (root) 
		root->TravPost( visit );
} 
	
#endif //_B_TREE_IMPLEMENTATION__H_
	
	

