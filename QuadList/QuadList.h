/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* ��ӭ����ָ��
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
	 //��*e��Ϊp�ĺ�̡�b�����ڲ���
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



