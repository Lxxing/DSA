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

	BinTree<int> bintree;
	cout <<"size:" << bintree.Size() << endl;
	cout <<"empty:" << bintree.Empty() << endl;
	int test = 100;
	bintree.InsertRoot(test);
	BinTreeNodeTPtr(int) root = bintree.Root();
	cout <<"size:" << bintree.Size() << endl;
	cout <<"empty:" << bintree.Empty() << endl;
	cout <<"data:" << root->data << endl;
	root->TravLevel(PrintData);
	//bintree.InsertLChild(root,RandBin());
	BinTreeNodeTPtr(int) rootl = bintree.InsertLChild(root,RandBin());
	//bintree.InsertRChild(root,RandBin());
	BinTreeNodeTPtr(int) rootr = bintree.InsertRChild(root,RandBin());
	cout << "\n--TravLevel---" << endl;
	root->TravLevel(PrintData);
	cout << "\n--TravPre---" << endl;
	root->TravPre(PrintData);
	cout << "\n--TravIn---" << endl;
	root->TravIn(PrintData);
	cout << "\n--TravPost---" << endl;
	root->TravPost(PrintData);
	cout << "-----" << endl;
	
	BinTree<int> *binL = new BinTree<int>();
	test = 20;
	binL->InsertRoot(test);
	binL->InsertLChild(binL->Root(),RandBin(test));
	binL->InsertLChild(binL->Root(),RandBin(test));
	binL->InsertRChild(binL->Root(),RandBin(test));
	binL->InsertRChild(binL->Root(),RandBin(test));
	cout << "\n--TravLevel---" << endl;
	binL->TravLevel(PrintData);
	cout << "\n--TravPre---" << endl;
	binL->TravPre(PrintData);
	cout << "\n--TravIn---" << endl;
	binL->TravIn(PrintData);
	cout << "\n--TravPost---" << endl;
	binL->TravPost(PrintData);
	cout << "-----" << endl;
	
	BinTree<int> *binR = new BinTree<int>();
	test = 30;
	binR->InsertRoot(test);
	binR->InsertLChild(binR->Root(),RandBin(test));
	binR->InsertLChild(binR->Root(),RandBin(test));
	binR->InsertRChild(binR->Root(),RandBin(test));
	binR->InsertRChild(binR->Root(),RandBin(test));
	cout << "\n--TravLevel---" << endl;
	binR->TravLevel(PrintData);
	cout << "\n--TravPre---" << endl;
	binR->TravPre(PrintData);
	cout << "\n--TravIn---" << endl;
	binR->TravIn(PrintData);
	cout << "\n--TravPost---" << endl;
	binR->TravPost(PrintData);
	cout << "-----" << endl;

	
	bintree.InsertLTree(rootl,binL);
	bintree.TravLevel(PrintData);
	cout << "-----" << endl;
	bintree.InsertRTree(rootr,binR);

	cout << "\n--TravLevel---" << endl;
	bintree.TravLevel(PrintData);
	cout << "\n--TravPre---" << endl;
	bintree.TravPre(PrintData);
	cout << "\n--TravIn---" << endl;
	bintree.TravIn(PrintData);
	cout << "\n--TravPost---" << endl;
	bintree.TravPost(PrintData);
	cout << "-----" << endl;
	
	BinTree<int> *testl = bintree.Secede(rootl);
	bintree.TravLevel(PrintData);
	cout << "-----" << endl;
	testl->TravLevel(PrintData);
	cout << "-----" << endl;
}

