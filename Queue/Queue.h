/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/

#ifndef _LX_QUEUE__H_
#define _LX_QUEUE__H_

#include <list>

namespace LX
{

template <typename T>
class Queue : public std::list<T>
{

public:

    void enqueue ( T const& e ) { push_back ( e ); } //入队：尾部插入
    T dequeue() { T rnt = front();pop_front(); return rnt;} //出队：首部删除
    //T& front() { return front(); } //队首。list包含此函数

};

}


#endif //_LX_QUEUE__H_


