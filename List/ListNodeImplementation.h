#ifndef _X_LISTNODEIMPLEMENTATION__H_
#define _X_LISTNODEIMPLEMENTATION__H_


template <typename T>
ListNode::ListNode()
{
	this->data = NULL;
	this->pred = NULL;
	this->succ = NULL;
}


template <typename T>
ListNode::~ListNode()
{
	this->data = NULL;
	this->pred = NULL;
	this->succ = NULL;
}

#endif //_X_LISTNODEIMPLEMENTATION__H_
