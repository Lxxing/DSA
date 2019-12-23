#ifndef _LX_LIST__H_
#define _LX_LIST__H_

#include "ListNode.h"

//双向列表类ADT
template <typename T>
class List
{
public:
	List() {};
	~List() {};

	Rank size() const {return _size;}//整体规模
	bool empty() const {return _size < 1;}//空判断
	T& operator [] (Rank r) const {};

private:
	ListNodePtr _header;
	ListNodePtr _tailer;
	int _size;

};





#endif //_LX_LIST__H_
