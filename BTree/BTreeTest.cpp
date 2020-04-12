/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/

#include <iostream>
using namespace std;
#include <string>

#include "BTree.h"

void PrintData(int & data)
{
	cout  << data << ", ";
}

static int RandBin(int h = 100)
{
	return rand() % h;
}
int main()
{

	BTree<int> bintree;
	cout <<"size:" << bintree.Size() << endl;
	cout <<"empty:" << bintree.Empty() << endl;
	int test = 36;

	
	BTreeNodeTPtr(int) s1 = bintree.Search(40);
	if (NULL == s1)
	{
		cout << "search error" << endl;
	}
    s1 = bintree.Search(46);

	bintree.Insert(40);
	
	bintree.Remove(69);

	bintree.Remove(58);

	bintree.Remove(36);

}



