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

//众数计算
//思想有点像裁剪平行四边形，等比例裁剪
template <typename T>//选出众数候选
T majorityCandidata(vector<T> &A)
{
	int count = 0;//候选者与非候选者差值	
	T maj;//候选者
	for (int i = 0; i < A.size(); i++)
	{
		if (0 == count)
		{
			maj = A[i];//候选者更新，A-P
			count++;//差值计数，这一步很重要
		}
		else
		{
			A[i] == maj ? count++ : count--;//差值计数
		}
	}
	return maj;
}

template <typename T>
bool majorityCheck(vector<T> &A,int maj)
{
	int count = 0;
	for (int i = 0; i < A.size(); i++)
	{
		if (maj == A[i])
		{
			count++;
		}
	}

	return count << 1 > A.size() ? true : false;
}

template <typename T>
bool Majority(vector<T> &A,int & maj)
{
	maj = majorityCandidata(A);
	return majorityCheck(A, maj);
}


//中位数计算


void main()
{

	vector<int> A = {5,3,9,3,3,2,3,3};
	int maj;
	Majority(A,maj);
	cout << "Majority:" << maj << endl;
}

