/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/

#include <iostream>
using namespace std;

namespace LXUtil
{
	void shuffle(int A[], int n) { //将A[0, n)随机打乱
		while (1 < n)
			swap(A[rand() % n], A[--n]);
	}

	void shuffle(int A[], int lo, int hi) //将A[lo, hi)随机打乱
	{
		shuffle(A + lo, hi - lo);
	}
	void print(int A[], int n, int lo, int hi) { //输出整数数组区间A[lo, hi)
		bool sorted = true;
		for (int i = 1; i < n; i++) if (A[i - 1] > A[i]) sorted = false;
		printf(sorted ? "S: " : " : ");
		for (int i = 0; i < lo; i++) printf("   .");
		for (int i = lo; i < hi; i++) printf("%4d", A[i]);
		for (int i = hi; i < n; i++) printf("   .");
		printf("\n");
	}

	void print(int A[], int n) { print(A, n, 0, n); }

	void randomArray(int A[], int n, int seed) 
	{
		srand(seed);
		for (int i = 0; i < n; i++) A[i] = i;
		shuffle(A, 0, n / 3);
		shuffle(A, 2 * n / 3, n);
	}
}

