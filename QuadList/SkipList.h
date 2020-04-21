/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/
#ifndef __SKIP_LIST__H_
#define __SKIP_LIST__H_

#include <list.h>

#include "Dictionary.h"
#include "QuadList.h"


template <typename K,typename V>
class SkipList : public Dictionary<K,V>,list< QuadList<Entry<K,V> >* >
{
protected:
	bool SkipSearch (     ListNode<QuadList<Entry<K, V>>*>* &qlist,
      QuadListNode<Entry<K, V>>* &p,K& k );

public:
	int Size() const;
	bool Put(K k, V v);
	V* Get(K k);
	bool Remove(K k);

};


#include "SkipListImpl.h"



#endif //__SKIP_LIST__H_

