/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/
#include <iostream>
using namespace std;
#include <math.h>


//a^n算法：n >= 0
__int64 powerBF( __int64 a, int n )
{ 
   __int64 rnt = 1; 
   while ( 0 < n ) { //O(n)
      rnt *= a; 
      n--;
   }
   return rnt; 
}
//优化
__int64 power( __int64 a, int n ) 
{ 
   __int64 rnt = 1; 
   __int64 p = a; 
   while ( 0 < n )//O(logn)
   { 
      if ( n & 1 ) 
         rnt *= p; 
      n >>= 1;
      p *= p; 
   }
   return rnt;
} 


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
//优化迭代版
__int64 power1OP ( int n )
{ 
   __int64 rnt = 1;
   __int64 p = 2; //O(1)：累乘项初始化为2
   while ( 0 < n ) //O(logn)：迭代log(n)轮
   { 
      if ( n & 1 ) //如果是奇数
         rnt *= p; 
      n >>= 1; //指数减半
      p *= p;
   }
   return rnt;
} //O(logn) = O(r)，r为输入指数n的比特位数



//递归
__int64 power2Rec(int n)
{
	
	return n==0 ? 1 : power2Rec(n - 1) << 1;
}
//递归优化
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

	if (n % 2 == 0)//( n & 1 ) == 0
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
	std::cout << "10:" << powerBF(2,n) << endl;
	std::cout << "10:" << power(2,n) << endl;
	std::cout << "10:" << power1(n) << endl;
	std::cout << "10:" << power1OP(n) << endl;
	std::cout << "10:" << power2Rec(n) << endl;
	std::cout << "10:" << power2(n) << endl;
	

}

