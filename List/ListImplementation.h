#ifndef _X_LISTIMPLEMENTION__H_
#define _X_LISTIMPLEMENTION__H_


template <typename T>
Rank List::size() const
{
	return _size;
}


template <typename T>
bool List::empty() const
{
	return _size < 1;
}

template <typename T>
T& List::operator [] (Rank r) const 
{
	ListNodePtr header = _header;
	while (r--)
	{
		header = header->succ;
	}
	return *header;
}


template <typename T>
ListNodePtr List::first () const 
{
	return _header;
}

template <typename T>
ListNodePtr List::last () const 
{
	return _tailer;
}

template <typename T>
bool valid(ListNodePtr p) const
{
	return p == NULL ? true : false;
}

template <typename T>
int disordered() const
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
ListNodePtr find(T const & e) const
{
	return find(e,_size,_header);
}

template <typename T>
ListNodePtr find(T const &e, int n, ListNodePtr p) const
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
ListNodePtr search(T const & e) const
{
	search(e, _size, _header);
}

template <typename T>
ListNodePtr search(T const &e,int n,ListNodePtr p) cosnt
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
ListNodePtr selectMax() const
{
	return selectMax(_header,_size);
}

template <typename T>
ListNodePtr selectMax(ListNodePtr p,int n) const
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



#endif //_X_LISTIMPLEMENTION__H_
