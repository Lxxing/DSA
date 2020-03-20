/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/

#include <iostream>
using namespace std;
#include <string>

#include "BST.h"

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

	BST<int> bintree;
	cout <<"size:" << bintree.Size() << endl;
	cout <<"empty:" << bintree.Empty() << endl;
	int test = 36;
	bintree.InsertRoot(test);
	BinTreeNodeTPtr(int) root = bintree.Root();
	cout <<"size:" << bintree.Size() << endl;
	cout <<"empty:" << bintree.Empty() << endl;
	cout <<"data:" << root->data << endl;
	root->TravLevel(PrintData);
	
	
	BinTree<int> *binL = new BST<int>();
	test = 27;
	binL->InsertRoot(test);
	binL->InsertLChild(binL->Root(),6);

	cout << "\n--TravLevel---" << endl;
	binL->TravLevel(PrintData);
	cout << "\n--TravPre---" << endl;
	binL->TravPre(PrintData);
	cout << "\n--TravIn---" << endl;
	binL->TravIn(PrintData);
	cout << "\n--TravPost---" << endl;
	binL->TravPost(PrintData);
	cout << "-----" << endl;
	
	BinTree<int> *binR = new BST<int>();
	test = 58;
	binR->InsertRoot(test);
	BinTreeNodeTPtr(int) n53 = binR->InsertLChild(binR->Root(),53);
	binR->InsertLChild(n53,46);
	BinTreeNodeTPtr(int) n69 = binR->InsertRChild(binR->Root(),69);
	binR->InsertRChild(n69,64);
	cout << "\n--TravLevel---" << endl;
	binR->TravLevel(PrintData);
	cout << "\n--TravPre---" << endl;
	binR->TravPre(PrintData);
	cout << "\n--TravIn---" << endl;
	binR->TravIn(PrintData);
	cout << "\n--TravPost---" << endl;
	binR->TravPost(PrintData);
	cout << "-----" << endl;

	
	bintree.InsertLTree(root,binL);
	bintree.TravLevel(PrintData);
	cout << "-----" << endl;
	bintree.InsertRTree(root,binR);

	cout << "\n--TravLevel---" << endl;
	bintree.TravLevel(PrintData);
	cout << "\n--TravPre---" << endl;
	bintree.TravPre(PrintData);
	cout << "\n--TravIn---" << endl;
	bintree.TravIn(PrintData);
	cout << "\n--TravPost---" << endl;
	bintree.TravPost(PrintData);
	cout << "-----" << endl;


	BinTreeNodeTPtr(int) s1 = bintree.Search(40);
	if (NULL == s1)
	{
		cout << "search error" << endl;
	}
    s1 = bintree.Search(46);
	if (NULL != s1)
	{
		cout << "search ok:" << s1->height <<endl;
	}
	bintree.Insert(40);
	cout << "\n--TravIn---" << endl;
	bintree.TravIn(PrintData);
	bintree.Remove(69);
	cout << "\n--TravIn---" << endl;
	bintree.TravIn(PrintData);
	bintree.Remove(58);
	cout << "\n--TravIn---" << endl;
	bintree.TravIn(PrintData);
	bintree.Remove(36);
	cout << "\n--TravIn---" << endl;
	bintree.TravIn(PrintData);
}


