#include <iostream>
using namespace std;
#include <string>

#include "List.h"

template <typename T>
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

}

void PrintData(int & data)
{
	cout << data << ", ";
}
int main()
{

	List<int> lst;
	cout <<"size:" << lst.size() << endl;
	cout <<"empty:" << lst.empty() << endl;
	lst.insertAsFirst(3);//3,
	Print(lst);
	lst.insertAsLast(0);//3,0
	Print(lst);
	lst.insertAsFirst(4);//4,3,0
	Print(lst);
	lst.insertAfter(lst.first(), 1);//4,1,3,0
	Print(lst);
	lst.insertAfter(lst.first(), 2);//4,2,1,3,0
	Print(lst);
	lst.insertBefore(lst.last(), 9);//4,2,1,3,9£¬0,
	Print(lst);
	lst.insertBefore(lst.last(), 8);//4,2,1,3,9,8£¬0,
	Print(lst);
	ListNodeTPtr(int) max = lst.selectMax();
	cout << "max:" << max->data << endl;//9
	int rm = lst.remove(max);
	lst.insertAsLast(rm);//4,2,1,3,8,0,9
	lst.insertAsLast(rm);//4,2,1,3,8,0,9,9
	Print(lst);
	lst.insertAfter(lst.first(), 4);//4,4,2,1,3,8,0,9,9
	ListNodeTPtr(int) nd3 = lst.find(3);
	lst.insertBefore(nd3, 3);//4,4,2,1,3,3,8,0,9,9
	Print(lst);

	List<int> lstpre(lst);
	Print(lstpre, "lstpre:");
	lstpre.deduplicate();
	Print(lstpre,"lstpre deduplicate:");//4, 2, 1, 3, 8, 0, 9

	lst.sort();//0,1,2,3,3,4,4,8,9,9
	Print(lst);		
	lst.uniqufy();
	Print(lst, "lst uniqufy:");
	
	ListNodeTPtr(int) snd4 = lst.search(4);
	lst.insertAfter(snd4,4);
	ListNodeTPtr(int) snd8 = lst.search(8);
	lst.insertAfter(snd8, 8);
	ListNodeTPtr(int) snd3 = lst.search(3);
	Print(lst);
	lst.tranvers(PrintData);

}
