/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/
#ifndef __X_LXUTIL__H_
#define __X_LXUTIL__H_
	


namespace LXUtil
{
typedef int Rank;

void shuffle(int A[], int n); //随机置乱整数数组A[0, n)
void shuffle(int A[], int lo, int hi); //随机置乱整数数组区间A[lo, hi)
void print(int A[], int n); //输出整数数组A[0, n)
void print(int A[], int n, int lo, int hi); //输出整数数组区间A[lo, hi)
void randomArray(int A[], int n, int seed);
    
template <typename T> // 二分查找：有序区间[lo, hi)内查找元素e
static Rank binSearch ( T* A, T const& e, Rank lo, Rank hi )
{
	while (lo < hi)//有效区间为0
	{
		int mid = (lo + hi) >> 1;
   		if (e < A[mid])
   		{
   			hi = mid;//[lo,mid)
   		}
   		else if (e > A[mid])
		{
			lo = mid + 1;//(mid,hi),不包括mid节点
		}
		else//去掉等于分支能减小最坏时间复杂度的常数项，但最好的复杂度也将降低
		{
			return mid;
		}
	}
	return -1;
    
}
	
 
template <typename T> // 二分查找2
static Rank binSearch2 ( T* A, T const& e, Rank lo, Rank hi )
{
	while (1 < hi - lo)//有效区间为1
	{
		int mid = (lo + hi) >> 1;
   		if (e < A[mid])
   		{
   			hi = mid;//[lo,mid)
   		}
   		else
		{
			lo = mid;//[mid, hi)
		}
	}
	//此时区间[lo,hi)，hi=lo+1,
	return e == A[lo] ? lo : -1;
    
}

template <typename T> // 二分查找3
static Rank binSearch3 ( T* A, T const& e, Rank lo, Rank hi )
{
	while (lo < hi)//有效区间为0
	{
		int mid = (lo + hi) >> 1;
   		if (e < A[mid])
   		{
   			hi = mid;//[lo,mid)
   		}
   		else
		{
			lo = mid + 1;//(mid, hi)
		}
	}
	
	return --lo;//将不大于e的最大秩返回作为有效信息
    
}


}//end of LXUtil

#endif //__X_LXUTIL__H_

