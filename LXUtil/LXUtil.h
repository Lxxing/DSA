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
	void shuffle(int A[], int n); //���������������A[0, n)
	void shuffle(int A[], int lo, int hi); //�������������������A[lo, hi)
	void print(int A[], int n); //�����������A[0, n)
	void print(int A[], int n, int lo, int hi); //���������������A[lo, hi)
	void randomArray(int A[], int n, int seed);
}

#endif //__X_LXUTIL__H_

