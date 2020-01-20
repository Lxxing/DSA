
#include <iostream>
using namespace std;
#include <time.h> 

#include "LXUtil.h"
using namespace LXUtil;

int sum(int A[], int len)
{

	int ret = 0;

	for(int i = 0; i < len; i++)
	{
		ret += A[i];
	}

	return ret;

}
//�ݹ飺ǰn - 1��֮�ͣ����ۼƵ�n - 1��,�ݹ����n+1
int sumRecursive(int A[],int len)
{

	int ret = 0;

	//�ݹ����
	if(0 == len)
	{
		return 0;
	}
	/*��Ч
	ret = A[len - 1];
	ret += sumRecursive(A,len - 1);
	return ret;*/

	/*
	���ö�·�ݹ��㷨
	return sumRecursive(A,0,n-1);
	*/
	return sumRecursive(A,len - 1) + A[len - 1];

}


//O(hi - lo + 1)����������������ĳ���
int sumRecursive(int A[],int low,int high)
{

	int ret = 0;

	//�ݹ����
	if(low >= high)
	{
		return A[low];
	}

	int mid = (low + high) >> 1;//ȡ�м�ڵ�

	return sumRecursive(A, low, mid) + sumRecursive(A, mid + 1, high);

}


int main()
{
	int n = 10;
	int* A = (int*)malloc(n * sizeof(int)); 

 	unsigned int seed = (unsigned int)time(NULL);
    randomArray(A, n, seed); 
    std::cout << "-->  ";
    print(A, n);
	//0 + 1 + ... + n=n*(n-1)/2 
    int s = sum(A, n); 
	std::cout << "�����汾:  " << s << std::endl;

	s = 0;
    s = sumRecursive(A, n); 
	std::cout << "�ݹ�汾:  " << s << std::endl;
	
	s = 0;
    s = sumRecursive(A, 0, n - 1); 
	std::cout << "�ݹ�汾1:  " << s << std::endl;
	

	free(A);

}

