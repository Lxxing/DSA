
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
//递归：前n - 1项之和，再累计第n - 1项,递归深度n+1
int sumRecursive(int A[],int len)
{

	int ret = 0;

	//递归基，
	if(0 == len)
	{
		return 0;
	}
	/*等效
	ret = A[len - 1];
	ret += sumRecursive(A,len - 1);
	return ret;*/

	/*
	调用多路递归算法
	return sumRecursive(A,0,n-1);
	*/
	return sumRecursive(A,len - 1) + A[len - 1];

}


//O(hi - lo + 1)，线性正比于区间的长度
int sumRecursive(int A[],int low,int high)
{

	int ret = 0;

	//递归基，
	if(low >= high)
	{
		return A[low];
	}

	int mid = (low + high) >> 1;//取中间节点

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
	std::cout << "迭代版本:  " << s << std::endl;

	s = 0;
    s = sumRecursive(A, n); 
	std::cout << "递归版本:  " << s << std::endl;
	
	s = 0;
    s = sumRecursive(A, 0, n - 1); 
	std::cout << "递归版本1:  " << s << std::endl;
	

	free(A);

}

