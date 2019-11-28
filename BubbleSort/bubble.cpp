#include "bubble.h"

void bubblesort ( int A[], int len ) 
{ 
	for (size_t i = 0; i < len; i++)
	{
		for (size_t j = 1; j < len - i; j++)
		{
			if (A[i] > A[j])
			{
				swap(A[i],A[j]);
			}
		}

	}
}