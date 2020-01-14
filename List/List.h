#ifndef _LX_LIST__H_
#define _LX_LIST__H_

#include "ListNode.h"

//双向列表类ADT
template <typename T>
class List
{
public:
	List();
	List ( List<T> const& L ); //整体复制列表L
	~List();

	Rank size() const;//整体规模
	bool empty() const;//空判断
	T& operator [] (Rank r) const;//寻秩访问，O(n)
	ListNodePtr first() const; //首节点
	ListNodePtr last() const;    //尾结点
	int clear(); //清除所有节点,不包括头尾
	bool valid(ListNodePtr p) const;	//节点是否有效
	int disordered() const;     //判断列表是否有序
	ListNodePtr find(T const & e) const;    //无序链表查找
	ListNodePtr find(T const &e, int n, ListNodePtr p) const;    //无序链表区间查找
	ListNodePtr search(T const & e) const;   //有序查找
	ListNodePtr search(T const &e,int n,ListNodePtr p) const;//有序区间查找
	ListNodePtr selectMax(ListNodePtr p,int n) const;    //p节点后的n-1个后继中最大
	ListNodePtr selectMax() const;    //整个链表最大

	ListNodePtr insertAsFirst(T const &e);//e作为首节点插入
	ListNodePtr insertAsLast(T const &e);//e作为尾节点插入
	ListNodePtr insertBefore(ListNodePtr p,T const &e);//e作为p前驱插入
	ListNodePtr insertAfter(ListNodePtr p,T const &e);//e作为p后继插入
	T remove(ListNodePtr p);//删除节点p，返回删除节点
	void merge(List<T> &l);//全列表归并
	void sort(ListNodePtr p,int n);//列表区间排序
	void sort();//列表全排序
	int deduplicate();//无序去重
	int uniqufy();//有序去重
	void reverse();//反转列表

	//遍历
	void tranvers(void (*) (T&));
	template <typename VST>
	void tranvers(VST& vst);//遍历
protected:
	void init();//初始化头尾节点
	void merge ( ListNodePtr&, int, List<T>&, ListNodePtr, int ); //有序列表的归并
	void mergeSort ( ListNodePtr &, int ); //归并排序,从p开始的n个节点
	void selectionSort ( ListNodePtr p, int n );//选择排序，从p开始的n个节点
	void insertionSort ( ListNodePtr, int ); //插入排序,对从p开始的n个节点
private:
	ListNodePtr _header;
	ListNodePtr _tailer;
	int _size;

};


#include "ListImplementation.h"


#endif //_LX_LIST__H_
