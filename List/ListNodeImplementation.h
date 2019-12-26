#ifndef _X_LISTNODEIMPLEMENTATION__H_
#define _X_LISTNODEIMPLEMENTATION__H_


template <typename T>
ListNode<T>::ListNode()
{
	this->data = NULL;
	this->pred = NULL;
	this->succ = NULL;
}

template <typename T>
ListNode<T>::ListNode(const T &e)
{
	this->data = e;
	this->pred = NULL;
	this->succ = NULL;
}


template <typename T>
ListNode<T>::~ListNode()
{
	this->data = NULL;
	this->pred = NULL;
	this->succ = NULL;
}

#endif //_X_LISTNODEIMPLEMENTATION__H_
