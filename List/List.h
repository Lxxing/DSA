#ifndef _LX_LIST__H_
#define _LX_LIST__H_

#include "ListNode.h"

//˫���б���ADT
template <typename T>
class List
{
public:
	List() {};
	~List() {};

	Rank size() const {return _size;}//�����ģ
	bool empty() const {return _size < 1;}//���ж�
	T& operator [] (Rank r) const {};

private:
	ListNodePtr _header;
	ListNodePtr _tailer;
	int _size;

};





#endif //_LX_LIST__H_
