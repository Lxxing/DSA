#ifndef _X_LISTIMPLEMENTION__H_
#define _X_LISTIMPLEMENTION__H_

template <typename T>
List<T>::List()
{
	_header = new ListNode<T>();
	_tailer = new ListNode<T>();
	_header->succ = _tailer;
	_header->pred = NULL;
	_tailer->pred = _header;
	_tailer->succ = NULL;
	_size = 0;
}

template <typename T>
List<T>::~List()
{
	delete _header;
	delete _tailer;
}


template <typename T>
Rank List<T>::size() const
{
	return _size;
}


template <typename T>
bool List<T>::empty() const
{
	return _size < 1;
}

template <typename T>
T& List<T>::operator [] (Rank r) const	//0 <= r < _size
{
	ListNodePtr pCur = first();//小标�?开始，对应的实际数据应该从第一个节点开�?
	while (r--)//r�?，返回首节点，r>0时，循环r次，指向第r个数�?
	{
		pCur = pCur->succ;
	}
	return pCur->data;
}


template <typename T>
ListNodePtr List<T>::first () const
{
	return _header->succ;
}

template <typename T>
ListNodePtr List<T>::last () const
{
	return _tailer->pred;
}

template <typename T>
bool List<T>::valid(ListNodePtr p) const
{
	return p == NULL ? true : false;
}

template <typename T>
int List<T>::disordered() const
{
	int ret = 0;
	ListNodePtr pCur = this->_header;
	for (int i = 0; i < _size; i++)
	{
		if (pCur->data > pCur->succ->data)
		{
			ret++;
		}
		
		pCur = pCur->succ;
	}

	return ret;
}

template <typename T>
ListNodePtr List<T>::find(T const & e) const
{
	return find(e,_size,_header);
}

template <typename T>
ListNodePtr List<T>::find(T const &e, int n, ListNodePtr p) const
{
	ListNodePtr pCur = p;
	while (n--)
	{
		if (e == pCur->data)
		{
			return pCur;
		}
		pCur = pCur->succ;
	}
	return NULL;
}

template <typename T>
ListNodePtr List<T>::search(T const & e) const
{
	search(e, _size, _header);
}

template <typename T>
ListNodePtr List<T>::search(T const &e,int n,ListNodePtr p) const
{
	ListNodePtr pCur = p;
	while (n--)
	{
		if (e <= pCur->data)
		{
			return pCur;
		}
		pCur = pCur->succ;
	}
	return NULL;
}

template <typename T>
ListNodePtr List<T>::selectMax() const
{
	return selectMax(_header,_size);
}

template <typename T>
ListNodePtr List<T>::selectMax(ListNodePtr p,int n) const
{
	ListNodePtr pCur = p;
	ListNodePtr pMax = p;
	while (n--)
	{
		if (pMax->data < pCur->data)
		{
			pMax = pCur;
		}
		pCur = pCur->succ;
	}
	return pMax;
}

template <typename T>
ListNodePtr List<T>::insertAsFirst(T const &e)
{
	ListNodePtr node = new ListNode<T>(e);
	node->succ = _header->succ;
	node->pred = _header;
	_header->succ->pred = node;
	_header->succ = node;
	_size++;
	return node;
}

template <typename T>
ListNodePtr List<T>::insertAsLast(T const &e)
{
	ListNodePtr node = new ListNode<T>(e);
	node->succ = _tailer;
	node->pred = _tailer->pred;
	_tailer->pred->succ = node;
	_tailer->pred = node;
	_size++;
	return node;
}

template <typename T>
ListNodePtr List<T>::insertBefore(ListNodePtr p,T const &e)
{
	ListNodePtr node = new ListNode<T>(e);
	node->succ = p;
	node->pred = p->pred;
	p->pred->succ = node;
	p->pred = node;
	_size++;
	return node;

}

template <typename T>
ListNodePtr List<T>::insertAfter(ListNodePtr p,T const &e)
{
	ListNodePtr node = new ListNode<T>(e);
	node->succ = p->succ;
	node->pred = p;
	p->succ->pred = node;
	p->succ = node;
	_size++;
	return node;
}

template <typename T>//ɾ���ڵ�p,���ؽڵ�����
T List<T>::remove(ListNodeTPtr(T) p)
{
	//����ϲ㶼��ֵ��Ч�Ľڵ㣬�˴�����Ҫ�ж�ͷβ�ڵ�
	if (p == _header || p == _tailer)
	{
		return -1;
	}
	T rnt = p->data;//����ɾ���ڵ���ֵ����T���ͱ�������=��������
	p->succ->pred = p->pred;
	p->pred->succ = p->succ;
	delete p;//�ͷ�
	_size--;//����
	
	return rnt;
}

template <typename T>
void List<T>::merge(ListNodePtr &self, int selfsize, List<T>&L, ListNodePtr q, int size)
{



}

template <typename T>
void List<T>::merge(List<T> &l)
{
	merge(_header, _size, l, l.first(), l.size());
}

template <typename T>
void List<T>::sort(ListNodePtr p,int n)
{
	selectionSort(p,n);
}

template <typename T>
void List<T>::sort()
{
	sort(first(),_size);
}

//�б��ѡ�������㷨����p��ʼ��n��Ԫ������
template <typename T>
void List<T>::selectionSort ( ListNodePtr p, int n )
{
	ListNodePtr pBar = p;
	for (int i = 0; i < n; ++i)
	{
		pBar = pBar->succ;
	}

	while (n)
	{
		ListNodePtr maxpnode = selectMax(p, n);
		T maxdata = remove(maxpnode);
		insertBefore(pBar,maxdata);
		pBar = pBar->pred;
		n--;
	}

}


#endif //_X_LISTIMPLEMENTION__H_
