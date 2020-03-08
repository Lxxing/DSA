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
{ //输出n*n的可行布局
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

//冲突检测，判断是否可以在当前行的第k列放置下一皇后
//s[k]为当前行k的列值，s[k]与之前的放置的皇后是否冲突
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
//从左上角为起点(0,0)
void Place4Queens_BruteForce()
{
	const int N = 4;//非const变量不能定义数组
	int solution[N];//数值代表列号

	for (solution[0] = 0; solution[0] < N; solution[0]++)
	{
		for (solution[1] = 0; solution[1] < N; solution[1]++)
		{
			for (solution[2] = 0; solution[2] < N; solution[2]++)
			{
				for (solution[3] = 0; solution[3] < N; solution[3]++)
				{
					//最后一个行，判断放置的列能否满足已经放置信息
					//在此处已经形成一个完整的序列了。需要判断所有的序列是否合格
					/*if (CollideCheck(solution, 0)) continue;
					if (CollideCheck(solution, 1)) continue;
					if (CollideCheck(solution, 2)) continue;
					if (CollideCheck(solution, 3)) continue;*/


					int line = 0;
					for (; line < N; line++)
					{
						if (CollideCheck(solution, line)) break;
					}
					if (line != N)
					{
						continue;
					}
					
					nSolution++;
					DisplaySolution(solution, N);
				}
			}
		}
	}
}
//判断后的已经放置的皇后不需要再次判断，可剪枝
void Place4Queens_Pruning()
{
	const int N = 4;//非const变量不能定义数组
	int solution[N];//数值代表列号

	for (solution[0] = 0; solution[0] < N; solution[0]++)
	{
		if (!CollideCheck(solution, 0))
		for (solution[1] = 0; solution[1] < N; solution[1]++)
		{
			if (!CollideCheck(solution, 1))
			for (solution[2] = 0; solution[2] < N; solution[2]++)
			{
			    if (!CollideCheck(solution, 2))
				for (solution[3] = 0; solution[3] < N; solution[3]++)
				{
					if (!CollideCheck(solution, 3))
					{
					    nSolution++;
					    DisplaySolution(solution, N);
					}
					
				}
			}
		}
	}
}

void main()
{
	Place4Queens_BruteForce();
    printf ( "Queens, %d Solution(s), %dCheck(s)\n\a\a", nSolution, nCheck );
	nSolution = 0;
	nCheck = 0;
	Place4Queens_Pruning();
	printf ( "Queens, %d Solution(s), %dCheck(s)\n\a\a", nSolution, nCheck );
}


