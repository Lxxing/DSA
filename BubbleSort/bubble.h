/******************************************************************************************
 * Data Structures in C++
 * Auther : luxiang
 * github:https://github.com/Lxxing?tab=repositories
 * 欢迎交流指正
 ******************************************************************************************/

inline void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
void bubblesort(int A[], int len);

template <typename T>
void bubblesort(T A[], unsigned int len)
{
    //这是先把小的数排到前面的方法。跟前面的方法相反
	//主要在于，第二个循环，如果是从后面开始遍历
	for (unsigned int i = 1; i <= len; i++)
	{
		for (unsigned int j = len; j > i; j++ )
		{
			if (A[j - 1] > A[j])
			{
				swap(A[j - 1], A[j]);
			}
		}
	}
}