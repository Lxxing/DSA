/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/

#include "bubble.h"

void bubblesort ( int A[], int len ) 
{ 
	//int legth = sizeof(A) / sizeof(a[1]);这儿的A是个指针，计算结果为1
	for (size_t i = len; i > 0; i--)//等价于while(len--).遍历的个数
	{
		for (size_t j = 1; j < i; j++)//A[0,i),利用数组的最右端的边界i。其实也可以直接用最右边的边界，但是这样会增加复杂度
		{
			if (A[j - 1] > A[j])
			{
				swap(A[j - 1],A[j]);
			}
		}

	}
	/*
	当我开始学的时候，总是想从头开始循环，这个时候第二个循环的判断天骄就是
	j < len -i.即i表示遍历的次数，也是已经排好的个数。所以len -i 就是第二个
	循环需要遍历的次数上界.
	这儿 有一个需要注意的边界。如果循环是[0,n),那么j的上界是len - (i + 1)
	for (size_t i = 0; i < len; i++)
	{
		for (size_t j = 0; j < len - (i + 1); j++)
		{
			if (A[j] > A[j + 1])
			{
				swap(A[j], A[j + 1]);
			}
		}
	}

	或者
	for (size_t i = 1; i < len + 1; i++)
	{
		for (size_t j = 0; j < len - i; j++)
		{
			if (A[j] > A[j + 1])
			{
				swap(A[j], A[j + 1]);
			}
		}
	}
	*/
}