/******************************************************************************************
* RMQ4CPP 
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* ��ӭ����ָ�� xiaoxiaomiantianwo@163.com
******************************************************************************************/

#include <iostream>
using namespace std;
//����Ǹ������Ķ�����չ��λ��1�ĸ���
int countOnes(unsigned int n)
{
	int ret = 0;

	while(n)	//������Ȼ����0
	{
		
		if(n & 1)	//��������������1�ͼ���
		{
			ret++;
		}
		n = (n >> 1);    //�൱�ڼ�С����
		
	}

	return ret;

}


int main()
{

	//0x1000101011
	cout << "555:" << countOnes(555) << endl;
	//1010011010
	cout << "666:" << countOnes(555) << endl;

}
