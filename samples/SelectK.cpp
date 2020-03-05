/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/


#include <iostream>
#include <time.h> 
#include <vector>
using namespace std;

////k选取算法：基于快速划分
template <typename T>
void quickSelect(vector<T> A,int k)
{
	int pre = 0;
	int suc = A.size() - 1;

	for ( ;pre < suc; )
	{
		int lo = pre;
		int hi = suc;
		T pivot = A[lo];
		while (lo < hi)
		{
			while (pivot <= A[hi] && lo < hi)//需要加越界判断lo<hi
			{
				hi--;
			}
			A[lo] = A[hi];
			while (A[lo] <= pivot && lo < hi)//需要加越界判断lo<hi
			{
				lo++;
			}
			A[hi] = A[lo];
		}//assert(lo==hi)
		A[lo] = pivot;

		if (k <= lo)
		{
			suc = lo - 1;
		}
		if (k >= lo)
		{
			pre = lo + 1;
		}
	}
	
}


void main()
{

	vector<int> S1 = {8,1,3,5,9};
	quickSelect(S1,3);
	cout << "median:"  << endl;
}



