/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/
#include <iostream>
using namespace std;
#include <math.h>
//非负整数计算幂函数2^n
//O(n) = O(2^r)，r为输入指数n二进制位数，即比特位数
__int64 power1(int n)
{
	__int64 rnt = 1;//O(1)

	for (int i = 0; i  < n; i++ )//O(n)
	{

		rnt <<= 1; //rnt *= 2;倍增,//O(1)
		
	}

	return rnt;//O(1)
}
inline __int64 sqr(__int64 n)
{
	return n * n;
}
__int64 power2(int n)
{
	__int64 rnt = 1;
	if (0 == n)
	{
		return rnt;
	}

	if (n % 2 == 0)
	{
		rnt = sqr(power2(n >> 1));
	}
	else
	{
		rnt = sqr(power2(n >> 1)) * 2;
	}
	
	return rnt;
}


void main()
{
	int n = 10;
	std::cout << "10:" << power1(n) << endl;
	std::cout << "10:" << power2(n) << endl;;

}

