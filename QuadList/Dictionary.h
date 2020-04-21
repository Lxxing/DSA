/******************************************************************************************
** Data Structures in C++ 
** Auther : luxiang
** github:https://github.com/Lxxing?tab=repositories
** 欢迎交流指正 xiaoxiaomiantianwo@163.com
******************************************************************************************/
#ifndef __DICTIONARY_ENTRY__H_
#define __DICTIONARY_ENTRY__H_


template <typename K,typename V>
class Dictionary
{
public:
	virtual int Size() const = 0;
	virtual bool Put(K k, V v) = 0;
	virtual V* Get(K k) = 0;
	virtual bool Remove(K k) = 0;
};

template <typename K,typename V>
class Entry
{
public:
	K key;
	V value;

	Entry(K k = K(),V v = V())
		:key(k),value(v)
	{}

	bool operator < (Entry<K,V> const & e){ return this.key < e.key}
	bool operator > (Entry<K,V> const &e){return this.key > e.key}
	bool operator != (Entry<K,V> const &e){return this.key != e.key}
	bool operator == (Entry<K,V> const &e){return this.key == e.key}
};



#endif //__DICTIONARY_ENTRY__H_

