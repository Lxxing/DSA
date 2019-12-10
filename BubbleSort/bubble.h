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

template <typename T>
void bubblesortA(T A[], unsigned int len)
{
	bool sorted = false; //整体排序标志位，false表示尚未排序
	while (!sorted) { //在尚未确认已全局排序之前，逐趟进行扫描交换
		sorted = true; //假定已经排序
		for (int i = 1; i < n; i++) { //自左向右逐对检查当前范围A[0, n)内的各相邻元素
			if (A[i - 1] > A[i]) { //一旦A[i - 1]与A[i]逆序，则交换
				swap(A[i - 1], A[i]); 
				sorted = false; //设置未排序标志位
			}
		}
		n--; //就位一个元素
	}
}