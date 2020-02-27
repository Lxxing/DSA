/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/


#include "Stack.h"
using namespace LX;

#include <iostream>
#include <string>

//#include <stack>
void main()
{
	Stack<int> stackTest;
	std::cout << "empty:" << stackTest.empty() << std::endl;
	int testn = 11;
	stackTest.push(testn);
	stackTest.push(testn =12);
	stackTest.push(testn = 13);
	std::cout << "empty:" << stackTest.empty() << std::endl;
	std::cout << "size:" << stackTest.size() << std::endl;
	std::cout << "top:" << stackTest.top() << std::endl;
	std::cout << "pop:" << stackTest.pop() << std::endl;
	std::cout << "top:" << stackTest.top() << std::endl;
	std::cout << "pop:" << stackTest.pop() << std::endl;
	std::cout << "top:" << stackTest.top() << std::endl;
	std::cout << "pop:" << stackTest.pop() << std::endl;
	std::cout << "size:" << stackTest.size() << std::endl;



}
