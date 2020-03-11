/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/

#include <iostream>
using namespace std;
#include <string>

#include "BinTree.h"

/*template <typename T>
void Print(List<T> const &e,string predstr = "List")
{
	if (!predstr.empty())
	{
		cout << predstr << ":" ;
	}
	for (int i = 0; i < e.size(); ++i)
	{
		cout << e[i] << ", ";
	}
	cout << endl;

}*/

int main()
{

	BinTree<int> bintree;
	cout <<"size:" << bintree.Size() << endl;
	cout <<"empty:" << bintree.Empty() << endl;
	int test = 100;
	bintree.InsertRoot(test);
	BinTreeNodeTPtr(int) root = bintree.Root();
	cout <<"size:" << bintree.Size() << endl;
	cout <<"empty:" << bintree.Empty() << endl;
	cout <<"data:" << root->data << endl;
	

}

