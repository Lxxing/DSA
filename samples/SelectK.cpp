/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* ��ӭ����ָ��
******************************************************************************************/


#include <iostream>
#include <time.h> 
#include <vector>
using namespace std;

////kѡȡ�㷨�����ڿ��ٻ���
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
			while (pivot <= A[hi] && lo < hi)//��Ҫ��Խ���ж�lo<hi
			{
				hi--;
			}
			A[lo] = A[hi];
			while (A[lo] <= pivot && lo < hi)//��Ҫ��Խ���ж�lo<hi
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



