/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* ��ӭ����ָ��
******************************************************************************************/

#pragma once

namespace LXUtil
{
	void shuffle(int A[], int n); //���������������A[0, n)
	void shuffle(int A[], int lo, int hi); //�������������������A[lo, hi)
	void print(int A[], int n); //�����������A[0, n)
	void print(int A[], int n, int lo, int hi); //���������������A[lo, hi)
	void randomArray(int A[], int n, int seed);
}
