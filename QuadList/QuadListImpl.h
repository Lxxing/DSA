/******************************************************************************************
** Data Structures in C++ 
** Auther : luxiang
** github:https://github.com/Lxxing?tab=repositories
** 欢迎交流指正 xiaoxiaomiantianwo@163.com
******************************************************************************************/
#ifndef _QUAD_LIST__IMPL_H_
#define _QUAD_LIST__IMPL_H_

template <typename T>
void QuadList::QuadList()
{
	Init();
}
template <typename T>
void QuadList::Size() const
{
	return size;
}

template <typename T>
bool QuadList::Empty() const
{
	return size > 0 ? false : true;
}

template <typename T>
QuadListNodePtr QuadList::First() const
{
	return header->succ;
}

template <typename T>
QuadListNodePtr QuadList::Last() const
{
	return tailer->pred;
}

template <typename T>
bool QuadList::IsValid(QuadListNodePtr p)
{
	return p && (header != p) && (tailer != p);
}

template <typename T>
T QuadList::remove(QuadListNodePtr p)
{
	//摘除节点
	p->pred->succ = p->succ; 
	p->succ->pred = p->pred; 
	size--;
	
	T e = p->entry; //备份词条，
	delete p; //释放节点
	
	return e; //返回词条
}

template <typename T>
QuadListNodePtr QuadList::InsertAfterAbove(T const& e, QuadListNodePtr p, QuadListNodePtr b = NULL)
{
	 size++; 
	 return p->InsertAsSuccAbove ( e, b );  
}

template <typename T>
void QuadList::~QuadList()
{
	Clear();

	delete header;
	delete tailer;
}


template <typename T>
void QuadList::Init()
{
	header = new QuadListNode<T>();
	tailer = new QuadListNode<T>();

	header->pred = NULL;
	header->succ = tailer;
	header->above = NULL;
	header->below = NULL;

	tailer->pred = header;
	tailer->succ = NULL;
	tailer->above = NULL;
	tailer->below = NULL;

	size = 0;
}

template <typename T>
void QuadList::Clear()
{
	int result = size;
	while ( 0 < size )
	{
		Remove ( header->succ);
	}

	return result;
}




#endif //_QUAD_LIST__IMPL_H_

