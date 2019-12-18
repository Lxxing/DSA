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
	{//bugfix:�±��ȡֵ�����len -1
		for (unsigned int j = len - 1; j > i - 1; j-- )
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
		for (unsigned int i = 1; i < len; i++) { //����������Լ�鵱ǰ��ΧA[0, n)�ڵĸ�����Ԫ��
			if (A[i - 1] > A[i]) { //һ��A[i - 1]��A[i]�����򽻻�
				swap(A[i - 1], A[i]); 
				sorted = false; //����δ�����־λ
			}
		}
		len--; //��λһ��Ԫ��
	}
}