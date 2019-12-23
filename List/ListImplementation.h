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


#endif //_X_LISTIMPLEMENTION__H_
