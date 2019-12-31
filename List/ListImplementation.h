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
	ListNodePtr pCur = first();//灏忔爣浠?寮�濮嬶紝瀵瑰簲鐨勫疄闄呮暟鎹簲璇ヤ粠绗竴涓妭鐐瑰紑濮?
	while (r--)//r涓?锛岃繑鍥為鑺傜偣锛宺>0鏃讹紝寰幆r娆★紝鎸囧悜绗瑀涓暟鎹?
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

template <typename T>//删除节点p,返回节点数据
T List<T>::remove(ListNodeTPtr(T) p)
{
	//如果上层都赋值有效的节点，此处不需要判断头尾节点
	if (p == _header || p == _tailer)
	{
		return -1;
	}
	T rnt = p->data;//备份删除节点数值，（T类型必须重载=操作符）
	p->succ->pred = p->pred;
	p->pred->succ = p->succ;
	delete p;//释放
	_size--;//计数
	
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

//列表的选择排序算法：从p开始的n个元素排序
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
