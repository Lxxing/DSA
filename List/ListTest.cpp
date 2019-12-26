#include <iostream>
using namespace std;

#include "List.h"

template <typename T>
void Print(List<T> const &e)
{
	for (int i = 0; i < e.size(); ++i)
	{
		cout << e[i] << ", ";
	}
	cout << endl;

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
	lst.insertBefore(lst.last(), 9);//4,2,1,3,0,9
	Print(lst);
	lst.insertBefore(lst.last(), 8);//4,2,1,3,00,9,8
	Print(lst);


}