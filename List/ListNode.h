#ifndef __LISTNODE__H_
#define __LISTNODE__H_


typedef int Rank;    //����ͳһ��rank����
#define ListNodePtr ListNode<T>*   //ָ��
template <typename T>
struct ListNode
{
	T data;	//����
	ListNodePtr pred;	//ǰ��prediction
	ListNodePtr succ;	//���

	ListNode() {};
	~ListNode() {};

	
	

};



#endif //__LISTNODE__H_