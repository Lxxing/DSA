/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* ��ӭ����ָ��
******************************************************************************************/
#ifndef __X_LXUTIL__H_
#define __X_LXUTIL__H_
	


namespace LXUtil
{
typedef int Rank;

void shuffle(int A[], int n); //���������������A[0, n)
void shuffle(int A[], int lo, int hi); //�������������������A[lo, hi)
void print(int A[], int n); //�����������A[0, n)
void print(int A[], int n, int lo, int hi); //���������������A[lo, hi)
void randomArray(int A[], int n, int seed);
    
template <typename T> // ���ֲ��ң���������[lo, hi)�ڲ���Ԫ��e
static Rank binSearch ( T* A, T const& e, Rank lo, Rank hi )
{
	while (lo < hi)//��Ч����Ϊ0
	{
		int mid = (lo + hi) >> 1;
   		if (e < A[mid])
   		{
   			hi = mid;//[lo,mid)
   		}
   		else if (e > A[mid])
		{
			lo = mid + 1;//(mid,hi),������mid�ڵ�
		}
		else//ȥ�����ڷ�֧�ܼ�С�ʱ�临�Ӷȵĳ��������õĸ��Ӷ�Ҳ������
		{
			return mid;
		}
	}
	return -1;
    
}
	
 
template <typename T> // ���ֲ���2
static Rank binSearch2 ( T* A, T const& e, Rank lo, Rank hi )
{
	while (1 < hi - lo)//��Ч����Ϊ1
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
	//��ʱ����[lo,hi)��hi=lo+1,
	return e == A[lo] ? lo : -1;
    
}

template <typename T> // ���ֲ���3
static Rank binSearch3 ( T* A, T const& e, Rank lo, Rank hi )
{
	while (lo < hi)//��Ч����Ϊ0
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
	
	return --lo;//��������e������ȷ�����Ϊ��Ч��Ϣ
    
}


}//end of LXUtil

#endif //__X_LXUTIL__H_

