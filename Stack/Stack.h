/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/
#ifndef _X_STACK__H_
#define _X_STACK__H_

#include <iostream>
#include <vector>

namespace LX
{

template <typename T>
class Stack : public std::vector<T>
{
public:
	void push(T & e)//入栈：将新元素作为末元素插入
	{
		this->push_back(e);
	}
	/*void push(T e)
	{
		this->insert(e);
	}*/

	T pop()//出栈：删除末元素
	{
		T rnt = this->back();
		this->pop_back();
		return rnt;
	}

	T & top()//取顶：返回末元素
	{
		return this->at(size() - 1);
	}

};


}


#endif //_X_STACK__H_

