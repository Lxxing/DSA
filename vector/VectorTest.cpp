/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/

#include <iostream>
#include <string>

#include "Vector.h"

using namespace LX;

template <typename T>
void Print(vector<T> const &e,std::string predstr = "Vector,")
{
	if (!predstr.empty())
	{
		std::cout << predstr << ":" ;
	}
	for (int i = 0; i < e.size(); ++i)
	{
		std::cout << e[i] << ", ";
	}
	std::cout << std::endl;

}

void main()
{
	vector<int> vecint;
	std::cout << "empty:" << vecint.empty() << std::endl;
	for (int i = 0; i < 10; i++)
	{
		vecint.insert(i);
	}
	vecint.insert(4,20);
	std::cout << "empty:" << vecint.empty() << std::endl;
	std::cout << "size:" << vecint.size() << std::endl;
	Print(vecint, "vecint:");

	std::cout << "at(5):" << vecint.at(5) << std::endl;

	std::cout << "vecint(5):" << vecint[5] << std::endl;

	std::cout << "remove(5):" << vecint.remove(5) << std::endl;
	Print(vecint, "vecint:");

	std::cout << "remove(7,9):" << vecint.remove(7,9) << std::endl;
	Print(vecint, "vecint:");

	std::cout << "find:" << vecint.find(20) << std::endl;
	vecint.insert(20);
	Print(vecint, "vecint:");
	std::cout << "deduplicate:" << vecint.deduplicate() << std::endl;
	Print(vecint, "vecint:");
	std::cout << "find:" << vecint.find(10) << std::endl;
	vecint.sort();
	Print(vecint, "vecint:");
	vecint.permute();
	Print(vecint, "vecint:");
	vecint.sort();
	Print(vecint, "vecint:");
	std::cout << "find:" << vecint.search(20) << std::endl;


}


