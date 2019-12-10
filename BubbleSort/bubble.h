/******************************************************************************************
 * Data Structures in C++
 * Auther : luxiang
 * github:https://github.com/Lxxing?tab=repositories
 * ��ӭ����ָ��
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
    //�����Ȱ�С�����ŵ�ǰ��ķ�������ǰ��ķ����෴
	//��Ҫ���ڣ��ڶ���ѭ��������ǴӺ��濪ʼ����
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
	bool sorted = false; //���������־λ��false��ʾ��δ����
	while (!sorted) { //����δȷ����ȫ������֮ǰ�����˽���ɨ�轻��
		sorted = true; //�ٶ��Ѿ�����
		for (int i = 1; i < n; i++) { //����������Լ�鵱ǰ��ΧA[0, n)�ڵĸ�����Ԫ��
			if (A[i - 1] > A[i]) { //һ��A[i - 1]��A[i]�����򽻻�
				swap(A[i - 1], A[i]); 
				sorted = false; //����δ�����־λ
			}
		}
		n--; //��λһ��Ԫ��
	}
}