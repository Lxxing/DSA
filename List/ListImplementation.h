#ifndef _X_LISTIMPLEMENTION__H_
#define _X_LISTIMPLEMENTION__H_

template <typename T>
void List<T>::init()
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
List<T>::List()
{
	init();
}

template <typename T>
List<T>::List ( List<T> const& L )
{
	init();

	ListNodePtr pCur = L.first()->pred;	
	for (int i = 0; i < L.size(); i++)
	{
		pCur = pCur->succ;
		insertAsLast(pCur->data);
	}
}

template <typename T>
List<T>::~List()
{
	clear();
	delete _header;
	delete _tailer;
}

template <typename T>
int List<T>::clear()
{
	int origSize = _size;
	while (_size > 0)
	{
		remove(_header->succ);
	}
	return origSize;//返回列表原始个数
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
	return find(e,_size,_tailer);
}

template <typename T>//无序列表内节点p的n个（真）前驱中，找到等于e的最后者
ListNodePtr List<T>::find(T const &e, int n, ListNodePtr p) const
{
	ListNodePtr pCur = p;
	while (n-- >= 0)//从第0位开始
	{
		pCur = pCur->pred;
		if (e == pCur->data)
		{
			return pCur;
		}
		
	}
	return NULL;
}

template <typename T>
ListNodePtr List<T>::search(T const & e) const
{
	return search(e, _size, _tailer);
}

template <typename T>//有序列表内节点p的n个（真）前驱中，找到不大于e的最后者
ListNodePtr List<T>::search(T const &e,int n,ListNodePtr p) const
{
	ListNodePtr pCur = p;
	while (n-- >= 0)
	{
		pCur = pCur->pred;
		if (e >= pCur->data)
		{
			return pCur;
		}
		
	}
	return NULL;
}

template <typename T>
ListNodePtr List<T>::selectMax() const
{
	return selectMax(_header,_size);
}

template <typename T>//p开始的n个节点
ListNodePtr List<T>::selectMax(ListNodePtr p,int n) const
{
	ListNodePtr pCur = p;
	ListNodePtr pMax = p;//将当前节点定为最大节点
	while (n > 1)
	{
		pCur = pCur->succ;//也可以放在if判断之后，但是多了依次跟自己比较.n>1不包含本身
		if (pMax->data < pCur->data)
		{
			pMax = pCur;
		}

		n--;
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

template <typename T>//当前列表中自self起的selfsize个元素，与列表L中自q起的size个元素归并
void List<T>::merge(ListNodePtr &self, int selfsize, List<T>&L, ListNodePtr q, int size)
{

	ListNodePtr pCur = self->pred; //标记归并后区间的起点
	while ( 0 < size ) //在q尚未移出区间之前
	{
      if ( ( 0 < selfsize) && ( self->data <= q->data ) ) //若self仍在区间内且v(self) <= v(q)，则
      { 
          self = self->succ;//确定self的新元素区间,self归入合并的列表，并替换为其直接后继
          if ( q == self ) 
              break; 
          selfsize--;
      } 
      else //self已超出右界或v(q) < v(self),将q转移至self之前
      { 
          q = q->succ;//确定q的新元素区间
      	  T rmnode = L.remove(q->pred);//从q区间拿出的元素
      	  insertBefore(self, rmnode);
      	  size--; 
      } 
   	}

	self = pCur->succ;
}

template <typename T>
void List<T>::merge(List<T> &l)
{
	merge(first(), _size, l, l.first(), l.size());
}

template <typename T>
void List<T>::sort(ListNodePtr p,int n)
{
	//int casen = rand()%3;
	int casen = 3;
	switch (casen)
	{
		case 1:
			selectionSort(p,n);
			break;
		case 2:
			insertionSort(p,n);
			break;
		case 3:
			mergeSort(p,n);
			break;
	}
	
}

template <typename T>
void List<T>::sort()
{
	sort(first(),_size);
}

//列表的选择排序算法：从p开始的n个元素排序(valid(p)&&rank(p)+n<_size)
template <typename T>
void List<T>::selectionSort ( ListNodePtr p, int n )
{
	ListNodePtr pHead = p->pred;//必须保存头指针，不然调用selectmax，会有可能把当前指针删除掉
	ListNodePtr pBar = p;//有序区间标志，首节点
	for (int i = 0; i < n; ++i)
	{
		pBar = pBar->succ;
	}//有序区间置空,待排序空间为(pHead,pBar)

	while (n > 1)//至少两个有效数据
	{
		ListNodePtr maxpnode = selectMax(pHead->succ, n);//第一个参数要用pHead的下一个节点
		T maxdata = remove(maxpnode);//从无序区间删除
		insertBefore(pBar,maxdata);//添加到有序区间，并作为首节点
		pBar = pBar->pred;//移动有序区间首节点位置
		n--;
	}

}

template <typename T> //valid(p)&&rank(p)+n<_size
void List<T>::insertionSort (ListNodePtr p, int n ) 
{ 
   for ( int r = 0; r < n; r++ ) //r也是有序序列的计数
   {
   	  ListNodePtr nd = search(p->data, r, p );//查找位置节点
      insertAfter( nd, p->data ); //插入位置节点
      p = p->succ; //转向下一节点
      remove ( p->pred );//
   }
}

template <typename T> //valid(p)&&rank(p)+n<_size,归并排序：对起始于位置p的n个元素排序
void List<T>::mergeSort ( ListNodePtr& p, int n)
{
	if (n <= 1)
	{
		return;//递归基础
	}

	ListNodePtr pother = p;//pother移动到中间
	int mid = n >> 1;
	for (int i = 0; i < mid; i++)
	{
		pother = pother->succ;
	}

	mergeSort(p, mid);
	mergeSort(pother, n - mid);
	merge(p,mid,*this,pother,n - mid);
	
	return;
}

template <typename T>//删除重复元素，返回删除元素个数
int List<T>::deduplicate()
{
	ListNodePtr pHead = _header;
	ListNodePtr pBar = _tailer;
	int oldsize = _size;//记录原始规模
	int rmsize = 0;//记录删除的个数
	int num = 0;//记录有序序列的个数

	while (_tailer != pHead->succ)//遍历到尾节点
	{
		pHead = pHead->succ;
		ListNodePtr nd = find(pHead->data, num, pHead);//查找数据位置
		if (NULL != nd)
		{
			T rm = remove(nd);//删除重复
			rmsize++;//记录重复个数
			continue;
		}
		num++;//下一个位置查找
	}
	return oldsize - rmsize;
}

template <typename T>//删除重复元素，返回删除元素个数
int List<T>::uniqufy()
{
	ListNodePtr pHead = _header;
	int oldsize = _size;//记录原始规模

	while (_tailer != pHead->succ)//遍历到尾节点
	{
		pHead = pHead->succ;
		if (pHead->data == pHead->succ->data)
		{
			remove(pHead->succ);
		}
	}
	return oldsize - _size;

}

template <typename T>
void List<T>::tranvers(void (* usrVisit) (T&))
{
	for (ListNodePtr pCur = first(); pCur != _tailer; pCur = pCur->succ)
	{
		usrVisit(pCur->data);
	}
}

template <typename T> template <typename VST> 
void List<T>::tranvers ( VST& usrVisit )
{  
	for (ListNodePtr pCur = first(); pCur != _tailer; pCur = pCur->succ)
	{
		usrVisit(pCur->data);
	}
}



#endif //_X_LISTIMPLEMENTION__H_
