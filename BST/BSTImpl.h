/******************************************************************************************
* Binary Search Tree 
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* ��ӭ����ָ�� xiaoxiaomiantianwo@163.com
******************************************************************************************/
#ifndef __BINARY_SEARCH_TREEIMPL__H_
#define __BINARY_SEARCH_TREEIMPL__H_

/************************ȫ�־�̬ģ�庯��***************************************/

template <typename T>
static BinTreeNodePtr& SearchRec(BinTreeNodePtr & v,const T &e,BinTreeNodePtr &hot)
{
	//�ݹ��
	if (NULL == v || e == v->data)
	{
		return v;
	}
	hot = v;//��¼����ǰ�Ľڵ�����
	return e < v->data ? SearchRec(v->lChild,e,hot) : SearchRec(v->rChild,e,hot);
}
/*
�ɹ�������ɾ���ڵ�Ľ�����
ʧ�ܣ�������ʧ�ܣ�remove�����Ѿ�����ʧ�����
hotָ��ʵ��ɾ���ڵ�ĸ���
*/

template <typename T>//���յ����
static BinTreeNodePtr removeAt(BinTreeNodePtr &node, BinTreeNodePtr & hot ) 
{
	BinTreeNodePtr backNode = node;//ɾ���ڵ�
	BinTreeNodePtr sucNode = NULL;//����ڵ�
	if (!HasLChild(*node))//��Ϊ�գ��滻��
	{
		node = node->rChild;//��ȫ����backNode��
		sucNode = node;//����ʾ��sucNode = node->rChild;����һ��node->rChild�Ѿ��ı�
	}
	else if(!HasRChild(*node))//��Ϊ�գ��滻��
	{
		node = node->lChild;
		sucNode = node;
	}
	else
	{
		backNode = node->Succ();
		//����Ԫ��ֵ����ʱ��̽ڵ�backNode��ЧΪ��ɾ����Ŀ��ڵ�
		swap(backNode->data,node->data);

		//����ڵ�*backNode
		BinTreeNodePtr backParent = backNode->parent;
		sucNode = backNode->rChild;//һ��û������������Ȼ��̾����������ˡ�

		if (backParent == node)
		{
			backParent->rChild = sucNode;
		}
		else
		{
			backParent->lChild = sucNode;
		}
		
	}

	hot = backNode->parent;//ɾ���ڵ�ĸ���
	if (sucNode)
	{
		sucNode->parent = hot;//�滻�ڵ���hot�ڵ����ӣ��ָ���
	}
	delete backNode;
	return sucNode;//���ؽ�����
}

/***************************************************************/
/*
�ɹ����������нڵ�e
ʧ�ܣ�����NULL,
*/
template <typename T>
BinTreeNodePtr &BST<T>::Search(const T &e)
{
	return SearchRec(this->root,e,hot = NULL);
}

template <typename T>
BinTreeNodePtr BST<T>::Insert(const T &e)
{
	BinTreeNodePtr &node = this->Search(e);//���ص����������ͣ���Ȼ��ֵ���ܽ��ڵ��������
	if (node)
	{
		return node;//�ڵ����
	}

	node = new BinTreeNode<T>(e,hot);//���ýڵ�ָ��hot�ӽڵ㣬���������(��)�ڵ�
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
		return false;//�ڵ㲻����
	}

	removeAt(node,hot);
	size--;
	UpdateHeight(hot);
	return true;
}


#endif //__BINARY_SEARCH_TREEIMPL__H_

