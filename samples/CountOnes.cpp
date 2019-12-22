
#include <iostream>
using namespace std;

int countOnes(unsigned int n)
{
	int ret = 0;

	while(n)	//数据仍然大于0
	{
		
		if(n & 1)	//如果二进制最后是1就计数
		{
			ret++;
		}
		n = (n >> 1);    //相当于减小二倍
		
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
