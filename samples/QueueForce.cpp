/******************************************************************************************
* Data Structures in C++
* Auther : luxiang
* github:https://github.com/Lxxing?tab=repositories
* ��ӭ����ָ��
******************************************************************************************/



#include <iostream>
#include <time.h> 
#include <vector>
using namespace std;

int nSolution; //�������
int nCheck; //��������

void DisplaySolution ( int* solu, int n ) 
{ //���n*n�Ŀ��в���
   printf ( "--\n" );
   for ( int i = 0; i < n; i++ ) 
   {
      for ( int j = 0; j < n; j++ )
      {
         printf ( ( j == solu[i] ) ? "��" : "[]" );
      }
      printf ( "\n" );
   }
   printf ( "--\n" );
}

//��ͻ��⣬�ж��Ƿ�����ڵ�ǰ�еĵ�k�з�����һ�ʺ�
//s[k]Ϊ��ǰ��k����ֵ��s[k]��֮ǰ�ķ��õĻʺ��Ƿ��ͻ
bool CollideCheck ( int* s, int k )
{ 
   nCheck++;
   for ( int i = 0; i < k; i++ ) 
   {
      if ( s[k] == s[i] )         return true; //��
      if ( s[k] - s[i] == k - i ) return true; //�Խ���
      if ( s[k] - s[i] == i - k ) return true; //���Խ���
   }
   return false;
}
//�����Ͻ�Ϊ���(0,0)
void Place4Queens_BruteForce()
{
	const int N = 4;//��const�������ܶ�������
	int solution[N];//��ֵ�����к�

	for (solution[0] = 0; solution[0] < N; solution[0]++)
	{
		for (solution[1] = 0; solution[1] < N; solution[1]++)
		{
			for (solution[2] = 0; solution[2] < N; solution[2]++)
			{
				for (solution[3] = 0; solution[3] < N; solution[3]++)
				{
					//���һ���У��жϷ��õ����ܷ������Ѿ�������Ϣ
					//�ڴ˴��Ѿ��γ�һ�������������ˡ���Ҫ�ж����е������Ƿ�ϸ�
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
//�жϺ���Ѿ����õĻʺ���Ҫ�ٴ��жϣ��ɼ�֦
void Place4Queens_Pruning()
{
	const int N = 4;//��const�������ܶ�������
	int solution[N];//��ֵ�����к�

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


