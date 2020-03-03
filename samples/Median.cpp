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

//中位数计算:将两个有序序列归并成一个有序的序列
template <typename T>//S1[len1,lo1+num1),S2[len2,lo2+num2)
T forceMedian(vector<T> S1,int lo1,int num1,
					vector<T> S2,int lo2,int num2)
{
	//归并成有序序列S
	vector<T> S;
	int hi1 = lo1 + num1;
	int hi2 = lo2 + num2;
	while ((lo1 < hi1) && (lo2 < hi2))
	{
		while (( lo1 < hi1 ) && (S1[lo1] <= S2[lo2]))
		{
			S.push_back(S1[lo1++]);
		}
		while ((lo2 < hi2) && (S2[lo2] <= S1[lo1]))
		{
			S.push_back(S2[lo2++]);
		}
	}
	
	while (lo1 < hi1)
	{
		S.push_back(S1[lo1]);
	}

	while (lo2 < hi2)
	{
		S.push_back(S2[lo2]);
	}

	return S[(num1 + num2) / 2];
}


void main()
{

	vector<int> S1 = {1,3,5,7,9};
	vector<int> S2 = {2,4,6,8,10};
	int median = forceMedian(S1,0,5,S2,0,5);
	cout << "median:" << median << endl;
}


