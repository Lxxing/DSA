/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/

#pragma once

namespace LXUtil
{
	void shuffle(int A[], int n); //随机置乱整数数组A[0, n)
	void shuffle(int A[], int lo, int hi); //随机置乱整数数组区间A[lo, hi)
	void print(int A[], int n); //输出整数数组A[0, n)
	void print(int A[], int n, int lo, int hi); //输出整数数组区间A[lo, hi)
	void randomArray(int A[], int n, int seed);
}
