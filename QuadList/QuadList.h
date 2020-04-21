/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/
#ifndef _QUAD_LIST_H_
#define _QUAD_LIST_H_

#include "QuadListNode.h" 

template <typename T>
class QuadList
{
public:

	QuadList();

	~QuadList();

	//ADT
	int Size() const;
	bool Empty() const;
	QuadListNodePtr First() const;
    QuadListNodePtr Last() const;
    bool IsValid (QuadListNodePtr p );
	T remove ( QuadListNodePtr p );
	 //将*e作为p的后继、b的上邻插入
	QuadListNodePtr InsertAfterAbove ( T const& e, QuadListNodePtr p, QuadListNodePtr b = NULL );

protected:
	void Init();
	void Clear();
private:
	int size;
	QuadListNodePtr header;
	QuadListNodePtr tailer;
};

#include "QuadListImpl.h"


#endif //_QUAD_LIST_H_



