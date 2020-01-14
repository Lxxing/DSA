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
	return origSize;//�����б�ԭʼ����
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
	return find(e,_size,_tailer);
}

template <typename T>//�����б��ڽڵ�p��n�����棩ǰ���У��ҵ�����e�������
ListNodePtr List<T>::find(T const &e, int n, ListNodePtr p) const
{
	ListNodePtr pCur = p;
	while (n-- >= 0)//�ӵ�0λ��ʼ
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

template <typename T>//�����б��ڽڵ�p��n�����棩ǰ���У��ҵ�������e�������
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

template <typename T>//p��ʼ��n���ڵ�
ListNodePtr List<T>::selectMax(ListNodePtr p,int n) const
{
	ListNodePtr pCur = p;
	ListNodePtr pMax = p;//����ǰ�ڵ㶨Ϊ���ڵ�
	while (n > 1)
	{
		pCur = pCur->succ;//Ҳ���Է���if�ж�֮�󣬵��Ƕ������θ��Լ��Ƚ�.n>1����������
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

template <typename T>//��ǰ�б�����self���selfsize��Ԫ�أ����б�L����q���size��Ԫ�ع鲢
void List<T>::merge(ListNodePtr &self, int selfsize, List<T>&L, ListNodePtr q, int size)
{

	ListNodePtr pCur = self->pred; //��ǹ鲢����������
	while ( 0 < size ) //��q��δ�Ƴ�����֮ǰ
	{
      if ( ( 0 < selfsize) && ( self->data <= q->data ) ) //��self������������v(self) <= v(q)����
      { 
          self = self->succ;//ȷ��self����Ԫ������,self����ϲ����б����滻Ϊ��ֱ�Ӻ��
          if ( q == self ) 
              break; 
          selfsize--;
      } 
      else //self�ѳ����ҽ��v(q) < v(self),��qת����self֮ǰ
      { 
          q = q->succ;//ȷ��q����Ԫ������
      	  T rmnode = L.remove(q->pred);//��q�����ó���Ԫ��
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

//�б��ѡ�������㷨����p��ʼ��n��Ԫ������(valid(p)&&rank(p)+n<_size)
template <typename T>
void List<T>::selectionSort ( ListNodePtr p, int n )
{
	ListNodePtr pHead = p->pred;//���뱣��ͷָ�룬��Ȼ����selectmax�����п��ܰѵ�ǰָ��ɾ����
	ListNodePtr pBar = p;//���������־���׽ڵ�
	for (int i = 0; i < n; ++i)
	{
		pBar = pBar->succ;
	}//���������ÿ�,������ռ�Ϊ(pHead,pBar)

	while (n > 1)//����������Ч����
	{
		ListNodePtr maxpnode = selectMax(pHead->succ, n);//��һ������Ҫ��pHead����һ���ڵ�
		T maxdata = remove(maxpnode);//����������ɾ��
		insertBefore(pBar,maxdata);//��ӵ��������䣬����Ϊ�׽ڵ�
		pBar = pBar->pred;//�ƶ����������׽ڵ�λ��
		n--;
	}

}

template <typename T> //valid(p)&&rank(p)+n<_size
void List<T>::insertionSort (ListNodePtr p, int n ) 
{ 
   for ( int r = 0; r < n; r++ ) //rҲ���������еļ���
   {
   	  ListNodePtr nd = search(p->data, r, p );//����λ�ýڵ�
      insertAfter( nd, p->data ); //����λ�ýڵ�
      p = p->succ; //ת����һ�ڵ�
      remove ( p->pred );//
   }
}

template <typename T> //valid(p)&&rank(p)+n<_size,�鲢���򣺶���ʼ��λ��p��n��Ԫ������
void List<T>::mergeSort ( ListNodePtr& p, int n)
{
	if (n <= 1)
	{
		return;//�ݹ����
	}

	ListNodePtr pother = p;//pother�ƶ����м�
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

template <typename T>//ɾ���ظ�Ԫ�أ�����ɾ��Ԫ�ظ���
int List<T>::deduplicate()
{
	ListNodePtr pHead = _header;
	ListNodePtr pBar = _tailer;
	int oldsize = _size;//��¼ԭʼ��ģ
	int rmsize = 0;//��¼ɾ���ĸ���
	int num = 0;//��¼�������еĸ���

	while (_tailer != pHead->succ)//������β�ڵ�
	{
		pHead = pHead->succ;
		ListNodePtr nd = find(pHead->data, num, pHead);//��������λ��
		if (NULL != nd)
		{
			T rm = remove(nd);//ɾ���ظ�
			rmsize++;//��¼�ظ�����
			continue;
		}
		num++;//��һ��λ�ò���
	}
	return oldsize - rmsize;
}

template <typename T>//ɾ���ظ�Ԫ�أ�����ɾ��Ԫ�ظ���
int List<T>::uniqufy()
{
	ListNodePtr pHead = _header;
	int oldsize = _size;//��¼ԭʼ��ģ

	while (_tailer != pHead->succ)//������β�ڵ�
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
