#ifndef _X_LISTIMPLEMENTION__H_
#define _X_LISTIMPLEMENTION__H_


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
T& List<T>::operator [] (Rank r) const
{
	ListNodePtr header = _header;
	while (r--)
	{
		header = header->succ;
	}
	return *header;
}


template <typename T>
ListNodePtr List<T>::first () const
{
	return _header;
}

template <typename T>
ListNodePtr List<T>::last () const
{
	return _tailer;
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
	ListNodePtr *node = new ListNode(e);
	node->succ = _header->succ;
	_header->succ->pred = node;
	_header->succ = node;
	return node;
}

template <typename T>
ListNodePtr List<T>::insertAsLast(T const &e)
{
	ListNodePtr *node = new ListNode(e);
	node->succ = _tailer;
	_tailer->pred->succ = node;
	_tailer->pred = node;
	return node;
}

template <typename T>
ListNodePtr List<T>::insertBefore(ListNodePtr p,T const &e)
{
	ListNodePtr *node = new ListNode(e);
	node->succ = p;
	p->pred->succ = node;
	p->pred = node;
	return node;

}

template <typename T>
ListNodePtr List<T>::insertAfter(ListNodePtr p,T const &e)
{
	ListNodePtr *node = new ListNode(e);
	node->succ = p->succ;
	p->succ->pred = node;
	p->succ = node;
	
	return node;
}

template <typename T>
T List<T>::remove(ListNodePtr p)
{
	ListNodePtr rnt = p;
	p->succ->pred = p->pred;
	p->pred->succ = p->succ;
	
	return rnt->data;
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


#endif //_X_LISTIMPLEMENTION__H_
