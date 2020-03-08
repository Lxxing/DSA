/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/

#include <iostream>
#include <string>

#include "Queue.h"

using namespace LX;

template <typename T>
void Print(Queue<T> const &e,std::string predstr = "Vector,")
{
	if (!predstr.empty())
	{
		std::cout << predstr << ":" ;
	}
	for (auto it = e.cbegin(); it != e.cend(); it++)
		std::cout << *it << ", ";
	std::cout << std::endl;

}

void main()
{
	Queue<int> queueint;
	std::cout << "empty:" << queueint.empty() << std::endl;
	for (int i = 0; i < 10; i++)
	{
		queueint.enqueue(i);
	}
	std::cout << "empty:" << queueint.empty() << std::endl;
	std::cout << "size:" << queueint.size() << std::endl;
	Print(queueint, "queueint:");

	while (!queueint.empty())
	{
		std::cout << "dequeue:" << queueint.dequeue() << std::endl;
	}


}



