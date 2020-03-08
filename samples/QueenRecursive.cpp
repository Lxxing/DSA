/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* 欢迎交流指正
******************************************************************************************/



#include <iostream>
#include <time.h> 
#include <vector>
using namespace std;

int nSolution; //解的总数
int nCheck; //尝试总数

void DisplaySolution ( int* solu, int n ) 
{ //输出n*n的布局
   printf ( "--\n" );
   for ( int i = 0; i < n; i++ ) 
   {
      for ( int j = 0; j < n; j++ )
      {
         printf ( ( j == solu[i] ) ? "█" : "[]" );
      }
      printf ( "\n" );
   }
   printf ( "--\n" );
}

bool CollideCheck ( int* s, int k )
{ 
   nCheck++;
   for ( int i = 0; i < k; i++ ) 
   {
      if ( s[k] == s[i] )         return true; //列
      if ( s[k] - s[i] == k - i ) return true; //对角线
      if ( s[k] - s[i] == i - k ) return true; //反对角线
   }
   return false;
}

//放置第k个皇后(共n个)
const int N = 4;
void Place4Queens_Recursive(int n, int k)
{

	static int solution[N];

	//递归基，皇后已满
	if (n <= k)
	{
		nSolution++;
		DisplaySolution(solution, N);
		return;
	}
	
	for (int line = 0; line < N; line++)//遍历列
	{
		solution[k] = line;//各个列放置到当前行
		if (!CollideCheck(solution, k))
	    {//前面无冲突，则递归放置下一个
			Place4Queens_Recursive(n,k + 1);
		}
	}
}

void main()
{
	Place4Queens_Recursive(N,0);
    printf ( "Queens, %d Solution(s), %dCheck(s)\n\a\a", nSolution, nCheck );
}



