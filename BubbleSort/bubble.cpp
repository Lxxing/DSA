/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* ��ӭ����ָ��
******************************************************************************************/

#include "bubble.h"

void bubblesort ( int A[], int len ) 
{ 
	//int legth = sizeof(A) / sizeof(a[1]);�����A�Ǹ�ָ�룬������Ϊ1
	for (size_t i = len; i > 0; i--)//�ȼ���while(len--).�����ĸ���
	{
		for (size_t j = 1; j < i; j++)//A[0,i),������������Ҷ˵ı߽�i����ʵҲ����ֱ�������ұߵı߽磬�������������Ӹ��Ӷ�
		{
			if (A[j - 1] > A[j])
			{
				swap(A[j - 1],A[j]);
			}
		}

	}
	/*
	���ҿ�ʼѧ��ʱ���������ͷ��ʼѭ�������ʱ��ڶ���ѭ�����ж��콾����
	j < len -i.��i��ʾ�����Ĵ�����Ҳ���Ѿ��źõĸ���������len -i ���ǵڶ���
	ѭ����Ҫ�����Ĵ����Ͻ�.
	��� ��һ����Ҫע��ı߽硣���ѭ����[0,n),��ôj���Ͻ���len - (i + 1)
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

	����
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