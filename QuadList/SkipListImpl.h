/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/
#ifndef _SKIP_LIST_IMPL_H_
#define _SKIP_LIST_IMPL_H_

template <typename K,typename V>
bool SkipList::SkipSearch (     ListNode<QuadList<Entry<K, V>>*>* &qlist,
      QuadListNode<Entry<K, V>>* &p,K& k )
{

}

template <typename K,typename V>
int SkipList::Size() const
{
	return empty() ? 0 : First()->front()
}

template <typename K,typename V>
bool SkipList::Put(K k, V v)
{
	
}

template <typename K,typename V>
V* SkipList:: Get(K k)
{
	
}

template <typename K,typename V>
bool SkipList::Remove(K k) const
{
	
}





#endif //_SKIP_LIST_IMPL_H_




